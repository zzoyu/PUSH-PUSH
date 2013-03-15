const char MAP_LEVEL1[12][17] =
	{
		"22222222222222222",
		"21111111111111112",
		"21111222111111112",
		"21111242111111112",
		"21111212222111112",
		"21122231342111112",
		"21124301222111112",
		"21122223211111112",
		"21111124211111112",
		"21111122211111112",
		"21111111111111112",
		"22222222222222222"
	};


void Draw( char _map[] );

void Draw( char _map[] )
{
	int i;
	int j;
	//char m_map[] = _map;

	//char m_map[] = _map;

	system( "cls" );

	for( i=0; i<12; i++ )
	{
		for( j=0; j<17; j++ )
		{
			switch( MAP_LEVEL1[i][j] )
			{
			case '1':
				printf( "  " );
				break;
			case '2':
				printf( "▩" );
				break;
			case '3':
				printf( "■" );
				break;
			case '4':
				printf( "□" );
				break;
			case '5':
				printf( "▣" );
				break;
			case '0':
				printf( "㈜" );
				break;
			default:
				printf( "!!!WARNING!!! BUG!!!\a" );
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