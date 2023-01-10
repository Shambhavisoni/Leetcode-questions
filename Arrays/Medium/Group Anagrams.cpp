/*1. Make a hashmap where key is the sorted string and value is a vector of its anagrams.
2. iterate through the map and push back the map value in the resultant array.
3. return the resultant array.
TC:
SC:
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> v;
        for(int i=0;i<strs.size();i++){
            string ogString=strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(ogString);
        }
        for(auto i=m.begin();i!=m.end();i++){
            v.push_back(i->second);
        }
        return v;
    }
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     return s==t;
    // }
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> v1;
    //     for(int i=0;i<strs.size();i++){
    //         vector<string> v;
    //             if(strs[i]!="-1"){
    //                  v.push_back(strs[i]);
    //                 for(int j=i+1;j<strs.size();j++){
    //                     bool check = isAnagram(strs[i],strs[j]);
    //                     if(check){
    //                         v.push_back(strs[j]);
    //                         strs[j]="-1";
    //                     }
    //                 }
    //                 v1.push_back(v);
    //             }
    //     }
    //     return v1;
    // }
};
