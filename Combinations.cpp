#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if(k>n) return result;
        if(k==n){
        	vector<int> r;
        	for(int i=1;i<=n;i++){
        		r.push_back(i);
        	}
        	result.push_back(r);
        	return result;
        }
        if(k==1){
        	for(int i=0;i<n;i++){
        		vector<int> r;
        		r.push_back(i+1);
        		result.push_back(r);
        	}
        	return result;
        }
        for(int i=1;i<=n-k+1;i++){
        	vector<int> r;
        	int count=k-1;
        	while(count){
        		for(int j=i;j<i+k-1;j++){
	        		r.push_back(j);
	        	}
				for(int m=i+k-1;m<=n;m++){
		                r.push_back(m);
		                result.push_back(r);
		                r.pop_back();
		                count--;
		        }
        	}
        	
            	
            
        }
        return result;
    }
private:
    vector<vector<int> >result;
};
int main(){
		Solution s;
		vector<vector<int> >  rrr=s.combine(5,3);
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
