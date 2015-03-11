#include "header.h"
#include <string.h>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        bool result=false;
        int slen=strlen(s);
        int plen=strlen(p);
        if(slen<plen) return false;
        int k;
        for(int i=0;i<slen;){
            if(s[i]==p[i]||p[i]=='?'){
            	i++;
            	if(i<slen&&(i==plen)) return false;
            }
            else if(p[i]=='*'){
                k=i;
                while(i<slen)
                    i++;
                while(k<plen&&(p[k]=='*'||p[k]=='?')) k++;
			   	if(k<plen)
			        return false;
            }else{
                return false;
            }
        }
        return true;
        
    }
};

int main(){
	Solution st;
	char *s="aa";
	char *p="*a";
	bool r=st.isMatch(s,p);
	cout<<r;
}
