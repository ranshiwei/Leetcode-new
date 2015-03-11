#include "header.h"
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(),num.end());
        int n=num.size();
        result.push_back(num);
        if(n==1){
            return result;
        }
        for(int i=n-2;i>=0;i--){
            int len = result.size();
            for(int k=0;k<len;k++){
            	vector<int> tmp=result[k];
            	vector<int> ctmp=tmp;
            	for(int j=i+1;j<n;j++){
	                swap(ctmp[i],ctmp[j]);
	                cout<<endl;
	                result.push_back(ctmp);
	                ctmp=tmp;
	            }
            }
        }
        return result;
    }
private:
    vector<vector<int> > result;
};

int main(){
	Solution s;
	int tmp[]={1,2,3};
	vector<int> t(tmp,tmp+3);
	vector<vector<int> > r=s.permute(t);
	cout<<r.size()<<endl;
}
