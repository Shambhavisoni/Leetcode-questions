/**/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> v;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         if(nums1[i]==nums2[j]){
        //             v.push_back(nums1[i]);
        //             nums2[j]=INT_MIN;
        //             break;
        //         }
        //     }
        // }
        // return v;


        // vector<int> v;
        // unordered_map<int,int> m;
        // for(int i=0;i<nums1.size();i++){
        //     m[nums1[i]]++;
        // }
        // for(int i=0;i<nums2.size();i++){
        //     if(m[nums2[i]]>0){
        //         v.push_back(nums2[i]);
        //         m[nums2[i]]--;
        //     }
        // }
        // return v;

        vector<int> v;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                v.push_back(nums2[j]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else {
                j++;
            }
        }
        return v;
    }
};
