class Solution {
public:
    int helper(int* ans,int n){
        if(n<0){
            return 0;
        }
        if(ans[n]!=-1){
            return ans[n];
        }
        int a=helper(ans,n-1);
        int b=helper(ans,n-2);
        ans[n]=a+b;
        return ans[n];
    }
    int climbStairs(int n) {
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(1);
        for(int i=2;i<=n;i++){
            ans.push_back(ans[i-1]+ans[i-2]);
        }
        return ans[n];
    }
};
