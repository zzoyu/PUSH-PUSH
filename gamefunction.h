char g_map[13][20] =
	{
		//f for Frame
		//b for Blank
		//w for Wall
		//x for boX
		//s for Stuff
		//p for Player
		//i for in
		"ffffffffffffffffffff",
		"fbbbbbbbbbbbbbbbbbbf",
		"fbbbbbbbbbbbbbbbbbbf",
		"fbbbbbbbwwwbbbbbbbbf",
		"fbbbbbbbwxwbbbbbbbbf",
		"fbbbbbbbwbwwwwbbbbbf",
		"fbbbbbwwwsbsxwbbbbbf",
		"fbbbbbwxspbwwwbbbbbf",
		"fbbbbbwwwwswbbbbbbbf",
		"fbbbbbbbbwxwbbbbbbbf",
		"fbbbbbbbbwwwbbbbbbbf",
		"fbbbbbbbbbbbbbbbbbbf",
		"ffffffffffffffffffff"
	};

int g_count = 0;

void Draw( char _map[] );
void Move( int _x, int _y );

void Draw( char _map[] )
{
	char m_level = 1;
	int i;
	int j;

	int m_x;
	int m_y;

	system( "cls" );

	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩ " );
	ColorChange( "LEVEL %02d", m_level, 15 );
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
				ColorChange( "□", NULL, 6 );
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
	Move( m_x, m_y );
}

void GameStart( char _levelName[] )
{
	Draw( g_map );
}

void Move( int _x, int _y )
{
	int i = 0;
	int j = 0;

	char m_key = getch();

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
		default:
			break;
	}
	switch( g_map[_x+i][_y+j] )
	{
	case 'b' : //상
		g_map[_x+i][_y+j] = g_map[_x][_y];
		g_map[_x][_y] = 'b';
		break;
	case 's':
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
	default:
		break;
	}
	Sleep(50);
	Draw( g_map );
}