#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int len=strlen(s.c_str());
        if(len==0) return 0;
        if(len==1) return 1;
        int count=0;
        if(s[0]-'0'>2||(s[0]-'0'==2&&(1<len && s[1]-'0'>6)))
            count = countNum(s,1,len,count)+1;
        else{
            count = countNum(s,1,len,count)+countNum(s,2,len,count)+1;
        }
        return count;
    }
    int countNum(string s,int index,int len,int count){
        if(index>=len)
            return 0;
        if(s[index]-'0'>2||(s[index]-'0'==2&&(index+1<len && s[index+1]-'0'>6)))
            count = countNum(s,index+1,len,count)+1;
        else{
            count = countNum(s,index+1,len,count)+countNum(s,index+2,len,count)+1;
        }
        return count;
    }
};

int main(){
	Solution s;
	string st="122";
	int result=s.numDecodings(st);
	cout<<result<<endl;
}
