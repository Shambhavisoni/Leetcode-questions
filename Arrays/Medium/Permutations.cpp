class Solution {
public:
    int fact(int n){
        if(n==0){
            return 1;
        }
        return n * fact(n-1);
    }
    void permutations(vector<vector<int>>& v1,vector<int>& nums){
        if(nums.size()==0){
            v1.push_back(nums);
        }
        for(int i=0;i<nums.size();i++){
            vector<int> v;
            for(int j=0;j<i;j++){
                v.push_back(nums[j]);
            }
            for(int j=i+1;j<nums.size();j++){
                v.push_back(nums[j]);
            }
            
            permutations(v1,v);
            for(int l=0;l<v1.size();l++){
                if(v1[l].size()==v.size()){
                    // int k=0;
                    // while(k<fact(nums.size()-1)){
                        v1[l].push_back(nums[i]);
                    //     k++;
                    // }
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v1;
        vector<int> v;
        permutations(v1,nums);
        return v1;       
    }
};

// class Solution {
// public:
//     void permutations(vector<vector<int>>& v,vector<int>& nums,int si,int ei){
//         if(si==ei){
//             v.push_back(nums);
//             return;
//         }
//         for(int i=si;i<=ei;i++){
//             swap(nums[si],nums[i]);
//             permutations(v,nums,si+1,ei);
//             swap(nums[i],nums[si]);
//         }
//     } 
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> v;
//         permutations(v,nums,0,nums.size()-1);
//         return v;
//     }
// };
