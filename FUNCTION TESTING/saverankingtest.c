#include< stdio.h >
#include< stdlib.h >

int main()
{
	FILE *m_fp;
	char m_buf[31];
	char m_name[10];
	int m_score;
	char m_temp[11];
	int i = 1;

	printf( "파일 저장 기능을 테스트 하고 있습니다.\n" );
	printf( "Please enter your name. : " );
	scanf( "%s", m_name );
	printf( "Please enter your score. : " );
	scanf( "%d", &m_score );

	m_fp = fopen( "ranking.dat", "a" );

	fprintf( m_fp, "%s\n%d\n", m_name, m_score );

	fclose( m_fp );

	m_fp = fopen( "ranking.dat", "r" );

	while( !feof( m_fp ) )
	{
		fgets( m_buf, 10, m_fp );
		if( m_buf != '\n' )
		{
			if( i%2==1 )
			{
				printf( "이름 : %s", m_buf );
			}
			else
			{
				printf( "점수 : %d\n", atoi(m_buf) );
			}
			
		}
		i = i + 1;
	}
	fclose( m_fp );

	getch();
	return 0;
}