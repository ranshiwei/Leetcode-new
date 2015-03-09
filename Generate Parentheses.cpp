#include <iostream>
#include <string>
#include <vector> 
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generate(n,n,s,result);
        return result;
    }
    void generate(int leftNum,int rightNum,string s,vector<string> &result){
        if(leftNum==0 && rightNum==0)
            result.push_back(s);
        if(leftNum>0)
            generate(leftNum-1,rightNum,s+'(',result);
        if(rightNum>0 && leftNum<rightNum)
            generate(leftNum,rightNum-1,s+')',result);
    }
private:
    vector<string> result;
    string s;
}; 

int main(){
	Solution s;
	vector<string> vs;
	vs = s.generateParenthesis(3);
	for(int i=0;i<vs.size();i++)
		cout<<vs[i]<<endl;
}
