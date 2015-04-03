class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int len = m+n-1;
        int acur=m-1;
        int bcur=n-1;
        while(acur>=0&&bcur>=0){
            if(A[acur]>B[bcur]){
                A[len--]=A[acur--];
            }else{
                A[len--]=B[bcur--];
            }
        }
        while(acur>=0)
            A[len--]=A[acur--];
        while(bcur>=0)
            A[len--]=B[bcur--];
    }
};
