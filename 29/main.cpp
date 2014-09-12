///////////////////////////////////////////////////////////////////////////////
//		Author:		Andrew Springer
//		Disclaimer:
//			Spoilers for Project Euler Problem 29
//			All work here is original
//			Answer: 
#include <iostream>
#include <vector>
#include <math.h>	// for pow()

using namespace std;


/////////////Function Prototypes///////////////////////////////////////////////
double	calcNum(int a, int b);
bool	isUnique(vector<double> v, double num);
int		testCalcNum();
int		testIsUnique();
void	runTests();
///////////////////////////////////////////////////////////////////////////////

int main(){
	vector<double> results;
	double current;
	runTests();	
	
	for(int a = 2; a <= 100; a++){
		for(int b = 2; b <= 100;  b++){
			current = calcNum(a, b);
			if(isUnique(results, current)){
				results.push_back(current);
			}
		}
	}

	cout << "Answer: " << results.size() << endl;
	return 0;
}

double calcNum(int a, int b){
	double answer = pow(a, b);
	// cout << a << "^" << b << " = " << answer << endl;
	return answer;
}


bool isUnique(vector<double> v, double num){
	for(int i = 0; i < v.size(); i++){
		if(num == v[i]){
			// cout << num << " matches " << v[i] << endl;
			return false;
		}
	}
	return true;
}


///////////////////////////////////////////////////////////////////////////////
//	Function Testing
///////////////////////////////////////////////////////////////////////////////

int	testCalcNum(){
	double res1 = 256; // 4^4
	double res2 = 125; // 5^3
	
	//Test for positive
	if(res1 != calcNum(4, 4)){
		return 1;	
	}
	if(res2 != calcNum(5, 3)){
		return 1;
	}
	return 0; // Everything is okay
}

int testIsUnique(){
	vector<double> v1;
	vector<double> v2;
	double num1 = 2;
	double num2 = 100;	

	for(double i = 0; i < 6; i++){
		v1.push_back(i);
		v2.push_back(i);
	}

	//Test for positive
	if(isUnique(v1, num1)){
		return 1;
	}

	//Test for negative
	if(!isUnique(v2, num2)){
		return 1;
	}

	return 0; // Everything is okay
}

void runTests(){
	bool isOkay = true;
	
	if(testCalcNum() != 0){
		isOkay = false;
		cout << "calcNum() is broken" << endl;
	}
	
	if(testIsUnique() != 0){
		isOkay = false;
		cout << "isUnique() is broken" << endl;
	}
	
	if(!isOkay){
		cout << "One of the tests went bad!" << endl;
	}
}
