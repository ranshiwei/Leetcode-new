#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std; 
class Solution {
public:
int largestRectangleArea(vector<int> &height) {
        int n=height.size();
        if(n==0) return 0;
        if(n==1) return height[0];

        height.push_back(0);
        n++;

        int ans=0;
        stack<int> s;

        int i=0,j=0,h=0;
        while(i<n){
            if(s.empty() || height[i]>height[s.top()]) s.push(i++);
            else{
                h=height[s.top()];
                s.pop();
                j= s.empty() ? -1:s.top();
                ans=max(ans,h*(i-j-1));
            }
        }
        return ans;
    }
};

int main(){
	int tmp[]={2,1,5,6,3,4,2};
	vector<int> t(tmp,tmp+7);
	Solution s;
	int result=s.largestRectangleArea(t);
	cout<<result;
}
