#include <iostream>
#include <string.h>
#include <string>
using namespace std;
 
class Solution {
public:
    string simplifyPath(string path) {
        int len=strlen(path.c_str());
        string temp=path.replaceAll("//","/");
        
    }
};
int main(){
	Solution s;
	string ss="/home//foo/";
	string result=s.simplifyPath(ss);
	cout<<result<<endl;
}
