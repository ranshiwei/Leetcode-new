#include "header.h"
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        comb2(num,target,0,path,result);        
    }
    void comb2(vector<int> &num,int target, int index, vector<int> path,vector<vector<int> > &result){
        int nlen = num.size();
        for(int i=index;i<nlen;i++){
            if(target==num[i]){
                vector<int> tmp=path;
                tmp.push_back(num[i]);
                ibegin=result.begin();
				iend=result.end();
				
				if(result.size()==0)
					result.push_back(tmp);
				else{
					for(;ibegin!=iend;ibegin++){
	                    vector<int> tt=*ibegin;
	                    int m=0;
	                    while(tt[m]==tmp[m])
	                        m++;
	                    if(m<tt.size()) result.push_back(tmp);
                	}
				}
            }
            if(target-num[i]>=num[0]){
                vector<int> tmp=path;
                tmp.push_back(num[i]);
                comb2(num,target-num[i],index+1,tmp,result);
            }
        }
    }
private:
    vector<vector<int> > result;
    vector<int> path;
    vector<vector<int> >::iterator ibegin,iend;
};

int main(){
	Solution s;
	int tmp[]={10,1,2,7,6,1,5};
	vector<int> t(tmp,tmp+7);
	vector<vector<int> >  rrr=s.combinationSum2(t,8);
	int length = rrr.size();
	vector<vector<int> >::iterator iibegin,iiend;
	for(;iibegin!=iiend;iibegin++){
	                    vector<int> tt=*iibegin;
	                    int size=tt.size();
						int j=0;
	                    while(j<size)
	                    	cout<<tt[j]<<" ";
	                    	cout<<endl;
                	}
}
