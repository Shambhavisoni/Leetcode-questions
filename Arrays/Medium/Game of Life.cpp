class Solution {
public:
    void deadCondition(vector<vector<int>>& board,int i,int j,vector<vector<int>>& v,int m,int n){
        int c=0;
        if(i>0){
            if(board[i-1][j]==1){
                c++;
            }
        }
        if(i<m-1){
            if(board[i+1][j]==1){
                c++;
            }
        }
        if(j>0){
            if(board[i][j-1]==1){
                c++;
            }
        }
        if(j<n-1){
            if(board[i][j+1]==1){
                c++;
            }
        }
        if(i>0 && j>0){
            if(board[i-1][j-1]==1){
                c++;
            }
        }
        if(i<m-1 && j<n-1){
            if(board[i+1][j+1]==1){
                c++;
            }
        }
        if(i>0 && j<n-1){
            if(board[i-1][j+1]==1){
                c++;
            }
        }
        if(i<m-1 && j>0){
            if(board[i+1][j-1]==1){
                c++;
            }
        }
        if(c==3){
            v.push_back({i,j});
        }
    }
    void liveCondition(vector<vector<int>>& board,int i,int j,vector<vector<int>>& v,int m,int n){
        int c=0;
        if(i>0){
            if(board[i-1][j]==1){
                c++;
            }
        }
        if(i<m-1){
            if(board[i+1][j]==1){
                c++;
            }
        }
        if(j>0){
            if(board[i][j-1]==1){
                c++;
            }
        }
        if(j<n-1){
            if(board[i][j+1]==1){
                c++;
            }
        }
        if(i>0 && j>0){
            if(board[i-1][j-1]==1){
                c++;
            }
        }
        if(i<m-1 && j<n-1){
            if(board[i+1][j+1]==1){
                c++;
            }
        }
        if(i>0 && j<n-1){
            if(board[i-1][j+1]==1){
                c++;
            }
        }
        if(i<m-1 && j>0){
            if(board[i+1][j-1]==1){
                c++;
            }
        }
        if(c<2 || c>3){
            v.push_back({i,j});
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> v;
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==0){
                    deadCondition(board,i,j,v,m,n);
                }
                else{
                    liveCondition(board,i,j,v,m,n);
                }
            }
        }
        for(int k=0;k<v.size();k++){
            int i=v[k][0];
            int j=v[k][1];
            board[i][j]=!board[i][j];
        }
    }
};



class Solution {
public:
    void deadCondition(vector<vector<int>>& board,int i,int j,int m,int n){
        int c=0;
        if(i>0){
            if(abs(board[i-1][j])==1){
                c++;
            }
        }
        if(i<m-1){
            if(abs(board[i+1][j])==1){
                c++;
            }
        }
        if(j>0){
            if(abs(board[i][j-1])==1){
                c++;
            }
        }
        if(j<n-1){
            if(abs(board[i][j+1])==1){
                c++;
            }
        }
        if(i>0 && j>0){
            if(abs(board[i-1][j-1])==1){
                c++;
            }
        }
        if(i<m-1 && j<n-1){
            if(abs(board[i+1][j+1])==1){
                c++;
            }
        }
        if(i>0 && j<n-1){
            if(abs(board[i-1][j+1])==1){
                c++;
            }
        }
        if(i<m-1 && j>0){
            if(abs(board[i+1][j-1])==1){
                c++;
            }
        }
        if(c==3){
            board[i][j]=2;
        }
    }
    void liveCondition(vector<vector<int>>& board,int i,int j,int m,int n){
        int c=0;
        if(i>0){
            if(abs(board[i-1][j])==1){
                c++;
            }
        }
        if(i<m-1){
            if(abs(board[i+1][j])==1){
                c++;
            }
        }
        if(j>0){
            if(abs(board[i][j-1])==1){
                c++;
            }
        }
        if(j<n-1){
            if(abs(board[i][j+1])==1){
                c++;
            }
        }
        if(i>0 && j>0){
            if(abs(board[i-1][j-1])==1){
                c++;
            }
        }
        if(i<m-1 && j<n-1){
            if(abs(board[i+1][j+1])==1){
                c++;
            }
        }
        if(i>0 && j<n-1){
            if(abs(board[i-1][j+1])==1){
                c++;
            }
        }
        if(i<m-1 && j>0){
            if(abs(board[i+1][j-1])==1){
                c++;
            }
        }
        if(c<2 || c>3){
            board[i][j]=-1;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> v;
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==0){
                    deadCondition(board,i,j,m,n);
                }
                else{
                    liveCondition(board,i,j,m,n);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==-1){
                    board[i][j]=0;
                }
                else if(board[i][j]==2){
                    board[i][j]=1;
                }
            }
        }
    }
};
