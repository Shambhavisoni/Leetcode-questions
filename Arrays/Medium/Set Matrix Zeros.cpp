class Solution {
public:
    void allZeros(vector<vector<int>>& matrix,int i,int j,int m,int n){
        int row=0,col=0;
        while(row<n){
            matrix[i][row]=0;
            row++;
        }
        while(col<m){
            matrix[col][j]=0;
            col++;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> indices;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    indices.push_back({i,j});
                }
            }
        }
        for(int i=0;i<indices.size();i++){
            allZeros(matrix,indices[i][0],indices[i][1],m,n);
        }
    }
};
