/***An efficient approach using binary search: **
1. For the first occurrence of a number 

a) If (high >= low)
b) Calculate  mid = low + (high – low)/2;
c) If ((mid == 0 || x > arr[mid-1]) && arr[mid] == x)
        return mid;
d) Else if (x > arr[mid])
       return first(arr, (mid + 1), high, x, n);
e) Else
       return first(arr, low, (mid -1), x, n);
f) Otherwise return -1;

2. For the last occurrence of a number 

a) if (high >= low)
b) calculate mid = low + (high – low)/2;
c)if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
        return mid;
d) else if(x < arr[mid])
       return last(arr, low, (mid -1), x, n);
e) else
      return last(arr, (mid + 1), high, x, n);      
f) otherwise return -1;

Time Complexity: O(log n) 
Auxiliary Space: O(1)

 **An Iterative Implementation of Binary Search Solution :**
 
For the first occurrence, we will first find the index of the number and then search again in the left subarray as long as we are finding the number.
 
For the last occurrence, we will first find the index of the number and then search again in the right subarray as long as we are finding the number

First occurrence: 

1. Do while low <= high:
2. First, find the mid element
3. Check if the arr[mid] > x then the first element will occur on the left side of mid. So, bring the high pointer to mid – 1
4. Check if the arr[mid] < x then the first element will occur on the right side of mid. So, bring the low pointer to mid + 1
5. If arr[mid] == x then this may be the first element. So, update the result to mid and move the high pointer to mid – 1.
6. Return the result.

Last occurrence: 

1. Do while low <= high:
2. First, find the mid element.
3. Check if the arr[mid] > x then the last element will occur on the left side of mid. So, bring the low pointer to mid – 1
4. Check if the arr[mid] < x then the last element will occur on the right side of mid. So, bring the low pointer to mid + 1
5. If arr[mid] == x then this may be the last element. So, update the result to mid and move the low pointer to mid + 1.
6. Finally, Return the result.

Time Complexity: O(log n) 
Auxiliary Space: O(1) */

class Solution {
public:
    int first(vector<int>& nums,int low, int high,int n,int target){
        int res=-1;
        while(low<=high){
            int mid=(low + high)/ 2;
            if(target>nums[mid]){
                low=mid+1;
            }
            else if(target<nums[mid]){
                high=mid-1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
    int last(vector<int>& nums,int low, int high,int n, int target){
        int res=-1;
        while(low<=high){
            int mid=(low + high)/ 2;
            if(target>nums[mid]){
                low=mid+1;
            }
            else if(target<nums[mid]){
                high=mid-1;
            }
            else{
                res=mid;
                low=mid+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> v;
         int l=first(nums,0,nums.size()-1,nums.size(),target);
         int h=last(nums,0,nums.size()-1,nums.size(),target);
         v.push_back(l);
         v.push_back(h);
         return v;
    }


    // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         if(start==-1){
        //             start=i;
        //             end=i;
        //         }
        //         else{
        //             end=i;
        //         }   
        //     }
        // }
        // v.push_back(start);
        // v.push_back(end);
        // return v;
};
