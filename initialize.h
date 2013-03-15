void Initialize();
void MainScreen();
void SelectLevel();
void GameStart( char _levelName[] );
void Ranking();
void Credit();
void ColorChange( char _string[], char _variable, int _color );

void Initialize()
{
	SetConsoleTitle( "::PUSH PUSH:: by KSY CYJ" );
	system( "mode con lines=16 cols=41" );
	system( "color 0E" );
	system( "cls" );
}

//함수 오버로딩이 불가능하여 주석처리
/*void ColorChange( char _string[] )
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 15 );
	printf( _string );
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 14 );
}*/
void ColorChange( char _string[], char _variable[], int _color )
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), _color );
	printf( _string, _variable );
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 14 );
}
void MainScreen()
{
	char m_select = -1;

	system( "cls" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩        ");
	ColorChange( "P U S H      P U S H", NULL, 15 );
	printf( "        ▩\n" );
	printf( "▩             By KSY CYJ             ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩  " );
	ColorChange( "▶ [ S ] 게임 시작", NULL, 15 );
	printf( "                ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩  " );
	ColorChange( "▶ [ R ] 랭킹", NULL, 15 );
	printf( "                     ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩  ");
	ColorChange( "▶ [ C ] 크레딧", NULL, 15 );
	printf( "                   ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );

	while( !(( m_select=='s' )||( m_select=='r' )||( m_select=='c' ) ) )
	{
		m_select = getch();
		switch( m_select )
		{
			case 's':
				//printf( "\a" );
				SelectLevel();
				break;
			case 'r':
				//printf( "\a" );
				Ranking();
				break;
			case 'c':
				//printf( "\a" );
				Credit();
				break;
			default:
				break;
		}	
	}
};

void SelectLevel()
{
	char m_select = -1;

	system( "cls" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩        ");
	ColorChange( "P U S H      P U S H", NULL, 15 );
	printf( "        ▩\n" );
	printf( "▩             By KSY CYJ             ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩           " );
	ColorChange( "♧ 레벨선택 ♧", NULL, 15 );
	printf( "           ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩  ");
	ColorChange( "▶ [ 1 ] Level 1", NULL, 15 );
	printf("                  ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩          돌아가려면 [R]키          ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );

	while( !(( m_select=='1' )||( m_select=='r' )) )
	{
		m_select = getch();
		switch( m_select )
		{
			case '1':
				//printf( "\a" );
				GameStart( "level1.dat" );
				break;
			case 'r':
				//printf( "\a" );
				MainScreen();
				break;
			default:
				break;
		}	
	}
};

void Ranking()
{
	char m_select = -1;
	char test[10]="조유진";
	char test2[10]="김성엽";

	system( "cls" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩        ");
	ColorChange( "P U S H      P U S H", NULL, 15 );
	printf( "        ▩\n" );
	printf( "▩             By KSY CYJ             ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩            ");
	ColorChange( "♧ 랭킹 ♧", NULL, 15 );
	printf("              ▩\n" );
	printf( "▩  " );
	ColorChange( "①위 %3s", test, 15 );
	printf("                       ▩\n" );
	printf( "▩  " );
	ColorChange( "②위 %3s", test, 15 );
	printf("                       ▩\n" );
	printf( "▩  " );
	ColorChange( "③위 %3s", test, 15 );
	printf("                       ▩\n" );
	printf( "▩  " );
	ColorChange( "④위 %3s", test, 15 );
	printf("                       ▩\n" );
	printf( "▩  " );
	ColorChange( "ⓩ[꼴지] %3s", test2, 15 );
	printf("                   ▩\n" );
	printf( "▩          돌아가려면 [R]키          ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );

	while( !( m_select=='r' ) )
	{
		m_select = getch();
		if( m_select == 'r' )
		{
			//printf( "\a" );
			MainScreen();
		}
	}
};

void Credit()
{
	char m_select = -1;

	system( "cls" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩        ");
	ColorChange( "P U S H      P U S H", NULL, 15 );
	printf( "        ▩\n" );
	printf( "▩             By KSY CYJ             ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩            ♧ 크레딧 ♧            ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩           이런거 한번쯤            ▩\n" );
	printf( "▩         해보고 싶었습니다.         ▩\n" );
	printf( "▩               배고파               ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩          돌아가려면 [R]키          ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );

	while( !( m_select=='r' ) )
	{
		m_select = getch();
		if( m_select == 'r' )
		{
			//printf( "\a" );
			MainScreen();
		}
	}
}
