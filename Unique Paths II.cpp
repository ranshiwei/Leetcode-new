class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        vector<int> t;
        if(m>0)
            t = obstacleGrid[0];
        else
            return 0;
        int n=t.size();
        
        int count=0;
        if(m<=0||n<=0)
        	return 0;
        if(m==1||n==1){
             if(m==1){
                 for(int i=0;i<n;i++)
                    if(obstacleGrid[0][i]==1)
                        return 0;
             }else{
                 for(int i=0;i<m;i++)
                    if(obstacleGrid[i][0]==1)
                        return 0;
             }
            return 1;
        }
        int path[m][n];
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        for(int i=0;i<m;i++)
        	for(int j=0;j<n;j++){
        		path[i][j]=0;
        	}
        bool flag=false;
        for(int i=m-2;i>=0;i--){
            if(obstacleGrid[i][n-1]==1||flag){
                path[i][n-1]=0;
                flag=true;
            }
            else
                path[i][n-1]=1;
        }
        flag=false;	
        for(int i=n-2;i>=0;i--){
            if(obstacleGrid[m-1][i]==1||flag){
                path[m-1][i]=0;
                flag=true;
            }else
                path[m-1][i]=1;
        }
        for(int i=m-2;i>=0;i--)
        	for(int j=n-2;j>=0;j--){
        	    if(obstacleGrid[i][j]==1)
        	        path[i][j]=0;
        	    else
        	        path[i][j]=path[i+1][j]+path[i][j+1];
        	}
        return path[0][0];
    }
};
