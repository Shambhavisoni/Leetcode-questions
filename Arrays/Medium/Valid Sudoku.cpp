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
