#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        for(int i=0;i<strs.size();i++){
            string cs=strs[i];
            sort(cs.begin(),cs.end());
            
            if(rmap.find(cs)==rmap.end()){
                rmap[cs]=i;
            }else{
                if(rmap[cs]>=0){
                	result.push_back(strs[rmap[cs]]);
                	rmap[cs]=-1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
private:
    map<string,int>  rmap;
    vector<string> result;
};

int main(){
	Solution s;
	string tt[]={"den","tea","and","ate","eat","end"};
	vector<string> cst(tt,tt+6);
	vector<string> rs=s.anagrams(cst);
	for(int i=0;i<rs.size();i++){
		cout<<rs[i]<<endl;
	}
}
