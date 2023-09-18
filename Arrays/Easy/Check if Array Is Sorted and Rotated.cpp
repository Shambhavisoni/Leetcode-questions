class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> idx;
        int mini=*min_element(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            if(nums[i]==mini){
                idx.push_back(i);
            }
        }

       
        int minEle=mini;

        for(int j=0;j<idx.size();j++){
            int i=(idx[j]+1)%n;
            mini=minEle;
            bool flag=true;
            while(i != idx[j]){
                if(nums[i]<mini){
                    flag=false;
                    break;
                }
                mini=nums[i];
                i=(i+1)%n;
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};
// *************************************************************
/*Intuition
We need to find how many times, the array is breaking the ascending order. If it is breaking just once then it or it does't break even once then it is sorted. So we can return true. Otherwise false.

Approach
There could be three cases where we can return true --

1. The given array is properly sorted. Ex- [1,2,5,6,9]

In this case the ascending order does not breaks inside the array. So cnt=0 , But when we check the last element and the first element, cnt becomes 1.👇

if(nums[n-1]>nums[0]){
            cnt++;
        }
2. The given array is sorted but rotated. Ex- [5,6,9,1,2]

In this case the ascending order breaks inside the array, So cnt becomes 1. But nums[n-1]<nums[0] So cnt doesn't increases. So cnt=1👇

int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
3. All the values of array are equal. Ex- [1,1,1,1]

In this case the ascending doesn't breaks in the array. And nums[n-1]==nums[0] . So cnt=0

So while returning if the cnt <= 1 then it will return true otherwise false.

Complexity
Time complexity:
O(N)

Space complexity:
O(1)*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(), cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;
    }
};
