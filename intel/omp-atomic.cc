#include	<stdio.h>
#include	<omp.h>
int	main() {
	const	int n=1000;
	int	total = 0;
#pragma omp parallel 
   {
	int	total_th = 0;
#pragma omp for
	for ( int i=0; i < n ; i++ ) {
	   total_th = total_th +i;
	}
#pragma omp atomic
	total += total_th;
   }
   printf("Total = %d ( must be %d) \n", total, ((n-1)*n)/2);
}

