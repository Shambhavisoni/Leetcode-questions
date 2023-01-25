class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
        // vector<int> v;
        // priority_queue<int> pq;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[i].size();j++){
        //         v.push_back(matrix[i][j]);
        //     }
        // }
        // for(int i=0;i<k;i++){
        //     pq.push(v[i]);
        // }
        // for(int i=k;i<v.size();i++){
        //     if(v[i]<pq.top()){
        //         pq.push(v[i]);
        //         pq.pop();
        //     }
        // }
        // return pq.top();
    }
};
