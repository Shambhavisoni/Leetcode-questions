/*1. Two Sum
Easy

40562

1303

Add to List

Share
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.*/


//APPROACH 1: BRUTE FORCE
//Go through each element of the array and try to find out an element in whole array with whom its sum is equal to target
//time complexity: O(n^2)
//space complexity: 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j){
                    continue;
                }
                else if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }            
            }
            if(v.size()!=0)
                break;
        }
         return v;
    }
};

//APPROACH 2: USING HASHMAPS
//calculate the element with whom ith index elem will sum up to target. Make a hashmap(key: value;; element: index)
//and check if the element to be found is there in the hashmap or not. If present push back value of that key and also push back ith index and return the array.
//if not present in hashmap add that ith index element as key and its index as value
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++){
        int findNum=target-nums[i];
        if(m.count(findNum)!=0){
            v.push_back(m[findNum]);
            v.push_back(i);
            return v;
        }
        m[nums[i]]=i;
    }
                    return v;
    }
