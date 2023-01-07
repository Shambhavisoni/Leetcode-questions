/*Two Sum using Hashing:
This problem can be solved efficiently by using the technique of hashing. Use a hash_map to check for the current array value x(let), if there exists a value target_sum-x which on adding to the former gives target_sum. This can be done in constant time.

Illustration:

arr[] = {0, -1, 2, -3, 1} 
sum = -2 
Now start traversing: 
Step 1: For ‘0’ there is no valid number ‘-2’ so store ‘0’ in hash_map. 
Step 2: For ‘-1’ there is no valid number ‘-1’ so store ‘-1’ in hash_map. 
Step 3: For ‘2’ there is no valid number ‘-4’ so store ‘2’ in hash_map. 
Step 4: For ‘-3’ there is no valid number ‘1’ so store ‘-3’ in hash_map. 
Step 5: For ‘1’ there is a valid number ‘-3’ so answer is 1, -3 

Follow the steps below to solve the problem:

1. Initialize an empty hash table s.
2. Do the following for each element A[i] in A[] 
3. If s[x – A[i]] is set then print the pair (A[i], x – A[i])
4. Insert A[i] into s.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int next=target-nums[i];
            if(m.count(next)){
                v.push_back(i);
                v.push_back(m[next]);
                break;
            }
            m[nums[i]]=i;
        }
        return v;
        
    }
};

/*Time Complexity: O(N), As the whole array is needed to be traversed only once.
Auxiliary Space: O(N), A hash map has been used to store array elements.*/
