#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    int search(int A[], int n, int target) {
    int mid = n/2;
    int left=0,right=n-1;
    int result;
    if(n==1) return A[0]==target?0:-1;
    while(left<=right){
        mid=(left+right)/2;
        if(A[mid]==target) return mid;
        if(A[right]==target) return right;
        if(A[left]==target) return left;
        if(A[left]<A[mid]){
            if(A[mid]>target&&A[left]<=target){
                result = binarySearch(A,left,mid,target);
                if(result!=-1)
                    return result;
                else
                	return -1;
            }else{
            	//if(A[left]==target) return left;
                left=mid+1;
            }
        }
        else{
            if(A[mid]<target){
                result=binarySearch(A,mid,right,target);
                if(result!=-1)
                    return result;
                else
                	return -1;
            }else{
            	
                right=mid-1;
            }
        }
    }
    return -1;
    }
    int binarySearch(int A[], int left,int right, int target){
        int middle;
        while(left<=right){
            middle=(left+right)/2;
            if(A[middle]==target)
                return middle;
            else if(A[middle]<target){
                left=middle+1;
            }else if(A[middle]>target){
                right=middle-1;
            }
            if(left>right) return -1;
        }
    }
};

int main(){
	int A[]={8,9,2,3,4};
	Solution s;
	int result = s.search(A,5,9);
	cout<<result<<endl;
}
