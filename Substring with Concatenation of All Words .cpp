#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
    int wlen = L[0].length();
    int slen = S.length();
    
    map<string,int> lmap;
    map<string,int>::iterator mite;
    vector<int> result;
    if(slen==0||wlen==0) return result;
    
    for(vector<string>::iterator ibegin=L.begin(),iend=L.end();ibegin!=iend;ibegin++){
        lmap[string(*ibegin)] = 0;
    }
    int j;
    for(int i=0;i<slen;){
    	string len=S.substr(i,wlen);
        mite = lmap.find(len);
        if(mite!=lmap.end()){
        	j++;
            lmap[string(len)]=1;
            
            map<string,int>::iterator mbegin=lmap.begin(),mend=lmap.end();
            for(;mbegin!=mend&&mbegin->second==1;mbegin++){
			}
            if(mbegin==mend){
                result.push_back(i-wlen);
            }
            if(i+wlen<slen)
            	i=i+wlen;
            else
            	break;
        }
        else{
        	j++;
        	for(vector<string>::iterator ibegin=L.begin(),iend=L.end();ibegin!=iend;ibegin++){
                lmap[*ibegin] = 0;
            } 
            i=j;
        }
            
    }
    return result;
    }
};

int main()
{
	string chi[] = {"foo","bar"};
	vector<string> child(chi,chi+2);
	string s = "barfoothefoobarman";
	vector<int> re;
	Solution ss;
	re = ss.findSubstring(s,child);
	for(int i=0;i<re.size();i++){
		cout<<re[i]<<endl;
	} 
}
