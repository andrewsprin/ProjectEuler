///////////////////////////////////////////////////////////////////////////////
// Author:	Andrew Springer
// Disclaimer:
//	Spoilers for Project Euler Problem 23
//	Also, this solution is NOT elegant, but will work.
//	Answer: 4179871
#include <iostream>
#include <vector>

using namespace std;


////Function Prototypes///////////////////////////////////////////////////////
vector<int> getProperDivisors(int num);
void printIntVector(vector<int> v);
bool isAbundant(int i);
int sumOfIntVector(vector<int> v);
vector<int> getAllAbundantNums();
bool isSumOfAbundants(vector<int> abundantNums, int num);
//////////////////////////////////////////////////////////////////////////////


// Project Euler Problem 23
int main(){
	vector<int> abunNums = getAllAbundantNums();
	int sum = 0;

	for(int i = 1; i <= 28123; i++){
		cout << "Trying " << i << endl;
		if(!isSumOfAbundants(abunNums, i)){
			sum = sum + i;
		}
	}
	
	cout << sum << endl;
	

	//Testing for isSumOfAbundants()
	/*
	if(isSumOfAbundants(abunNums, 24) && !isSumOfAbundants(abunNums, 3)){
		cout << "It works!" << endl;
	} else {
		cout << "Well this is awkward..." << endl;
	}
	*/

	//Testing for isAbundant()
	/*
	if(isAbundant(12)){
		cout << "It works!" << endl;
	} else {
		cout << "Something is wrong" << endl;
	}
	*/
	
	//Testing for getProperDivsors() and printIntVector()
	/*
	for(int i = 0; i < 11; i++){
		cout << i << " has divisors ";
		printIntVector(getProperDivisors(i));
		cout << endl;
	}
	*/	
}


vector<int> getProperDivisors(int num){
	vector<int> divisors;

	//Do stuff to determine proper divisors
	for(int i = 1; i < num; i++){
		if((num % i) == 0){
			// Add i to divisors
			divisors.push_back(i);
		}
	}
	return divisors;
}

void printIntVector(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << ", " ;
	}
}

bool isAbundant(int i){
	if(i < sumOfIntVector(getProperDivisors(i))){
		return true;
	} else {
		return false;
	}
}


int sumOfIntVector(vector<int> v){
	int sum = 0;
	
	for(int i = 0; i < v.size(); i++){
		sum = sum + v[i];
	}
	
	return sum;
}


vector<int> getAllAbundantNums(){
	vector<int> abundants;

	for(int i = 0; i < 28123; i++){
		if(isAbundant(i)){
			abundants.push_back(i);
		}
	}
	return abundants;
}


bool isSumOfAbundants(vector<int> abundantNums, int num){
	// TODO Kinda bad design with these parameters... fix that
	int x = 0;
	int y = 0;

	for(int i = 0; i < abundantNums.size(); i++){
		x = abundantNums[i];
		for(int k = i; k < abundantNums.size(); k++){
			y = abundantNums[k];
			if((x + y) == num){
				return true;
			}
		}
		if(x > num){
			return false;

		}
	}
	
	return false;
}

