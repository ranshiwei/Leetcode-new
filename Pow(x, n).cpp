#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        double result=1;
        if(n>0){
            while(n>0){
                if(n&0x01)
                result*=x;
                x*=x;
                n=n>>1;
            }
            return result;
        }else if(n<0){
            n=-n;
            while(n>0){
                if(n&0x01)
                result*=x;
                x*=x;
                n=n>>1;
            }
            return 1/result;
        }else{
            return result;
        }
    }
};
//class Solution {
//public:
//    double pow(double x, int n) {
//        double result = x;
//        if(x==1) return 1;
//        if(n==0) return 1;
//        if(x==-1)
//            if(n%2==0)
//                return 1;
//            else 
//                return -1;
//        if(n>0){
//        	for(int i=0;i<n-1;i++){
//	            result*=x;
//	            if(abs(result)<1e-10) return 0;
//	            if(abs(result)>LONG_MAX) return LONG_MAX;
//	        }
//	        return result;
//        }else if(n<0){
//        	for(int i=0;i<abs(n)-1;i++){
//	            result*=x;
//	            //if(abs(result)<1e-10) return 0;
////	            if(abs(result)>LONG_MAX) return LONG_MAX;
//	        }
//	        return 1/result;
//        }
//        
//    }
//};


int main(){
	Solution s;
	double result= s.pow(34.00515,-3);
	cout<<result<<endl;
}
