///////////////////////////////////////////////////////////////////////////////
//		Author:			Andrew Springer
//		SPOILER for Project Euler Problem 30
//		All work is original
//		Answer: 443839
#include <iostream>
#include <math.h>	// pow()
#include <string>
#include <vector>

using namespace std;

//////////////Function Prototypes//////////////////////////////////////////////
vector<int>		splitInt(int num);
void			printVInt(vector<int> v);
bool			check(int num);
int				powFive(vector<int> v);
///////////////////////////////////////////////////////////////////////////////


int main(){
	int max = (6 * ((int) pow(9, 5)) + 5000); // + 5000 just to be safe
	int sum = 0;

	for(int i = 2; i < max; i++){
		if(check(i)){
			sum = sum + i;
		}
	}
	
	cout << sum << endl;

	return 0;
}


bool check(int num){
	int temp = powFive(splitInt(num));
	
	if(temp == num){
		return true;
	} else {
		return false;
	}
}


int powFive(vector<int> v){
	int sum = 0;

	for(int i = 0; i < v.size(); i++){
		sum = sum + ( (int) pow(v[i], 5));
	}
	return sum;
}


vector<int> splitInt(int num){
	string str = to_string(num);
	vector<int> v;

	for(int i = 0; i < str.size(); i++){
		v.push_back( (int) str[i] - 48);
	}
	return v;	
}


void printVInt(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << ", ";
	}
	cout << endl;
}
