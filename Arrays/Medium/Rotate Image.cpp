/*APPROACH 1
1. Reverse every vector in the nested vector.
2. then swap the elements of array arr[i][j] and arr[i+(n-1-i)][j+(n-1-i)] except the case when i+j==n-1 where i is the outer loop and j in the inner one.

Time Complexity: O(N2) where N is the size of the array.
Auxiliary Space: O(1). As a constant space is needed

APPROACH 2
1. reverse whole matrix( matrix[0] is matrix[n-1] and so on).
2. then swap the elements of array arr[i][j] and arr[j][i] where i starts with 0 and j with i+1 and where i is the outer loop and j in the inner one.

Time Complexity: O(N2)  where N is the size of the array.
Auxiliary Space: O(1). As a constant space is needed*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
  
      // void rev(vector<int>& mat){
    //     int i=0,j=mat.size()-1;
    //     while(i<j){
    //         swap(mat[i],mat[j]);
    //         i++;
    //         j--;
    //     }
    // }
    // void rotate(vector<vector<int>>& matrix) {
    //     for(int i=0;i<matrix.size();i++){
    //         rev(matrix[i]);
    //     }
    //     for(int i=0;i<matrix.size();i++){
    //         int x=matrix.size()-1-i;
    //         for(int j=0;j<matrix.size();j++){
    //             if(i+j<matrix.size()-1){
    //                 swap(matrix[i][j],matrix[i+x][j+x]);
    //                 x--;
    //             }
    //         }
    //     }
    // }
};
