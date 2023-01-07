/***Method 1: (Using extra space) **

1. Create an auxiliary array temp[] to store unique elements.
2. Traverse input array and one by one copy unique elements of arr[] to temp[]. Also keep track of count of     unique elements. Let this count be j.
3. Copy j elements from temp[] to arr[] and return j

**Time Complexity : O(n) 
Auxiliary Space : O(n)**

**Method 2: (Constant extra space)**

Just maintain a separate index for same array as maintained for different array in Method 1.

**Time Complexity : O(n) 
Auxiliary Space : O(1)***/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j=0;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[j]=nums[i];
                j++;
            }

        }
        nums[j]=nums[i];
        j++;
        return j;
    }

};
