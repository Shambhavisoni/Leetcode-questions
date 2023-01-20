class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(size(nums),1);
        for(int i=1;i<nums.size();i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int p=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=p;
            p*=nums[i];
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> v;
//         int c=0,p=1,p0=1;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=0){
//                 p0*=nums[i];
//             }
//             p*=nums[i];
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0){
//                 c++;
//             }
//         }
//         if(c>1){
//             for(int i=0;i<nums.size();i++){
//                 v.push_back(0);
//             }
//         }
//         else if(c==1){
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]==0){
//                     v.push_back(p0);
//                 }
//                 else{
//                     v.push_back(0);
//                 }
//             }
//         }
//         else{
//             for(int i=0;i<nums.size();i++){
//                 v.push_back(p/nums[i]);
//             }
//         }
//         return v;
//     }
// };

// vector<int> ans;
//         int* left = new int[sizeof(int) * nums.size()];
//         int* right = new int[sizeof(int) * nums.size()];
//         int l=1,r=1;
//         left[0]=1;
//         for(int i=0;i<nums.size()-1;i++){
//             l*=nums[i];
//             left[i+1]=l;
//         }
//         right[nums.size()-1]=1;
//         for(int i=nums.size()-1;i>=0;i--){
//             r*=nums[i];
//             right[i-1]=r;
//         }
//         for(int i=0;i<nums.size();i++){
//             ans.push_back(left[i]*right[i]);
//         }
//         return ans;

// class Solution {
// public:
//     vector<int> helper(vector<int>& nums,int si,int ei,vector<int>& v){
//         if(si>ei){
//             return v;
//         }
//         int p=1,n=nums.size();
//         for(int i=0;i<n;i++){
//             if(i!=si){
//                 p*=nums[i];
//             }
//         }
//         v.push_back(p);
//         helper(nums,si+1,ei,v);
//         return v;
//     }
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> v;
//         int n=nums.size();
//         return helper(nums,0,n-1,v);
//     }
// };

// vector<int> v;
//         int n=nums.size(),p=1;
//         for(int i=0;i<n;i++){
//             p=1;
//             for(int j=0;j<n;j++){
//                 if(i!=j){
//                     p*=nums[j];
//                 }
//             }
//             v.push_back(p);
//         }
//         return v;
