/*1. Traverse through the array
2. check if the ith element is there in the map or not.
3. If present return True
4. else store that element in the map*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                return true;
            }
            m[nums[i]]=1;
        }
        return false;
    }
};
