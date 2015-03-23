#include <iostream>
using namespace std;
 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int count=0;
        countPaths(0,0,m-1,n-1,count);
        return count;
    }
    void countPaths(int curX,int curY,int endX,int endY,int &count){
        if(curX==endX&&curY==endY)
            count++;
        if(curX<endX){
            countPaths(curX+1,curY,endX,endY,count);
        }
        if(curY<endY){
            countPaths(curX,curY+1,endX,endY,count);
        }
    }
};
int main(){
	Solution s;
	int result= s.uniquePaths(3,3);
	cout<<result;
}
