#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
        int searchInsert(int A[], int n, int target) {	
		int i;
		for(i=0;i<n;){
			if(A[i]<target)
				i++;
			else{
				break;
			}
		}
		return i;
	}
};

int main(){
	int A[]={0};
	Solution s;
	int result = s.searchInsert(A,0,7);
	cout<<result;
}
