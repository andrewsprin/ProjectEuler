///////////////////////////////////////////////////////////////////////////////
//			Author:		Andrew Springer
//			SPOILERS for Project Euler Problem 32
//			All work is original
//			Answer:		
#include <iostream>
#include <vector>
#include <string>

using namespace std;

///////////Function Prototypes/////////////////////////////////////////////////
vector<int>		getFactors(int num);
vector<int>		getContainingDigits(int num);
bool			check(int a, int b, int c);
vector<int>		getDigits(int a, int b, int c);
///////////////////////////////////////////////////////////////////////////////

int main(){
	
}


vector<int> getFactors(int num){
	vector<int> v;

	for(int i = 1; i < num; i++){
		if((num % i) == 0){
			//Then the number is a factor
			v.push_back(i);
		}
	}
	
	return v;
}


vector<int> getContainingDigits(int num){
	//convert the number into a string
	//convert the string into a vector<int>
	string str = to_string(num);
	vector<int> v;	

	for(int i = 0; i < str.size(); i++){
			v.push_back((int) str[i] - 48);
	}	
}


bool check(int a, int b, int c){
	//Returns true if the 3 params are pandigital 1 - 9
}


vector<int>	getDigits(int a, int b, int c){
	vector<int> v;
	vector<int> result;	

	v = getContainingDigits(a);
	for(int i = 0; i < v.size(); i++){
		result.push_back(v[i]);
	}
	
	v = getContainingDigits(b);
	for(int i = 0; i < v.size(); i++){
		result.push_back(v[i]);
	}

	v = getContainingDigits(c);
	for(int i = 0; i < v.size(); i++){
		result.push_back(v[i]);
	}

	return result;
}
