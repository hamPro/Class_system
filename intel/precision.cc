#include	<stdio.h>
#include	<math.h>

int main() {
	const int N = 1000000;
	const int P = 10;
	double A[N];
	const double startValue = 1.0;
	A[:] = startValue;
	for (int i = 0 ; i < P ; i++) 
#pragma simd
	   for ( int r = 0; r < N; r++ )
		A[r] = exp(-A[r]);

	printf("Result = %.17e\n",A[0]);
}
