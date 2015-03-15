#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        int count=0;
        vector<int> path;
        SQ(result,0,path,n);
        return result;
    }
    void SQ(vector<vector<string> > &result,int i,vector<int> path,int n){
        if(i>=n){
        	vector<string> cr;
        	for (int i=0; i<path.size(); i++) {
	                string s = string(n, '.');
	                s[path[i]]='Q';
	                cr.push_back(s);    
                }
            result.push_back(cr);
            return;
        } 
            
        for(int j=0;j<n;j++){
            if(NotInSameColumn(j,path)){
                path.push_back(j);
                SQ(result,i+1,path,n);
                path.pop_back();
            }
        }
    }
    
    bool NotInSameColumn(int j,vector<int> p){
        for(int i=0;i<p.size();i++){
            if(p[i]==j||(p.size()-i)==abs(j-p[i]))
                return false;
        }
        return true;
    }
};
int main(){
	Solution s;
	vector<vector<string> >  rrr=s.solveNQueens(8);
	int length = rrr.size();
	cout<<length<<endl;
	vector<vector<string> >::iterator iibegin=rrr.begin(),iiend=rrr.end();
	for(;iibegin!=iiend;iibegin++){
	                    vector<string> tt=*iibegin;
	                    int size=tt.size();
						int j=0;
	                    while(j<size)
	                    	cout<<tt[j++]<<endl;;
	                    	cout<<endl<<endl;;
                	}
}
