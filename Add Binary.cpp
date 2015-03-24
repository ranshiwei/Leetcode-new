#include <iostream>
#include <string>
#include <string.h>
using namespace std;
 
class Solution {
public:
    string addBinary(string a, string b) {
        int alen=strlen(a.c_str());
        int blen=strlen(b.c_str());
        
        if(alen==0) return b;
        if(blen==0) return a;
        int max=alen>blen?alen:blen;
        string result(max+1,' ');
        int carry=0;
        int i=alen-1,j=blen-1,k=max;
        
        while(i>=0&&j>=0){
            int aa=a[i]-'0';
            int bb=b[j]-'0';
            int r=aa+bb+carry;
            carry=0;
            if(r>1){
                result[k--]= r%2+'0';
                carry=1;
            }else{
                result[k--]=r+'0';
                carry=0;
            }
            i--;
            j--;
        }
        if(i>=0){
            if(carry==0){
                while(i>=0)
                    result[k--]=a[i--];
            }else{
                int t;
                for(int m=i;m>=0;m--){
                    int num=a[m]-'0';
					t=num+carry;
                    if(t>1){
                        result[k--]='0';
                        carry=1;
                    }else{
                        result[k--]=t+'0';
                        carry=0;
                    }
                }
            }
        }
        if(j>=0){
            if(carry==0){
                while(j>=0)
                    result[k--]=b[j--];
            }else{
                int t;
                for(int m=j;m>=0;m--){
                    int num=b[m]-'0';
					t=num+carry;
                    if(t>1){
                        result[k--]='0';
                        carry=1;
                    }else{
                        result[k--]=t+'0';
                        carry=0;
                    }
                }
            }
        }
		if(carry){
			char p=1+'0';
			result[0]=p;
		}else{
			result=result.substr(1,max);
		}
        return result;
    }
};

int main(){
	Solution s;
	string a="100";
	string b="110010";
	string result=s.addBinary(a,b);
	cout<<result;
}
