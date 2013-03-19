#include< stdio.h >
#include< windows.h >

void CursorMove( int _x, int _y );

int main()
{
	int i;
	char m_name[10];
	system( "cls" );
	for( i=0; i<800; i++ )
	{
		printf("十");
	}
	getch();
	CursorMove( 10, 5 );
	printf( "旨收收收收收收收收收旬\n" );
	CursorMove( 10, 6 );
	printf( "早   內六    內六   早\n" );
	CursorMove( 10, 7 );
	printf( "早 檜葷 :           早\n" );
	CursorMove( 10, 8 );
	printf( "曲收收收收收收收收收旭\n" );
	CursorMove( 20, 7 );
	
	scanf("%s",&m_name);

	getch();
	return 0;
}

void CursorMove( int _x, int _y )
{
	COORD m_position = { _x-1, _y-1 };
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), m_position );
}