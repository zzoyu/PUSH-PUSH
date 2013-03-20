char g_map[13][20];

int g_count = 0;

char g_fileName[10];

void Draw( char _map[] );
void Move( int _x, int _y );
void MoveCursor( int _x, int _y );
void Popup();
void SaveScore( char _name[], int _score );
void LoadData( char _fileName[] );

void Draw( char _map[] )
{
	char m_level = 1;
	int i;
	int j;

	int m_x;
	int m_y;

	int m_boxCount=0;

	system( "cls" );

	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩ " );
	ColorChange( "R키 리셋", NULL, 15 );
	printf( " ▩ " );
	ColorChange( "COUNT : %03dMOVES", g_count, 15 );
	printf( "       ▩" );
	for( i=0; i<13; i++ )
	{
		for( j=0; j<20; j++ )
		{
			switch( g_map[i][j] )
			{
			case 'b':
				printf( "  " );
				break;
			case 'w':
				ColorChange( "▩", NULL, 8 );
				break;
			case 's':
				ColorChange( "■", NULL, 9 );
				break;
			case 'x':
				m_boxCount = m_boxCount + 1;
				ColorChange( "□", NULL, 6 );
				break;
			case 't':
				m_x = i;
				m_y = j;
				printf( "ㅱ", NULL, 11 );
				break;
			case 'i':
				printf( "▣", NULL, 11 );
				break;
			case 'p':
				m_x = i;
				m_y = j;
				ColorChange( "㈜", NULL, 15 );
				break;
			default:
				printf( "▩" );
			}
			//printf( "%c", g_map[i][j] );//디버그용
		}
		printf( "\n" );
		//printf( " i:%02d j:%02d\n", i,j );//디버그용, i와 j의 값을 확인하기 위해
	}
	if( m_boxCount != 0 )
	{
		printf("%d, %d", m_x, m_y );
		Move( m_x, m_y );
	}
	else
	{
		Popup();
	}
}

void GameStart( char _levelName[] )
{
	LoadData( _levelName );
	Draw( g_map );
}

void Move( int _x, int _y )
{
	int i = 0;	//행
	int j = 0;	//열

	char m_key = getch(); // 키를 입력받음 m_key 형태로

	switch( m_key )
	{
		case 72: //상
			g_count = g_count + 1;
			i = -1;
			j = 0;
			break;
		case 80: //하
			g_count = g_count + 1;
			i = 1;
			j = 0;
			break;
		case 75: //좌
			g_count = g_count + 1;
			i = 0;
			j = -1;
			break;
		case 77: //우
			g_count = g_count + 1;
			i = 0;
			j = 1;
			break;
		case 'r':
			LoadData( g_fileName );
			break;
		default:
			break;
	}
	switch( g_map[_x+i][_y+j] )
	{
	case 'b' :
		if( g_map[_x][_y] == 't' )
		{
			g_map[_x+i][_y+j] = 'p';
			g_map[_x][_y] = 'x';
		}
		else
		{
			g_map[_x+i][_y+j] = g_map[_x][_y];
			g_map[_x][_y] = 'b';
		}
		break;
	case 's':
		if( g_map[_x][_y] == 't' )
		{
			if( g_map[_x+2*i][_y+2*j] == 'x' )
			{
				g_map[_x+2*i][_y+2*j] = 'i';
				g_map[_x+i][_y+j] = 'p';
				g_map[_x][_y] = 'x';
			}
			else if( g_map[_x+2*i][_y+2*j] == 'b' )
			{
				g_map[_x+2*i][_y+2*j] = 's';
				g_map[_x+i][_y+j] = 'p';
				g_map[_x][_y] = 'x';
			}
		}
		switch( g_map[_x+2*i][_y+2*j] )
		{
			case 'b':
				g_map[_x+2*i][_y+2*j] = 's';
				g_map[_x+i][_y+j] = 'p';
				g_map[_x][_y] = 'b';
				break;
			case 'x':
				g_map[_x+2*i][_y+2*j] = 'i';
				g_map[_x+i][_y+j] = 'p';
				g_map[_x][_y] = 'b';
				printf("\a");
				break;
			default:
				break;

		}
		break;
	case 'x': //짐들어갈 빈칸
		if( g_map[_x][_y] == 't' )
		{
			g_map[_x+i][_y+j] = 't';
			g_map[_x][_y] = 'x';
		}
		else
		{
			g_map[_x+i][_y+j] = 't';
			g_map[_x][_y] = 'b';
		}
		break;
	case 'i': //짐들어있는칸
		if( g_map[_x+2*i][_y+2*j] == 'b' )
		{
			g_map[_x+2*i][_y+2*j] = 's';
			g_map[_x+i][_y+j] = 't';
			g_map[_x][_y] = 'b';
		}
		else if( g_map[_x+2*i][_y+2*j] == 'x' )
		{
			g_map[_x+2*i][_y+2*j] = 'i';
			g_map[_x+i][_y+j] = g_map[_x][_y];
			g_map[_x][_y] = 'x';
		}
		break;
		
	default:
		break;
	}
	Sleep(50);
	Draw( g_map );
}

void MoveCursor( int _x, int _y )
{
	COORD m_position = { _x-1, _y-1 };
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), m_position );
}

void Popup()
{	
	char r_name[10];
	system( "cls" );
	MoveCursor( 11, 5 );
	printf( "┏━━━━━━━━━┓\n" );
	MoveCursor( 11, 6 );
	printf( "┃ Congraturation ! ┃\n" );
	MoveCursor( 11, 7 );
	printf( "┗━━━━━━━━━┛\n" );

	MoveCursor( 0, 16 );
	getch();
	MainScreen();
}

void LoadData( char _fileName[] )
{
	FILE * m_fp;
	char m_map[13][20];

	int i = 0;

	m_fp = fopen( _fileName, "r" );

	while( !feof( m_fp ) )
	{
		fgets( g_map[i], 50, m_fp );
		i = i + 1;
	}
	fclose( m_fp );
}