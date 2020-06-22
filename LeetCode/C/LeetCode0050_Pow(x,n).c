double myPow(double x, int n) {
	if ( n > 0 ) {
		if ( n == 1 )
			return x;
		else {
			double result = myPow( x, n / 2 );
			if ( n % 2 )
				return ( result * result * x );
			else
				return ( result * result );
		}
	} else if ( n < 0 ) {
		if ( n == -1 )
			return ( 1 / x );
		else {
			double result = myPow( x, n / 2 );
			if ( n % 2 )
				return ( result * result * ( 1 / x ) );
			else
				return ( result * result );
		}

	} else
		return 1.0;
}
