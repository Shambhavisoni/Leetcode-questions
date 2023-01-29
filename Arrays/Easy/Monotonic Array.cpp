class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<=1){
            return true;
        }
        int i=0;
        while(i<nums.size()-1 && nums[i]==nums[i+1]){
            i++;
        }
        if(i<nums.size()-1 && nums[i]<=nums[i+1]){
           for(int j=i+1;j<nums.size();j++){
               if(nums[j-1]>nums[j]){
                   return false;
               }
            }
        }
        else if(i<nums.size()-1 && nums[i]>=nums[i+1]){

           for(int j=i+1;j<nums.size();j++){

               if(nums[j-1]<nums[j]){

                   return false;

               }

            }
        }
       return true;
    }
};
