#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        int sbegin,send;
        long long num=x;
        while(num*num>x){
            num>>=1;
        }
        if(num*num==x) return num;
        sbegin=num;
        send=(sbegin<<1)+1;
        int mid;
        while(sbegin<send&&sbegin*sbegin<x){
            mid=(sbegin+send)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid<x){
                sbegin=mid+1;
            }else{
                send=mid-1;
            }
        }
        int min = mid<sbegin?mid:sbegin;
        int max = mid>sbegin?mid:sbegin;
        if(max*max<=x) 
			return max;
        else
        	return min;
    }
};

int main(){
	Solution s;
	int result=s.sqrt(2);
	cout<<result<<endl;
}
