/*1. run a loop from i=0 till i< number of rows
2. initiare the array by 1 
3. Till array's size is less than i(in every iteration) append the sum of pairs of previous row element where sum=v1[i-1][k]+v1[i-1][k+1]. increment k in the while loop
4. as soon as array size becomes = i append 1 again(in beginning and in end)
5. push back the array in the nested array.
6. return the nested array*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v1;
        for(int i=0;i<numRows;i++){
            int k=0;
            vector<int> v;
            v.push_back(1);
            while(v.size()<i){
                int sum=v1[i-1][k]+v1[i-1][k+1];
                v.push_back(sum);
                k++;
            }
            if(v.size()==i){
                v.push_back(1);
            }
            v1.push_back(v);
        }
        return v1;
    }
};
