class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
            rows=matrix.size();
            if(matrix.size()>0){
                temp=matrix[0];
                columns=temp.size();
            }else{
                return result;
            }
            int begin=0;
            while(begin*2<columns&&begin*2<rows){
                
                int endX=columns-1-begin;
                int endY=rows-1-begin;
                
                for(int i=begin;i<=endX;i++)
                    result.push_back(matrix[begin][i]);
                if(begin<endY){
                    for(int i=begin+1;i<=endY;i++)
                        result.push_back(matrix[i][endX]);
                }
                if(begin<endY&&begin<endX){
                    for(int i=endX-1;i>=begin;i--)
                        result.push_back(matrix[endY][i]);
                }
                if(begin<endY-1&&begin<endX){
                    for(int i=endY-1;i>=begin+1;i--)
                        result.push_back(matrix[i][begin]);
                }
                begin++;
            }    
                
            return result;
    }
private:
    int rows,columns;
    vector<int> temp,result;
};
