bool isPrime(int n){
	bool isprime = true;
	for(int i = 2; i < sqrt(n) + 1; ++i){
		if(n % i == 0){
			isprime = false;
		}
	}
	return isprime;
}