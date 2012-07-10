#include "factorial.h"


/** 
 * an iterative implementation of factorial
 *  that doesn't overwrite the passed parameter ;)
 */
long long int factorial(long long int n){
	long long int ret = 1,
		i = 0;

	for (i=1; i<=n; i++) {
		ret *= i;
	}
	return ret;
}


double spyral(double t) {
	double v = sqrt(1+t*t);
	return 0.5 * (t * v  + log(t+v));

}
