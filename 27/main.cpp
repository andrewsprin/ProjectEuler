//////////////////////////////////////////////////////////////////////////////
//	Author: 		Andrew Springer
//	Project Euler Problem 27
//	Disclaimer:
//		Contains spoilers for Project Euler Problem 27
//		Answer: -59231
#include <iostream>
#include <stdlib.h>		// abs()

using namespace std;

/////////Function Prototypes//////////////////////////////////////////////////
bool	isPrime(int num);
int		getNumberOfPrimesProduced(int a, int b);
//////////////////////////////////////////////////////////////////////////////

int main(){	
	int a = 0;
	int b = 0;
	int primes = 0;
	int tempCount = 0;

	for(int x = -1000; x < 1000; x++){
		// X is values of a
		for(int y = -1000; y < 1000; y++){
			cout << "Testing a:" << x << " b:" << y << endl;
			tempCount = getNumberOfPrimesProduced(x, y);
			//Test to see if this is the largest count so far
			if(tempCount > primes){
				//Set a to x and b to y
				primes = tempCount;
				a = x;
				b = y;
			}
		}
	}

	//Begin some testing of getNumerOfPrimesProduced
	/*
	cout << "Testing 41" << endl;
	cout << getNumberOfPrimesProduced(1, 41) << endl;
	// Expect 40
	cout << "Testing -79, 1601" << endl;
	cout << getNumberOfPrimesProduced( -79, 1601) << endl;
	// Expect 80
	*/
	//End testing

	//Then find the products of a and b
	cout << "Coefficients a:" << a << " b:" << b << endl;
	cout << "Product of coefficients: " << (a * b) << endl;
	return 0;
}


bool isPrime(int num){
	bool answer = true;	
	
	if (num < 0){
		answer = false;
		return answer;
	}
	
	for (int i = 2; i < num; i++){
		if((num % i) == 0){
			answer = false;
			return answer;
		}
	}
	return answer;
}


int getNumberOfPrimesProduced(int a, int b){
	bool	isConsecutive = true;
	int		currentNum;
	int		n = 0;
	int		primeCount = 0;

	while(isConsecutive){
		currentNum = (n * n) + (n * a) + b;
		if(isPrime(currentNum)){
			n++;
			primeCount++;
			//cout << currentNum << " is prime" << endl;
		} else {
			//cout << currentNum << " is NOT a prime" << endl;
			isConsecutive = false;
		}
	}
	return primeCount;
}

