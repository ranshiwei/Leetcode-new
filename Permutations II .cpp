#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<int> tmpr = num;
        vector<int> tmpr2;
        result.push_back(num);
        
        while(1){
        	tmpr2=tmpr;
            tmpr=nextPermute(tmpr);
            int len=tmpr.size();
            int i=0;
            while(tmpr[i]==tmpr2[i]) i++;
            if(i<len)
            	result.push_back(tmpr);
            else 
				return result;
            for(obegin=tmpr.begin(),oend=tmpr.end();(obegin+1)!=oend;obegin++){
                if(*obegin<*(obegin+1))
                    break;
            }
            if(obegin+1==oend)
                return result;
        }
    }
    vector<int> nextPermute(vector<int> &num){
        int len=num.size();
        for(int i=len-2;i>=0;i--){
            int j=i+1;
            if(num[i]<num[j]){
                sort(num.begin()+j,num.end());
                while(num[j]<=num[i]) j++;
                swap(num[i],num[j]);
                return num;
            }
        }
        return num;
    }
private:
 vector<vector<int> > result;
 vector<int>::iterator obegin,oend;
};

int main(){
	Solution s;
	int tmp[]={1,1};
	vector<int> t(tmp,tmp+2);
	vector<vector<int> >  rrr=s.permuteUnique(t);
	int length = rrr.size();
	cout<<length<<endl;
	vector<vector<int> >::iterator iibegin=rrr.begin(),iiend=rrr.end();
	for(;iibegin!=iiend;iibegin++){
	                    vector<int> tt=*iibegin;
	                    int size=tt.size();
						int j=0;
	                    while(j<size)
	                    	cout<<tt[j++]<<" ";
	                    	cout<<endl;
                	}
}
