class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.length()+1;
        int len2=strlen(word2.c_str())+1;
        int path[len1][len2];
        for(int i=0;i<len1;i++)
            for(int j=0;j<len2;j++)
                path[i][j]=0;
        for(int i=0;i<len1;i++){
            path[i][0]=i;
        }
        for(int i=0;i<len2;i++)
            path[0][i]=i;
        for(int i=1;i<len1;i++)
            for(int j=1;j<len2;j++){
                if(word1[i-1]==word2[j-1])
                    path[i][j]=path[i-1][j-1];
                else{
                    path[i][j]=path[i-1][j-1]+1;
                    path[i][j]=min(path[i][j],min(path[i-1][j]+1,path[i][j-1]+1));
                }
            }
        return path[len1-1][len2-1];
    }
};
