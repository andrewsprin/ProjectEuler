//		Author:		Andrew Springer
//		SPOILERS for Project Euler Problem 32
//		
#include <iostream>
#include <vector>

using namespace std;

//	Function Prototypes
vector<int>		getFactors(int num);
void			printVector(vector<int> v);
vector<int>		getMultiplicands(int num);

int main(){
	
	//Print the factors of 20 without multipliers
	//printVector(getMultiplicands(20));
	cout << "Factors of 20: " << endl;
	printVector(getFactors(20));

	//Print the factors of 100 without multipliers
	//printVector(getMultiplicands(100));
	//printVector(getFactors(100));

	return 0;
}


vector<int> getFactors(int num){
	vector<int> v;
	for(int i = 0; i < num; i++){
		if((num % i) == 0){
			v.push_back(i);
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


vector<int> getMultiplicands(int num){
	vector<int> v = getFactors(num);
	int temp = 0;

	//Get rid of the multipliers 
	for(int x = 0; x < v.size(); x++){
		temp = ((int) num/v[x]);
		for(int y = 0; y < v.size(); y++){
			if(v[y] == temp){
				v.erase(v.begin() + y);
			}
		}
	}
	return v;
}
