#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0)  
            return 0;
        if(len==1)
            return 0;
        int minprices=INT_MAX,maxprices=INT_MIN;
        int i=0;
        int sum=0;
        int m=0;
        while(i<len){
            for(int j=i;j<len;j++){
                minprices=min(minprices,prices[j]);
                if(maxprices < prices[j]-minprices){
                    maxprices=prices[j]-minprices;
                    m=j;
                }
            }
            sum+=maxprices;
            i=m;
            minprices=INT_MAX;
            maxprices=INT_MIN;
        }
        return sum;
    }
};
int main(){
	int tmp[]={1,2,3,4,3,5};
	vector<int> t(tmp,tmp+(sizeof(tmp)/sizeof(int)));
	Solution s;
	int result=s.maxProfit(t);
	cout<<result<<endl;
}
