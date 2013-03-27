#include< stdio.h >
#include< string.h >

int main( int argv, char *args[] )
{
	system( strcat( strcat( "cl *.c /Fe", args ), ".exe" ) );
	printf( "%s\n", strcat( strcat( "cl *.c /Fe", args ), ".exe" ) );
	return 0;
}