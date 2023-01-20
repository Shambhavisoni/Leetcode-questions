class Solution {
public:
    void helper(vector<int>& nums,vector<int>& temp,int si,vector<vector<int>>& res){
        if(si==nums.size()){
            res.push_back(temp);
            return;
        }
            temp.push_back(nums[si]);
            helper(nums,temp,si+1,res);

            temp.pop_back();
            helper(nums,temp,si+1,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(nums,temp,0,res);
        return res;
    }
};
