#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=0) return 0;
        int i=0,j=0;
        int curnum=A[0];
        int count=0;
        for(;j<n;j++){
            if(A[j]==curnum){
                count++;
                if(count>2){
                    continue;
                }else{
                	A[i++]=A[j];
                }
            }
            else{
                count=1;
                curnum=A[j];
                A[i++]=A[j];
            }
        }
        return i;
    }
};
int main(){
	Solution s;
	int t[]={1,1,1,1,3,3};
	int result=s.removeDuplicates(t,sizeof(t)/sizeof(int));
	cout<<result<<endl;;
	for(int i=0;i<result;i++)
		cout<<t[i]<<endl;
}
