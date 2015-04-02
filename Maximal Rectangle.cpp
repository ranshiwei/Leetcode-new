#include <iostream>
#include <vector>
#include <algorithm>
#include <stack> 
using namespace std; 
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0)
            return 0;
        vector<int> recnum(n);
        int maxmal=0;
        for(int i=0;i<n;i++){
            recnum[i] = matrix[0][i]-'0';
        }
        calmaxmal(recnum,n,maxmal);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int cur=matrix[i][j]-'0';
                if(cur==0)
                    recnum[j]=0;
                else{
                    recnum[j]=recnum[j]+1;
                }
            }
            calmaxmal(recnum,n,maxmal);
        }
        return maxmal;
    }
    void calmaxmal(vector<int> rec,int n,int &maxmal){
        if(n==0) maxmal=0;
        if(n==1) maxmal=max(maxmal,rec[0]);
        stack<int> s;
        int i=0;
        rec.push_back(0);
        n++;
        while(i<n){
            if(s.empty()||rec[s.top()]<=rec[i]) 
                s.push(i++);
            else{
                int h=rec[s.top()];
                s.pop();
                int j=s.empty()?-1:s.top();
                maxmal=max(maxmal,h*(i-j-1));
            }
        }
    }
};

int main(){
	char t1[]={'1','0','1','1'};
//	char t2[]={'0','1','1','1'};
//	char t3[]={'1','0','1','1'};
//	char t4[]={'1','0','1','1'};
	vector<char> v1(t1,t1+4);	
//	vector<char> v2(t2,t2+4);
//	vector<char> v3(t3,t3+4);
//	vector<char> v4(t4,t4+4);
	vector<vector<char> > vv;
	vector<vector<char> > v2;
	vv.push_back(v1);
//	vv.push_back(v2);
//	vv.push_back(v3);
//	vv.push_back(v4);
	Solution s;
	int result=s.maximalRectangle(v2);
	cout<<result<<endl;
}
