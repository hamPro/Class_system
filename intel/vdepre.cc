void mycopy(int n, float* RESTRICT a, float* RESTRICT b) {
	for ( int i=0; i<n; i++ ) 
		a[i]=b[i];
}
