#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if(k>n||k<1||n<1) return result;
        for(int i=1;i<=n-k+1;i++){
            path.push_back(i);
            comb(n,i,k,result,path);
            path.pop_back();
        }
        return result;
    }
    void comb(int n,int index,int k,vector<vector<int> > &result,vector<int> &path){
        if(path.size()==k){
            result.push_back(path);
            return;
        } 
        for(int i=index+1;i<=n;i++){
            path.push_back(i);
            comb(n,index+1,k,result,path);
            path.pop_back();
        }
    }
private:
    vector<vector<int> >result;
    vector<int> path;
};

int main(){
		Solution s;
		vector<vector<int> >  rrr=s.combine(2,1);
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
