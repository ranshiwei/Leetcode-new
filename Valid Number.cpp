#include <iostream>
#include <string>
#include <string.h> 
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int len=strlen(s.c_str());
        if(len<=0) return false;
        int i=0;
        bool symbol=false;
        bool rePoint=false;
		bool reE=false;
		bool hasNum=false;
		int blank=0;	
        while(s[i]!='\0'){
        	if((s[i]>='0'&&s[i]<='9')||(s[i]=='.')||(s[i]=='e')||(s[i]==' '||(s[i]=='+'||s[i]=='-'))){
        		if(s[i]=='+'||s[i]=='-'){
					symbol=true;
					if(hasNum||rePoint)
						return false;
				}
        		if(s[i]=='.'){
					if(rePoint||reE)
						return false;
					rePoint=true;
					if((s[i+1]=='\0'&&!hasNum)) return false;
				}
				if(s[i]=='e'){
	        		if(reE||!hasNum)
	        			return false;
	        		reE=true;
	        		hasNum=false;
	        		if(s[i+1]=='\0') return false;
	        		
	        		if(s[i+1]=='+'||s[i+1]=='-')
        				i++;
	        	}
	        	if(s[i]==' '){
	        		if(hasNum||reE||rePoint||symbol){
						while(s[i]==' ') i++;
						if(s[i]=='\0'&&hasNum) return true;
						else 
							return false;
					}
					blank++;
	        	}
	        		
	        	if(s[i]>='0'&&s[i]<='9'){
	        		hasNum=true;
	        	}
	        	i++;
        	}else
        		return false;
        }
        if(i==blank)
       		return false;
    	if(s[i]=='\0'&&hasNum)
        	return true;
        else 
			return false;
    }
};
int main(){
	Solution ss;
	string s=" -1e-1";
	bool result=ss.isNumber(s);
	cout<<result;
}
