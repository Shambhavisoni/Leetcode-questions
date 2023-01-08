/*1. Run 2 loops(nested loops) to find out the index of a particular element in matrix.
2. Then for every number check if the number:
    *    is not repeated in the same row
    *    is not repeated in the same column
    *    is not repeated in the smaller 3 X 3 matrix --> mat[3*row/3+i/3][3*row/3+i%3]
3. If the following conditions are not satisfied for any number, directly return false.
4.  If the following conditions are satisfied for all numbers, return false.(after coming out of the outer loop).
***Note: We can also use sets/hashmap to check if duplicate elements are there or not***
T.C.= O(n^3)
S.C.= O(1)*/

class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int r,int c){
        for(int k=0;k<9;k++){
            if(k!=c && board[r][k]==board[r][c]){
                return false;
            }
            if(k!=r && board[k][c]==board[r][c]){
                return false;
            }
            if(3*(r/3)+k/3!=r && 3*(c/3)+k%3!=c && board[3*(r/3)+k/3][3*(c/3)+k%3]==board[r][c]){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                        if(!isSafe(board,i,j)){
                            return false;
                        }
                }
            }
        }
        return true;
    }
};
