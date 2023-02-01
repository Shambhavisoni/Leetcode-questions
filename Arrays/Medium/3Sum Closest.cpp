class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int maxx=INT_MIN,minn=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int low=i+1,high=nums.size()-1;
            while(low<high){
                int s=nums[i]+nums[low]+nums[high];
                if(s==target){
                    return s;
                }
                else if(s<target){
                    maxx=max(s,maxx);
                    low++;
                }
                else if(s>target){
                    minn=min(s,minn);
                    high--;
                }
            }
        }
        if(maxx==INT_MIN){
            return minn;
        }
        if(minn==INT_MAX){
            return maxx;
        }
        int d1=abs(target-maxx);
        int d2=abs(target-minn);
        if(d1<d2){
            return maxx;
        }
        return minn;
    }
};
