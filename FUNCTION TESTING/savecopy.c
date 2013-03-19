#include< stdio.h >

int main()
{
	FILE *m_fp;
	int i = 1;
	char m_temp[10][10];

	char m_name[10] = "zzoyu";
	int m_score = rand()%100;

	m_fp = fopen( "userdata.dat", "w" );
	fclose( m_fp );

	m_fp = fopen( "userdata.dat", "r" );

	if( m_fp != NULL )
	{
		printf("m_fp에 값이 있다\n");
		while( !feof( m_fp ) )
		{
			printf("읽는다\n");
			fgets( m_temp[i-1], 10, m_fp );
			i = i + 1;
		}
	}
	fclose( m_fp );

	printf("닫아따\n");

	if( i < 10 )
	{
		printf("i가 10보다 작다\n");
		m_fp = fopen( "userdata.dat", "a" );
		fprintf( m_fp, "%s\n%d\n", m_name, m_score );
		printf("써따\n");
	}
	else
	{
		fclose( m_fp );
		printf("i가 10보다 크다\n");
		m_fp = fopen( "userdata.dat", "w" );

		fprintf( m_fp, "%s", m_temp );
	}
	fclose( m_fp );
	printf("끝\n");
}