class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length()<needle.length()){
            return -1;
        }
        int pos,j=0;
        for(int i=0;i<haystack.length();i++){
            if(haystack[i]==needle[j]){
                pos=i;
                int k=i;
                while(j<needle.length() && haystack[k]==needle[j]){
                    j++;
                    k++;
                }
                if(j==needle.length()){
                    return pos;
                }
                else{
                    j=0;
                }
            }
        }
        return -1;
    }
};
