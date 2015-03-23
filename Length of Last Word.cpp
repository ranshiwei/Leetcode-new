class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len=strlen(s);
        if(len==0) return 0;
        int i=0,j=len-1;
        while(s[j]==' ') j--;
        while(s[j]!=' '&&j>=0){
            i++;
            j--;
        }
        return i;
    }
};
