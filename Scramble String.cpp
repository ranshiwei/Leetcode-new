#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1=strlen(s1.c_str());
        int len2=strlen(s2.c_str());
        if(len1!=len2)
            return false;
        if(s1==s2) return true;
        if(len1==0||len2==0) 
            return false;
        int charset[26];
        for(int i=0;i<26;i++)
        	charset[i]=0;
        for(int i=0;i<len1;i++)
            charset[s1[i]-'a']++;
        for(int i=0;i<len2;i++)
            charset[s2[i]-'a']--;
        for(int i=0;i<26;i++)
            if(charset[i]!=0)
                return false;
        bool result = false;
        for(int i=1;i<len1;i++){
            result=isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i));
            if(result)
                return true;
            result=isScramble(s1.substr(0,i),s2.substr(len1-i,i))&&isScramble(s1.substr(i),s2.substr(0,len1-i));
            if(result)
                return true;
        }
    return false;
    }
};

int main(){
	Solution s;
	string s1="xstjzkfpkggnhjzkpfjoguxvkbuopi";
	string s2="xbouipkvxugojfpkzjhnggkpfkzjts";
	bool result=s.isScramble(s1,s2);
	cout<<result<<endl;
}
