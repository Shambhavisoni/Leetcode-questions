// class Solution {
// public:
//     int helper(vector<int>& cost, int n){
//         if(n==0){
//             return cost[0];
//         }
//         if(n==1){
//             return cost[1];
//         }
//         int ans=cost[n]+min(helper(cost,n-1),helper(cost,n-2));
//         return ans;
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         int ans=min(helper(cost,n-1),helper(cost,n-2));
//         return ans;
//     }
// };

// class Solution {
// public:
//     int helper(vector<int>& cost, int n, vector<int>& arr){
//         if(n==0){
//             return cost[0];
//         }
//         if(n==1){
//             return cost[1];
//         }
//         if(arr[n]!=-1){
//             return arr[n];
//         }
//         int ans=cost[n]+min(helper(cost,n-1,arr),helper(cost,n-2,arr));
//         arr[n]=ans;
//         return arr[n];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int> arr(n,-1);
//         int ans=min(helper(cost,n-1,arr),helper(cost,n-2,arr));
//         return ans;
//     }
// };

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int> arr(n,-1);
//         arr[0]=cost[0];
//         arr[1]=cost[1];
//         for(int i=2;i<n;i++){
//             arr[i]=cost[i]+min(arr[i-1],arr[i-2]);
//         }
//         int ans=min(arr[n-1],arr[n-2]);
//         return ans;   
//     }
// };

// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         // vector<int> arr(n,-1);
//         int oneStep=cost[1];
//         int twoStep=cost[0];
//         int res,res2=cost[n-2];
//         for(int i=2;i<n;i++){
//             res=cost[i]+min(oneStep,twoStep);
//             twoStep=oneStep;
//             oneStep=res;
//             if(i==n-2){
//                 res2=oneStep;
//             }
//         }
//         int ans=min(oneStep,res2);
//         return ans; 
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int oneStep=cost[1];
        int twoStep=cost[0];
        for(int i=2;i<n;i++){
            int res=cost[i]+min(oneStep,twoStep);
            twoStep=oneStep;
            oneStep=res;
        }
        int ans=min(oneStep,twoStep);
        return ans; 
    }
};
