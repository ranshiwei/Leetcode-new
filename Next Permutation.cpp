#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        for(int i=len-1;i>=1;){
            int j=i-1;
            if(num[j]<num[i]){
                sort(num.begin()+i, num.end());
                while(num[i]<=num[j])
                	i++;
                	
                num[i]=num[j]^num[i];
                num[j]=num[j]^num[i];
                num[i]=num[j]^num[i];
                return;
            }
            i=j;
        }
        sort(num.begin(),num.end());
        return;
    }
};

int main(){
	int tmp[]={2,2,7,5,4,3,2,2,1};
	vector<int> result(tmp,tmp+9);
	Solution s;
	s.nextPermutation(result);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
}
