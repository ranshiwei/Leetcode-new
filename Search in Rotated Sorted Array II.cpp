#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n<=0) return false;
        int left=0,right=n-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(A[mid]==target)
                return true;
            if(A[mid]>A[right]){
                if(A[mid]>target&&A[left]<=target) right=mid-1;
                else left=mid+1;
            }else if(A[mid]<A[right]){
                if(A[mid]<target&&A[right]>=target) left=mid+1;
                else right=mid-1;
            }else{
                right--;
            }
        }
        return A[left]==target ? true : false;
    }
};

int main(){
	int tmp[]={1,1,3,1};
	Solution s;
	bool result=s.search(tmp,sizeof(tmp)/sizeof(int),3);
	cout<<result<<endl;
}
