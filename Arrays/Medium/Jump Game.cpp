class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        int i=nums.size()-1;
        int j=nums.size()-2;
        while(j>=0){
            if(j+nums[j]>=i){
                i=j;
                if(i==0){
                    return true;
                }
            }
            j--;
        }
        return false;
    }

    //  if(nums.size()==1){
    //         return true;
    //     }
    //     int j=0,i=0;
    //     while(j<nums.size()-1){
    //         // if(j==nums.size()){
    //         //     return true;
    //         // }
    //         if(nums.size()>1 && nums[i]==0){
    //             return false;
    //         }
    //         if(nums[i]+j<nums.size()){
    //             j+=nums[i];
    //         }
    //         else if(nums[i]+j>=nums.size()){
    //             while(nums[i]>=0 && j>=nums.size()){
    //                 nums[i]--;
    //             }
    //             j+=nums[i];
    //         }
    //         i=j;
    //     }
    //     return true;
};
