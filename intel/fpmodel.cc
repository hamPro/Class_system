#include	<stdio.h>
#include	<math.h>

int main() {
	for (int i = 0 ; i < 100 ; i++) {
	   const int N=i*5000;
	   double A = 0.1;
	   for ( int r = 0; r < N; r++ )
		A = sqrt(1.0-4.0*(A-0.5)*(A-0.5));
	   if ( i < 10) printf("After %5d iterations, A=%e\n", N, A);
	}
}
