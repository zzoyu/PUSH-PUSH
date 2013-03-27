#include< stdio.h >
#include< conio.h >
#include< windows.h >

#include "gamefunction.h"

extern char g_fileName[];

char g_map[13][20];
int g_count = 0;

void Draw()
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
	ColorChange( "COUNT : %03dMOVES", (char *)g_count, 15 );
	printf( "       ▩" );
	for( i=0; i<13; i++ )
	{
		for( j=0; j<20; j++ )
		{
			switch( g_map[i][j] )
			{
			case ' ':
				printf( "  " );
				break;
			case '#':
				ColorChange( "▩", NULL, 8 );
				break;
			case '$':
				ColorChange( "■", NULL, 9 );
				break;
			case '.':
				m_boxCount = m_boxCount + 1;
				ColorChange( "□", NULL, 6 );
				break;
			case '+':
				m_x = i;
				m_y = j;
				m_boxCount = m_boxCount + 1;
				printf( "ㅱ", NULL, 11 );
				break;
			case '*':
				printf( "▣", NULL, 11 );
				break;
			case '@':
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
		Popup( "Congratulations!" );
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
		case 27:
			g_count = 0;
			MainScreen();
		default:
			break;
	}
	switch( g_map[_x+i][_y+j] )
	{
	case ' ' :
		if( g_map[_x][_y] == '+' )
		{
			g_map[_x+i][_y+j] = '@';
			g_map[_x][_y] = '.';
		}
		else
		{
			g_map[_x+i][_y+j] = g_map[_x][_y];
			g_map[_x][_y] = ' ';
		}
		break;
	case '$':
		if( g_map[_x][_y] == '+' )
		{
			if( g_map[_x+2*i][_y+2*j] == '.' )
			{
				g_map[_x+2*i][_y+2*j] = '*';
				g_map[_x+i][_y+j] = '@';
				g_map[_x][_y] = '.';
			}
			else if( g_map[_x+2*i][_y+2*j] == ' ' )
			{
				g_map[_x+2*i][_y+2*j] = '$';
				g_map[_x+i][_y+j] = '@';
				g_map[_x][_y] = '.';
			}
		}
		switch( g_map[_x+2*i][_y+2*j] )
		{
			case ' ':
				g_map[_x+2*i][_y+2*j] = '$';
				g_map[_x+i][_y+j] = '@';
				g_map[_x][_y] = ' ';
				break;
			case '.':
				g_map[_x+2*i][_y+2*j] = '*';
				g_map[_x+i][_y+j] = '@';
				g_map[_x][_y] = ' ';
				printf("\a");
				break;
			default:
				break;

		}
		break;
	case '.': //짐들어갈 빈칸
		if( g_map[_x][_y] == '+' )
		{
			g_map[_x+i][_y+j] = '+';
			g_map[_x][_y] = '.';
		}
		else
		{
			g_map[_x+i][_y+j] = '+';
			g_map[_x][_y] = ' ';
		}
		break;
	case '*': //짐들어있는칸
		if( g_map[_x+2*i][_y+2*j] == ' ' )
		{
			g_map[_x+2*i][_y+2*j] = '$';
			g_map[_x+i][_y+j] = '+';
			g_map[_x][_y] = ' ';
		}
		else if( g_map[_x+2*i][_y+2*j] == '.' )
		{
			printf("\a");
			g_map[_x+2*i][_y+2*j] = '*';
			g_map[_x+i][_y+j] = g_map[_x][_y];
			g_map[_x][_y] = '.';
		}
		break;
		
	default:
		break;
	}
	Sleep(50);
	Draw();
}

void MoveCursor( int _x, int _y )
{
	COORD m_position = { _x-1, _y-1 };
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), m_position );
}

void Popup( char _message[] )
{	
	char r_name[10];
	//system( "cls" );
	MoveCursor( 10, 7 );
	printf( "┏━━━━━━━━━┓\n" );
	MoveCursor( 10, 8 );
	printf( "┃ ");
	printf( _message );
	printf( " ┃\n" );
	MoveCursor( 10, 9 );
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

	g_count = 0;

	m_fp = fopen( _fileName, "r" );

	if( m_fp == NULL )
	{
		Popup( "Can't Open File!" );
	}
	while( !feof( m_fp ) )
	{
		fgets( g_map[i], 50, m_fp );
		i = i + 1;
	}
	fclose( m_fp );
}