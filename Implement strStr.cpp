#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int haylen=strlen(haystack);
        int nelen=strlen(needle);
        if(nelen==0) return 0;
        int clen;
        for(int n=0;n<haylen;n++){
        	clen=n;
            int i=0;
            if(haylen-clen<nelen) break;
            while(haystack[clen++]==needle[i++]){
                if(i==nelen)
                    return (clen-nelen);
                continue;
            }
        }
        return -1;
    }
};

int main(){
	Solution s;
	char *s1="a";
	char *s2="a";
	int result = s.strStr(s1,s2);
	cout<<result<<endl;
}
