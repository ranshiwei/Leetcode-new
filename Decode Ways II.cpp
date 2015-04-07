#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
		int len=strlen(s.c_str());
        if(len==0) return 0;
        if(len==1) 
			if(s[0]=='0')
				return 0;
			else
				return 1;
        int count=0;
        int num[len];
        if(s[len-1]=='0')
        	num[len-1]=0;
        else
        	num[len-1]=1;
        	
        if(s[len-2]=='0'){
        	num[len-2]=0;
        }else{
        	if((s[len-2]-'0')==2&&((s[len-1]-'0')<=6)&&(s[len-1]!='0')||(s[len-2]-'0')==1&&(s[len-1]!='0'))
	        	num[len-2]=2;
	        else
	        	num[len-2]=1;
        }
        if(s[len-1]=='0'&&(s[len-2]-'0')>2)
        	return 0;
        for(int i=len-3;i>=0;i--){
        	if(s[i]=='0'){
        		num[i]=0;
        		continue;
        	}
        	if(((s[i]-'0'==2)&&(s[i+1]-'0')<=6)||(s[i]-'0'==1))
	        	num[i]=num[i+1]+num[i+2];
	        else
	        	num[i]=num[i+1];
	        if(s[i-1]=='0'&&s[i]-'0'>2)
        		return 0;
        }
        return num[0];
    }
};

int main(){
	Solution s;
	string st="100";
	int result=s.numDecodings(st);
	cout<<result<<endl;
}
