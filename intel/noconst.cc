#include	<stdio.h>

int main() {
	const int N=1<<28;
	double w = 0.5;
	double T = (double)N;
	double s = 0.0;
	
	for ( int i = 0 ; i < N ; i++ )
		s += w*(double)i/T;
	printf("%e\n", s);
}
