#include "header.h"
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int count=0;
        bool flag=false;
        while(true){
            flag=false;
            for(int i=0;i<n;i++){
                if(A[i]>0){
                    if(A[i]==1)
                        flag=true;
                    A[i]-=1;
                }
            }
            count++;
            if(!flag) break;
        }
        return count;
    }
};

int main(){
	Solution s;
	int tmp[]={0,1,2};
	int  rrr=s.firstMissingPositive(tmp,3);
	cout<<rrr<<endl;

}
