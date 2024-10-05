#include<iostream>
#include<vector>
#include<string>
using namespace std;
class StackOperations{
	public:
		vector<int>target;
		int n;
		//constructor to initialize target and n
		StackOperations(vector<int>targetArray,int num){
			target=targetArray;
			n=num;
		}
		//function to build the operatons
		vector<string>buildArray(){
			vector<string>operations;
			int current=1;//start from the first number in the stream
			for(int i=0;i<target.size();++i){
				while(current<target[i]){
					//if current number is less thantarget[i],we push and pop it
					operations.push_back("push");
					operations.push_back("pop");
					++current;
				}
				//now current is equal to the target[i],we push it onto the stack
				operations.push_back("push");
				++current;//move to the next number in the stream
			}
			return operations;
		}
};
//fuction to print operations
void printOperations(const vector<string>& operations){
	for(size_t i=0;i<operations.size();++i){
		cout<<operations[i]<<endl;//prints each operation on a new line
	}
}
int main(){
	//directly pass targetarray values to the constructor
	StackOperations stackOps({1,3},3);
	//get the operations to build the array
	vector<string>result=stackOps.buildArray();
	//call the fuction to build the array
	printOperations(result);
	//output the operations
	return 0;
}
	
