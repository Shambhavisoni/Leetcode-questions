class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        unordered_map<int,int>m;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        unordered_map<int,int>:: iterator it=m.begin();
        int i;
        for(i=0;i<k;i++){
            if(it!=m.end()){
                pq.push(it->second);
            }
            it++;
        }
        while(it!=m.end()){
            if(pq.top()<it->second){
                pq.push(it->second);
                pq.pop();
            }
            it++;
        }
        while(!pq.empty()){
            for(auto j=m.begin();j!=m.end();j++){
                if(!pq.empty() && j->second==pq.top()){
                    v.push_back(j->first);
                    pq.pop();
                    m.erase(j);
                    break;
                }
            }
        }
        
        return v;
    }
};
