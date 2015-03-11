class Solution {
public:
    int trap(int A[], int n) {
        int i,j,volumn;
        int sum=0;
        if(n<3) return 0;
        bool visited[n]={ false };
        i=0;
        while(i<n){
            for(j=i+1,volumn=0;j<n&&A[j]<A[i];j++){
                volumn+=(A[i]-A[j]);
            }
            if(j<n){
                    visited[i]=(A[i]==A[j]);
                    sum+=volumn;
                }
            i=j;
        }
        i=n-1;
        while(i>=0){
            for(j=i-1,volumn=0;j>=0&&A[j]<A[i];j--){
                volumn+=(A[i]-A[j]);
            }
            if(j>=0&&!visited[j]){
                sum+=volumn;
            }
            i=j;
        }
        return sum;
    }
};
