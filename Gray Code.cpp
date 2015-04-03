#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        result.push_back(0);
        int highbit=0;
        while(n--){
            highbit=result.size();
            for(int i=result.size()-1;i>=0;i--){
                result.push_back(highbit | result[i]);
            }
        }
        return result;
    }
private:
    vector<int> result;
};

int main(){
	Solution s;
	vector<int> result=s.grayCode(3);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
}
