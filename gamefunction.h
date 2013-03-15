const char MAP_LEVEL1[13][20] =
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


void Draw( char _map[] );

void Draw( char _map[] )
{
	char m_level = 1;
	char m_count = 0;
	int i;
	int j;
	//char m_map[] = _map;

	//char m_map[] = _map;

	system( "cls" );

	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩ " );
	ColorChange( "LEVEL %02d", m_level, 15 );
	printf( " ▩ " );
	ColorChange( "COUNT : %03dMOVES", m_count, 15 );
	printf( "       ▩" );
	for( i=0; i<13; i++ )
	{
		for( j=0; j<20; j++ )
		{
			switch( MAP_LEVEL1[i][j] )
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
				ColorChange( "㈜", NULL, 15 );
				break;
			default:
				printf( "▩" );
			}
			//printf( "%c", MAP_LEVEL1[i][j] );//디버그용
		}
		printf( "\n" );
		//printf( " i:%02d j:%02d\n", i,j );//디버그용, i와 j의 값을 확인하기 위해
	}
	getch();
}

void GameStart( char _levelName[] )
{
	Draw( MAP_LEVEL1 );
}