#include <iostream>
#include <vector>
#include <limits.h>
//Time Limit Exceeded
using namespace std; 
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int len = triangle.size();
        if(len==0)
            return 0;
        int sum=0;
        int minth=INT_MAX;
        int curlen=triangle[0].size();
        for(int i=0;i<curlen;i++){
            minpath(triangle,i,1,len,sum+triangle[0][i],minth);
            minpath(triangle,i+1,1,len,sum+triangle[0][i+1],minth);
        }
        return minth;
    }
    
    void minpath(vector<vector<int> > &triangle,int i, int level,int len,int sum,int &minth){
        if(level==len){
            if(sum<minth)
                minth=sum;
            return;
        }
        int curlen=triangle[level].size();
        if(i<curlen)
            minpath(triangle,i,level+1,len,sum+triangle[level][i],minth);
        if(i+1<curlen)
            minpath(triangle,i+1,level+1,len,sum+triangle[level][i+1],minth);
        return;
    }
};
int main(){
	vector<int> v1;
	v1.push_back(-1);
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	vector<int> v3;
	v3.push_back(1);
	v3.push_back(-1);
	v3.push_back(-3);
	vector<vector<int> > vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	Solution s;
	int result=s.minimumTotal(vv);
	cout<<result<<endl;
}
