#include <iostream>
#include <vector>
using namespace std; 
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        result.push_back(vector<int>(0));
        sort(S.begin(),S.end());
        subswd(S,0,S.size(),result,dupArray);
        return result;
    }
    void subswd(vector<int> &s,int n,int len,vector<vector<int> > result,vector<int> cur_vec){
        if(n==len)
            return;
        for(int i=n;i<len;i++){
            if(i==n||s[i]!=s[i-1]){
                cur_vec.push_back(s[i]);
                result.push_back(cur_vec);
                subswd(s,n+1,len,result,cur_vec);
                cur_vec.pop_back();
            }
        }
    }
private:
    vector<int> dupArray;
    vector<vector<int> > result;
};

int main(){
		Solution s;
		int tmp[]={1,2,2,2,3,3};
		vector<int> vi(tmp,tmp+6);
		vector<vector<int> >  rrr=s.subsetsWithDup(vi);
		cout<<rrr.size()<<endl;
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
