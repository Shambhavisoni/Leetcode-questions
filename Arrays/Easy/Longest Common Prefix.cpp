class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==0){
            return strs[0];
        }
        int mini=INT_MAX,j=0,kmin=INT_MAX;
        string s="";
        for(int i=0;i<strs.size();i++){
            if(mini>strs[i].size()){
                mini=strs[i].size();
                s=strs[i];
            } 
        }
        for(int i=0;i<strs.size();i++){
            if(s==strs[i]){
                continue;
            }
            else{
                j=0;
                while(j<mini && strs[i][j]==s[j]){
                    j++;
                }
                kmin=min(kmin,j);
            }
        }
        return s.substr(0,kmin);
    //    for(int i=0;i<kmin;i++){
    //        result+=s[i];
    //    }
    //    return result;
    }
};
