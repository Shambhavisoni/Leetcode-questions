class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // if(nums.size()==1){
        //     return 0;
        // }
        // if(nums[0]>nums[1]){
        //     return 0;
        // }
        // if(nums[nums.size()-1]>nums[nums.size()-2]){
        //     return nums.size()-1;
        // }
        // int i;
        // for(i=1;i<nums.size()-1;i++){
        //     if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
        //         break;
        //     }
        // }
        // return i;

        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2]){
            return nums.size()-1;
        }
        int mid,si=0,ei=nums.size()-1;
        while(si<ei){
            mid=(si+ei)/2;
            if(mid==0 && nums[0]>nums[1]){
                break;
            }
            else if(mid==nums.size()-1 && (nums[nums.size()-1]>nums[nums.size()-2])){
                nums.size()-1;
            }
            if(mid>0 && mid<nums.size()-1){
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    break;
                }
                if(nums[mid]<nums[mid+1]){
                    si=mid+1;
                }
                else if(nums[mid]<nums[mid-1]){
                    ei=mid;
                }
            }
        }
        return mid;
    }
};
