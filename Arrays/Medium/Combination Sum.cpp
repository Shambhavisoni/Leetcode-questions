class Solution {
public:
    void helper(int i, vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& res){
        if(i==candidates.size()){
            if(target==0){
                res.push_back(ans);
            }
            return;
        }
        if(target>=candidates[i]){
            ans.push_back(candidates[i]);
            helper(i,candidates,target-candidates[i],ans,res);
            ans.pop_back();
        }
        helper(i+1,candidates,target,ans,res);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(0,candidates,target,ans,res);
        return res;
    }
};
