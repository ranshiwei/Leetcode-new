#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        int pos=n-1;
        int curpos=n-2;
        while(curpos>=0 && pos!=0){
            if(A[curpos]+curpos>=pos)
                pos=curpos;
            curpos--;
        }
        return (pos==0)?true:false;
	}
};

//class Solution {
//public:
//    bool canJump(int A[], int n) {
//        if(n<0)
//            return false;
//        return cJ(A,0,n-1,0);
//    }
//    bool cJ(int A[],int left,int end,int path){
//        if(path>end)
//            return false;
//        if(path==end)
//        	return true;
//        if(A[left]==0) {
//            if(path<end)
//                return false;   
//            else
//                return true;
//        }
//        for(int i=A[left];i>=1;i--){
//            if(cJ(A,left+i,end,path+i))
//                return true;
//        }
//        return false;
//    }
//};
int main(){
	int A[]={0};
	Solution s;
	bool result=s.canJump(A,sizeof(A)/sizeof(int));
	cout<<result;
} 
