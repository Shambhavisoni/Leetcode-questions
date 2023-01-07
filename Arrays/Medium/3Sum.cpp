/*Approach: By Sorting the array the efficiency of the algorithm can be improved. This efficient approach uses the two-pointer technique. Traverse the array and fix the first element of the triplet. Now use the Two Pointers algorithm to find if there is a pair whose sum is equal to x – array[i]. Two pointers algorithm take linear time so it is better than a nested loop.
Algorithm : 
1. Sort the given array.
2. Loop over the array and fix the first element of the possible triplet, arr[i].
3. Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
4. If the sum is smaller than the required sum, increment the first pointer.
5. Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
6. Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //unordered_map<int,int> m;
        vector<vector<int>> v1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int low=i+1,high=nums.size()-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(sum==0){
                    v1.push_back({nums[i],nums[low],nums[high]});
                    while(low<high && nums[low]==nums[low+1]){
                        low++;
                    }
                    while(low<high && nums[high]==nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }
                
                else if(sum<0){
                    low++;
                }
                else if(sum>0){
                    high--;
                }
                while(i+1<nums.size() && nums[i]==nums[i+1]){
                    i++;
                }
            }
        }
        return v1;
    }
};
