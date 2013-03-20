#include< stdio.h >

void LoadData( char _fileName[] );
int main()
{
	LoadData( "level1.dat" );
	return 0;
}
void LoadData( char _fileName[] )
{
	FILE * m_fp;
	char m_map[13][20];

	int i = 0;
	m_fp = fopen( _fileName, "r" );

	while( !feof( m_fp ) )
	{
		fgets( m_map[i], 50, m_fp );
		printf( m_map[i] );
		i = i + 1;
	}
}