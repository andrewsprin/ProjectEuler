///////////////////////////////////////////////////////////////////////////////
//	Author:		Andrew Springer
//	Disclaimer:
//		Spoilers for Project Euler Problem 24
//
//	All work here is original
// 	Answer: 2783915460

#include <iostream>
#include <vector>

using namespace std;

/////////Function Prototypes///////////////////////////////////////////////////
void		perm(vector<int> nums);
void		printIntVector(vector<int> v);
///////////////////////////////////////////////////////////////////////////////

/////////Global Variables//////////////////////////////////////////////////////
int count = 0;
///////////////////////////////////////////////////////////////////////////////


int main(){
	vector<int> empty;

	perm(empty);
	
	return 0;
}

void perm(vector<int> nums){
	int top = 10;
	bool unique = true;
	int pos = nums.size();
	vector<int> copy = nums;
	int target = 1000000;

	nums.push_back(-1); //Make the new position
	for(int i = 0; i < top; i++){
		for(int x = 0; x < nums.size(); x++){
			if(i == nums[x]){
				unique = false;
			}
		}
		if(unique){
			if(nums.size() < top){
				//Then do a recursive call
				nums[pos] = i;
				perm(nums);
			} else {
				count++;
				if(count == target){
					printIntVector(copy);
					cout << i << endl;
				}
			}
		}	
		unique = true;
	}
}


void printIntVector(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}	
}













