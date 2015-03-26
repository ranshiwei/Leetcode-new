#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        if(n<=0) return;
        int rnum=0,bnum=n-1;
        for(int i=0;i<n;i++){
            while(A[i]==2&&i<bnum) 
				swap(A[i],A[bnum--]);
            while(A[i]==0&&i>rnum) 
				swap(A[i],A[rnum++]);
        }
    }
};

int main(){
	int tmp[]={0,1,0};
	Solution s;
	int len=sizeof(tmp)/sizeof(int);
	s.sortColors(tmp,len);
	for(int i=0;i<len;i++)
		cout<<tmp[i]<<endl;
}
