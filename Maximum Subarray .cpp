class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n<=0) return -1;
        maxnum=A[0];
        cnum=A[0];
        for(int i=1;i<n;i++){
            if(cnum<0)
                cnum=A[i];
            else{
                cnum+=A[i];
            }
            if(cnum>maxnum)
                maxnum=cnum;
        }
        return maxnum;
    }
private:
    int maxnum,cnum;
};
