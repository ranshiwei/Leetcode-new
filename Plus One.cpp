#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len=digits.size();
        if(len<=0) return digits;
        int carry=0;
        int temp=0;
        int i;
        digits[len-1]+=1;
        for(i=len-1;i>=0;i--){
            temp=digits[i]+carry;
            if(temp>9){
                carry=1;
                digits[i]=temp%10; 
            }else{
                digits[i]=temp;
                break;
            }
        }
        if(i>=0)
            return digits;
        else{
            vector<int> result(len+1);
            for(int i=len-1;i>0;i--)
                result[i+1]=digits[i];
            result[1]=temp%10;
            result[0]=1;
            
            return result;
        }
    }
};
int main(){
		Solution ss;
		int tt[]={2,9,9};
		vector<int> vt(tt,tt+3);
		vector<int> re=ss.plusOne(vt);
		for(int i=0;i<re.size();i++){
			cout<<re[i]<<endl;
		}
}
