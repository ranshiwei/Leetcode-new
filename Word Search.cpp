#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m=board.size();
        int n=board[0].size();
        if(m==0||n==0)
        	return false;
        vector<vector<int> > array;
        for(int i=0;i<m;i++){
        	vector<int> t;
        	for(int j=0;j<n;j++){
            	t.push_back(0);
            }
            array.push_back(t);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0])
                    if(findnext(board,word,i,j,m,n,1,array))
                        return true;
            }
        return false;
    }
    bool findnext(vector<vector<char> > &board,string word,int cx,int cy,int mx,int my,int index,vector<vector<int> > &array){
        if(index==word.length())
            return true;
        array[cx][cy]=1;
        if(cx+1<mx&&board[cx+1][cy]==word[index]&&array[cx+1][cy]==0)
            if(findnext(board,word,cx+1,cy,mx,my,index+1,array))
                return true;
        if(cy+1<my&&board[cx][cy+1]==word[index]&&array[cx][cy+1]==0)
            if(findnext(board,word,cx,cy+1,mx,my,index+1,array))
                return true;
        if(cx-1>=0&&board[cx-1][cy]==word[index]&&array[cx-1][cy]==0)
            if(findnext(board,word,cx-1,cy,mx,my,index+1,array))
                return true;
        if(cy-1>=0&&board[cx][cy-1]==word[index]&&array[cx][cy-1]==0)
            if(findnext(board,word,cx,cy-1,mx,my,index+1,array))
                return true;
        array[cx][cy]=0;
        return false;
    }
};
int main(){
	vector<vector<char> > vs;
	vector<char> c1;
	c1.push_back('A');
	c1.push_back('B');
	c1.push_back('C');
	c1.push_back('E');
	vector<char> c2;
	c2.push_back('S');
	c2.push_back('F');
	c2.push_back('C');
	c2.push_back('S');
	vector<char> c3;
	c3.push_back('A');
	c3.push_back('D');
	c3.push_back('E');
	c3.push_back('E');
	vs.push_back(c1);
	vs.push_back(c2);
	vs.push_back(c3);
	Solution s;
	string ss="BFCF";
	bool result=s.exist(vs,ss);
	cout<<result;
} 
