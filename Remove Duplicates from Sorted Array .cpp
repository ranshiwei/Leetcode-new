#include <iostream>
using namespace std;
 
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int i=0,j=1;
        bool flag=false;
        while(j<n){
            if(A[i]!=A[j]){
            	if(flag){
            		A[++i]=A[j++];
            	}
            	else{
            		A[++i] = A[j++];
            	}
                
            }else{
            	j++;
                flag=true;
            }
        }
        return i+1;
    }
};

int main(){
	int A[]={1,1,2,3};
	Solution s;
	int len = s.removeDuplicates(A,4);
	for(int i=0;i<len;i++)
		cout<<A[i]<<endl;
	cout<<len<<endl;
	
}


