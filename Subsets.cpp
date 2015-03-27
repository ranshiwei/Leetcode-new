#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
    	if(S.size()==0){
    		result.push_back(S);
    		return result;
    	}
        sort(S.begin(),S.end());
        for(int i=1;i<S.size();i++)
        	combine(S,i,result);
        result.push_back(S);
        vector<int> nu;
        result.push_back(nu);
        return result;
    }
    void combine(vector<int> s,int k,vector<vector<int> > &result){
            vector<int> path;
            for(int j=0;j<=s.size()-k;j++){
                path.push_back(s[j]);
                comb(s,j+1,k,result,path);
                path.pop_back();
            }
    }
    void comb(vector<int> s,int start,int k,vector<vector<int> > &result,vector<int> &path){
        if(path.size()==k){
            result.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            path.push_back(s[i]);
            comb(s,i+1,k,result,path);
            path.pop_back();
        }
    }
private:
    vector<vector<int> >result;
};

int main(){
		Solution s;
		int a[]={1,2,3,4};
		vector<int> tmp(a,a+4);
		vector<vector<int> >  rrr=s.subsets(tmp);
		vector<vector<int> >::iterator iibegin=rrr.begin(),iiend=rrr.end();
		for(;iibegin!=iiend;iibegin++){
		    vector<int> tt=*iibegin;
		    int size=tt.size();
			int j=0;
		    while(j<size)
		     	cout<<tt[j++]<<' ';;
		       	cout<<endl<<endl;;
	    }	
}
