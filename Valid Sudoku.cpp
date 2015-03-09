#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
            int n = board.size();
            vector<unordered_map<int,int> > rows(n);
            vector<unordered_map<int,int> > columns(n);
            vector<unordered_map<int,int> > boxes(n*n/9);
            int num, boxIndex;
            for(int i = 0; i < board.size(); ++ i)
                for(int j = 0; j < board[i].size(); ++ j){
                    if(board[i][j] != '.'){
                        num = board[i][j]-'0';
                        boxIndex = (i/3)*n/3+(j/3);
                        rows[i][num]++;
                        columns[j][num]++;
                        boxes[boxIndex][num]++;
                        if( rows[i][num]  > 1 || columns[j][num] > 1 || boxes[boxIndex][num] > 1)
                            return false;
                    }
            }
            return true;
        }
    };
int main(){
	char[][] tem={".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
	Solution s;
	bool result = s.isValidSudoku(tem);
	cout<<result;
}
