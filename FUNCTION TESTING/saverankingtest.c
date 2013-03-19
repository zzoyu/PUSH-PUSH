#include< stdio.h >

int main()
{
	FILE *m_fp;
	char m_name[10];
	int m_score;

	printf( "파일 저장 기능을 테스트 하고 있습니다.\n" );
	printf( "Please enter your name. : " );
	scanf( "%s", m_name );
	printf( "Please enter your score. : " );
	scanf( "%d", &m_score );

	m_fp = fopen( "ranking.dat", "a" );

	fprintf( m_fp, "%s=%d\n", m_name, m_score );
	fclose( m_fp );

	return 0;
}