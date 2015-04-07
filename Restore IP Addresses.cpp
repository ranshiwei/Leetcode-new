#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = strlen(s.c_str());
        if(len==0)
            return result;
        restoreip(s,0,len,0,result,path);
        return result;
    }
    void restoreip(string s,int index,int len,int num, vector<string> &result, vector<string> path){
        if(num==4){
            if(index==len){
            	for(int i=0;i<4;i++){
            		if(path[i].size()>1&&path[i][0]=='0')
            			return;
            	}
                string s=path[0]+"."+path[1]+"."+path[2]+"."+path[3];
                result.push_back(s);
            }else if(index > len)
            	return;
        }
        else if(num>4)
            return;
        for(int i=index,k=1;k<=3;i++,k++){
        	if(index+k>len)
        		break;
            if(k==1||k==2){
                path.push_back(s.substr(index,k));
                restoreip(s,index+k,len,num+1,result,path);
                path.pop_back();
            }else if(k==3){
                if(s[index]-'0'<2||(s[index]-'0'==2&&s[index+1]-'0'<5)||(s[index]-'0'==2&&s[index+1]-'0'==5&&s[index+2]-'0'<=5)){
                    path.push_back(s.substr(index,k));
                    restoreip(s,index+k,len,num+1,result,path);
                    path.pop_back();
                }
            }
        }
    }
private:
    vector<string> result;
    vector<string> path;
};
int main(){
	Solution s;
	string st="010010";
	vector<string> result=s.restoreIpAddresses(st);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
}
