class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> c;
        unordered_map<int,int> s;
        unordered_map<int,int> e;
        for(int i=0;i<nums.size();i++){
            if(!c.count(nums[i])){
                s[nums[i]]=i;
                e[nums[i]]=i;
            }
            else{
                e[nums[i]]=i;
            }
            c[nums[i]]++;
        }
        int max_no=INT_MIN,min_diff=INT_MAX;
        for(auto i=c.begin();i!=c.end();i++){
            max_no=max(max_no,i->second);
        }
        for(int i=0;i<nums.size();i++){
            if(c[nums[i]]==max_no && min_diff>e[nums[i]]-s[nums[i]]+1){
                min_diff=e[nums[i]]-s[nums[i]]+1;
            }
        }
        return min_diff;
    }
};
