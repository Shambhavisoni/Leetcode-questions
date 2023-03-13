class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int n=nums.size()-1;
        while(!pq.empty()){
            nums[n]=pq.top();
            pq.pop();
            n--;
        }
        return nums;
    }
};
