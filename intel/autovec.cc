#include	<stdio.h>
int main() {
	const	int	n=8;
	int	i;

	__declspec(align(64))	int A[n];
	__declspec(align(64))	int B[n];

	// Initialization
	for ( i=0; i<n; i++) A[i]=B[i]=i;

	// This loop will be auth-vectorized
	for ( i=0; i<n; i++) A[i]+=B[i];

	// Output
	for ( i=0; i<n; i++) printf("%2d  %2d  %2d\n", i, A[i], B[i]);
}
