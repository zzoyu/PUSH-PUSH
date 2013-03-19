#include< stdio.h >

int main()
{
	FILE *m_fp;
	int i = 1;
	char m_temp[10][10];

	char m_name[10] = "zzoyu";
	int m_score = rand()%100;

	m_fp = fopen( "userdata.dat", "a" );
	fprintf( m_fp, "%s\n%d\n", m_name, m_score );
	printf("½áµû\n");

	fclose( m_fp );
	printf("³¡\n");
}