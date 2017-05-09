#include	<stdio.h>
#include	<omp.h>
int	main() {
	const	int n=1000;
	int	total = 0;
#pragma omp parallel for
	for ( int i=0; i < n ; i++ ) {
	   #pragma omp critical
	   {
		total = total + i;
	   }
	}
	printf("Total = %d ( must be %d) \n", total, ((n-1)*n)/2);
}
