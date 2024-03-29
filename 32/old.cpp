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
vector<int>		getUniqueNums(vector<int> v);
vector<int>		getMultipliers(int num);
void			printVector(vector<int> v);
int				getSum(vector<int> v);
///////////////////////////////////////////////////////////////////////////////

int main(){
	vector<int> v;
	vector<int> sumMe;	

	//Upper limit = 9999
	for(int i = 2; i < 9999; i++){
		v = getMultipliers(i);
		cout << "Checking: " << i << endl;
		for(int x = 0; x < v.size(); x++){
			if(check(i, v[x], ((int) i/v[x]))){
				sumMe.push_back(i);
				cout << "Found: " << i << " ";
				cout << v[x] <<  " ";
				cout << ((int) i/v[x]) << endl;
			}
		}	
		v.clear();
	}

	//Get the sum and print it
	sumMe = getUniqueNums(sumMe);
	cout << getSum(sumMe) << endl;
}


vector<int> getFactors(int num){
	vector<int> v;

	for(int i = 2; i < num; i++){
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
	return v;
}


bool check(int a, int b, int c){
	//Returns true if the 3 params are pandigital 1 - 9
	vector<int> v = getDigits(a, b, c);
	bool	isOkay = true;
	int	numCount = 0;	

	for(int i = 1; i < 10; i++){
		numCount = 0;
		for( int x = 0; x < v.size(); x++){
			if(v[x] == i){
				numCount++;
			}	
		}
		if(numCount != 1){
			isOkay = false;
		}
	}
	for(int i = 0; i < v.size(); i++){
		if(v[i] < 1 || v[i] > 9){
			isOkay = false;
		}
	}
	
	return isOkay;
}


vector<int> getDigits(int a, int b, int c){
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


vector<int> getUniqueNums(vector<int> v){
	sort(v.begin(), v.end());
	unique(v.begin(), v.end());
	return v;
}


vector<int> getMultipliers(int num){
		vector<int> v = getFactors(num);
		int temp = 0;	

		//Now get rid of the multiplicands for each multiplier
		for(int i = 0; i < v.size(); i++){
			temp = (int) (num / v[i]);
			for(int x = 0; x < v.size(); x++){
				if(temp == v[x]){
					v.erase(v.begin() + x);
				}
			}
		}
		
		return v;
}


void printVector(vector<int> v){
	for(int i = 0; i < v.size(); i++){
			cout << v[i] << ", ";
	}
	cout << endl;
}


int getSum(vector<int> v){
	int sum = 0;
	
	for(int i = 0; i < v.size(); i++){
		sum = sum + v[i];
	}
	
	return sum;
}
