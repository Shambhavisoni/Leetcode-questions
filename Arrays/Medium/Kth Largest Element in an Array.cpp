class Solution {
public:
    int partition(vector<int>& nums,int si,int ei){
        int c=0;
        for(int i=si+1;i<=ei;i++){
            if(nums[i]>nums[si]){
                c++;
            }
        }
        swap(nums[si],nums[si+c]);
        int i=si,j=ei;
        while(i<si+c && j>si+c){
            if(nums[i]>nums[si+c]){
                i++;
            }
            else if(nums[j]<=nums[si+c]){
                j--;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        return si+c;
        // int p=nums[si],s=si+1,e=ei;
        // while(s<=e){
        //     if(nums[s]>p){
        //         s++;
        //     }
        //     else if(nums[e]<=p){
        //         e--;
        //     }
        //     else{
        //         swap(nums[s],nums[e]);
        //         s++;
        //         e--;
        //     }
        // }
        // swap(nums[si],nums[e]);
        // return e;
    }  
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1){
            return nums[0];
        }
        int ans,l=0,r=nums.size()-1;
        while(l<=r){
            int c=partition(nums,l,r);
            if(c==k-1){
                ans=nums[c];
                break;
            }
            if(c>k-1){
                r=c-1;
            }
            else{
                l=c+1;
            }
        }
        return ans;
    }
    // priority_queue<int,vector<int>,greater<int>> pq;
        // int i;
        // for(i=0;i<k;i++){
        //     pq.push(nums[i]);
        // }
        // for(;i<nums.size();i++){
        //     if(nums[i]>pq.top()){
        //         pq.push(nums[i]);
        //         pq.pop();
        //     }
        // }
        // return pq.top();
};
