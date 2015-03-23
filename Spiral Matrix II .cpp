#include <iostream>
#include "header.h"
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n<=0) return result;
        
        for(int i=0;i<n;i++){
            vector<int> t(n);
            result.push_back(t);
        }
        //result(n,vector<int>(n));
        int start=0,end=n;
        int curnum=1;
        while(start*2<n){
            for(int i=start;i<end;i++){
                result[start][i]=curnum++;
            }
            for(int i=start+1;i<end;i++){
                result[i][end-1]=curnum++;
            }
            for(int i=end-2;i>=start;i--){
                result[end-1][i]=curnum++;
            }
            for(int i=end-2;i>start;i--){
                result[i][start]=curnum++;
            }
            
            start++;
            end--;
        }
        return result;
    }
private:
    vector<vector<int> > result;
};
int main(){
	Solution s;
	vector<vector<int> >  rrr=s.generateMatrix(5);
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
