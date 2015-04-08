#include <iostream>
#include <string>
#include <string.h>
#include <vector>
//Cann't understand the fucking code!!
using namespace std;
class Solution{
	public:
	bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int size = s3.size();
        if (m+n !=  size) return false;
        vector<vector<bool> > f; // f[i][j] means taken first i chars from s1 and first j from s2 to get s3[0...i+j-1]
        for (int i = 0; i <= m; ++i) {
            f.push_back(vector<bool>(n+1,false));
        }
        f[0][0] = true;
        // take 0 chars from s2 and i chars from s2
        for (int i = 1; i <= m; ++i) {
            f[i][0] = f[i-1][0] && s1[i-1]==s3[i-1];
        }
        // take 0 chars from s1 and j chars from s2
        for (int j = 1; j <= n; ++j) {
            f[0][j] = f[0][j-1] && s2[j-1]==s3[j-1];
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = (f[i-1][j] && s1[i-1]==s3[i+j-1]) || (f[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return f[m][n];
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
