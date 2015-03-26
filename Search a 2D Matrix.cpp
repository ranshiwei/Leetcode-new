class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0) return false;
        for(int i=0;i<m;i++){
            if(matrix[i][n-1]<target)
                continue;
            else if(matrix[i][n-1]==target)
                return true;
            else{
                for(int j=n-2;j>=0;j--){
                    if(matrix[i][j]>target){
                        continue;
                    }else if(matrix[i][j]==target){
                        return true;
                    }else{
                        break;
                    }
                }
            }
        }
        return false;
    }
};
