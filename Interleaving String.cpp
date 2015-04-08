#include <iostream>
#include <string>
#include <string.h>
//  Time Limit Exceeded Code
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len = s3.size();
        if(len1==0&&len2==0)
            return true;
        if(len==0&&(len1>0||len2>0))
            return false;
        int i=0,j=0,k=0;
        while(k<len){
            if(s1[i]!=s2[j]){
                if(s1[i]==s3[k]){
                    i++;k++;
                }else if(s2[j]==s3[k]){
                    j++;k++;
                }else
                    k++;
            }else{
                if(s1[i]==s3[k]){
                    return isInterleave(s1.substr(i+1),s2.substr(j),s3.substr(k+1)) 
                            || isInterleave(s1.substr(i),s2.substr(j+1),s3.substr(k+1));
                }else{
                    k++;
                }
            }
        }
        if(i==len1&&j==len2)
        	return true;
        else
        	return false;
    }
};
int main(){
	Solution s;
	string s1="abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb";
	string s2="ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc";
	string s3="cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc";
	bool result=s.isInterleave(s1,s2,s3);
	cout<<result<<endl;
}
