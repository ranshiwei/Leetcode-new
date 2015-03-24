#include <iostream>
#include "header.h"
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if(m<=0) return -1;
        vector<int> t=grid[0];
        int n=t.size();
        int sum=0;
        if(m==1){
            for(int i=0;i<n;i++)
                sum=grid[0][i];
            return sum;
        }
        if(n==1){
            for(int i=0;i<n;i++)
                sum=grid[i][0];
            return sum;
        }
        int path[m][n];
        for(int i=0;i<m;i++)
        	for(int j=0;j<n;j++)
        		path[i][j]=0;
        path[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-2;i>=0;i--){
            path[i][n-1]=path[i+1][n-1]+grid[i][n-1];
        }
        for(int i=n-2;i>=0;i--){
            path[m-1][i]=path[m-1][i+1]+grid[m-1][i];
        }
        for(int i=m-2;i>=0;i--)
            for(int j=n-2;j>=0;j--){
                int min=path[i+1][j]<path[i][j+1]?path[i+1][j]:path[i][j+1];
                path[i][j]=min+grid[i][j];
            }
        return path[0][0];
    }
};

int main(){
	Solution s;
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(2);
	vector<int> t2;
	t2.push_back(1);
	t2.push_back(1);
	vector<vector<int> > result;
	result.push_back(t1);
	result.push_back(t2);
	int  rrr=s.minPathSum(result);
	cout<<rrr<<endl;
}
