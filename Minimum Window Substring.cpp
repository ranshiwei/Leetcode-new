#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.empty()||T.empty())
            return "";
        int count=T.length(); // £”‡∆•≈‰ ˝
        int require[128]={0};
        bool chSet[128]={false};
        for(int i=0;i<count;i++){
            require[T[i]]++;
            chSet[T[i]]=true;
        }
        int i=-1;
        int j=0;
        int minlen=INT_MAX;
        int minid=0;
        int len=S.length();
        while(i<len&&j<len){
            if(count){
                i++;
                require[S[i]]--;
                if(require[S[i]]>=0)
                    count--;
            }else{
                if(minlen>i-j+1){
                    minlen=i-j+1;
                    minid=j;
                }
                require[S[j]]++;
                if(chSet[S[j]]&&require[S[j]]>0)
                    count++;
                j++;
                
            }
        }
        if(minlen==INT_MAX)
            return "";
        return S.substr(minid,minlen);
    }
};

int main(){
	Solution s;
	string s1="ADOBECODEBANC";
	string s2="ABC";
	string result=s.minWindow(s1,s2);
	cout<<result<<endl;
}
