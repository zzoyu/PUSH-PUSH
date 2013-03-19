#include< stdio.h >

char g_map[14][20];

int main()
{
	int i = 1;

	FILE *m_fp;
	m_fp = fopen( "level1.dat", "r" );
	if( m_fp != NULL )
	{
		while( !feof( m_fp ) )
		{
			fgets( g_map[i-1], 21, m_fp );
			printf( g_map[i-1] );
			i = i + 1;
		}
	}
	fclose( m_fp );
}