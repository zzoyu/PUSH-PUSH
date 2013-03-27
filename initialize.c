#include< stdio.h >
#include< conio.h >
#include< windows.h >
#include< string.h >

#include "initialize.h"

char g_fileName[] = "level";

void Initialize()
{
	SetConsoleTitle( "::PUSH PUSH:: by KSY CYJ" );
	system( "mode con lines=16 cols=41" );
	system( "color 0E" );
	system( "cls" );
}

void ColorChange( char _string[], char _variable[], int _color )
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), _color );
	printf( _string, _variable );
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 14 );
}
int MainScreen()
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
	ColorChange( "▶ [ H ] 게임 설명", NULL, 15 );
	printf( "                ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩  ");
	ColorChange( "▶ [ C ] 크레딧", NULL, 15 );
	printf( "                   ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );

	while( !(( m_select=='s' )||( m_select=='c' )||( m_select=='h' )||( m_select==27 ) ) )
	{
		m_select = getch();
		switch( m_select )
		{
			case 's':
				//printf( "\a" );
				SelectLevel();
				break;
			case 'c':
				//printf( "\a" );
				Credit();
				break;
			case 'h':
				Help();
				break;
			case 27:
				return 0;
				break;
			default:
				break;
		}	
	}
	return 0;
};

void SelectLevel()
{
	char m_select = -1;
	char m_temp[] = "";

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
	ColorChange( "▶ [ 1 ] 레벨 번호로 입력", NULL, 15 );
	printf("         ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩  ");
	ColorChange( "▶ [ 2 ] 직접 파일 입력", NULL, 15 );
	printf("           ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩          돌아가려면 [R]키          ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n" );

	while( !(( m_select=='1' )||( m_select=='2' )||( m_select=='r' )) )
	{
		m_select = getch();
		MoveCursor( 6, 9 );
		printf("                        \n");
		MoveCursor( 6, 11 );
		printf("                        \n");
		MoveCursor( 6, 9 );
		switch( m_select )
		{
			case '1':
				//printf( "\a" );
				ColorChange( "레벨을 선택해 주세요.(0-9)\n", NULL, 15 );
				MoveCursor( 6, 10 );
				
				scanf( "%s", &m_temp );

				if( m_temp[0] == 'r' )
				{
					m_select = -1;
					SelectLevel();
				}
				else
				{
					sprintf( g_fileName, "%s%s%s", "level", m_temp, ".dat" );
					printf( g_fileName );
					GameStart( g_fileName );
				}
				break;
			case '2':
				//printf( "\a" );
				ColorChange( "파일명을 입력해 주세요.\n", NULL, 15 );
				MoveCursor( 6, 10 );
				scanf( "%s", g_fileName );
				if( g_fileName[0] == 'r' )
				{
					m_select = -1;
					SelectLevel();
				}
				else
				{
					printf( "%s", g_fileName );
					GameStart( g_fileName );
				}
				break;
			case 'r':
				MainScreen();
				break;
			default:
				break;
		}	
	}
};
void Help()
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
	printf( "▩            ♧ 도움말 ♧            ▩\n" );
	printf( "▩                                    ▩\n" );
	printf( "▩     캐릭터 이동 : 방향키           ▩\n" );
	printf( "▩            리셋 : R                ▩\n" );
	printf( "▩       게임 중단 : ESC              ▩\n" );
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
