#include <iostream>
#include <stdio.h>
#include <math.h>

void findPrimeFactors(int n)
{
	for (int i = n; i % 2 == 0; i = i / 2) {
		printf("%d", 2);
	}

	for (int i = 3; i <= sqrt(n); i = i + 2) {
		for (i = i; n % i == 0; n = n / i) {
			printf("%d", i);
		}
	}

	if (n > 2) {
		printf("%d ",n);
	}
		
}

int main()
{
	int n = 0;
	int testCases = 0;
	std::cin >> testCases;
	while (testCases--) {
		std::cout << "Enter a number: " << std::endl;
		std::cin >> n;
		findPrimeFactors(n);
	}
	
	return 0;
}