#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int count=1,k;
        if(n==0) return 0;
        for(int i=0;i<n;){
            int ms=A[i];
            if(i+ms>=n-1) return count;
            k=A[i];
            int max=i;
            for(int j=i+1,m=1;j<=i+ms;j++,m++){
                if(A[j]==0) continue;
                if(A[j]+m>k){
                    k=A[j]+m;
                    max=j;
                }
                    
            }
            i=max;
            count++;
        }
        return count;
    }
};
int main(){
	Solution s;
	int tmp[]={1};
	int result=s.jump(tmp,1);
	cout<<result<<endl;
}
