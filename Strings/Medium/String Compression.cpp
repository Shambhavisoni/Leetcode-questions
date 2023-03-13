class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        int j=0;
        for(int i=0;i<chars.size();i++){
            int c=1;
            while(i<chars.size()-1 && chars[i]==chars[i+1]){
                c++;
                i++;
            }
            chars[j]=chars[i];
            j++;
            if(c>1){
                string len=to_string(c);
                for(auto i:len){
                    chars[j]=i;
                    j++;
                }
            }
        }
        return j;

        
        // vector<char> v1;
        // v1.push_back(chars[0]);
        // int c=1;
        // for(int i=1;i<chars.size();i++){
        //     if(chars[i-1]==chars[i]){
        //         c++;
        //     }
        //     else{
        //         if(c>1){
        //             string s=to_string(c);
        //             for(auto j:s){
        //                 v1.push_back(char(j));
        //             }
        //         }
        //         v1.push_back(chars[i]);
        //         c=1;
        //     }
        // }
        // if(c>1){
        //     string s=to_string(c);
        //     for(auto j:s){
        //         v1.push_back(char(j));
        //     }
        // }
        // chars=v1;
        // return v1.size();
    }
};
