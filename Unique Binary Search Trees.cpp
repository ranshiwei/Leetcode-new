#include <iostream>
//Reference code from discuss
using namespace std; 
class Solution {
public:
    int numTrees(int n) {
        int g[n+1];
        for(int i=0;i<=n;i++)
        	g[i]=0;
        g[0]=g[1]=1;
        for(int i=2;i<=n;i++)
            for(int j=1;j<=i;j++)
                g[i]+=g[j-1]*g[i-j];
        return g[n];
    }
};
int main(){
	Solution s;
	long long result=s.numTrees(2);
	cout<<result<<endl;
}
