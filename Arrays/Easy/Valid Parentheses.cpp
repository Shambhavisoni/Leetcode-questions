lass Solution {
public:
    bool isValid(string s) {
        if(s[0]==']'|| s[0]=='}' || s[0]==')'){
            return false;
        }
        stack<char> s1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['|| s[i]=='{' || s[i]=='('){
                s1.push(s[i]);
            }
            else if(s[i]==']'|| s[i]=='}' || s[i]==')'){
                if(!s1.empty() && s[i]==']'&& s1.top()=='['){
                    s1.pop();
                }
                else if(!s1.empty() && s[i]==')'&& s1.top()=='('){
                    s1.pop();
                }
                else if(!s1.empty() && s[i]=='}'&& s1.top()=='{'){
                    s1.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(s1.empty()){
            return true;
        }
        return false;
        //     if(s[i]=='('){
        //         s1++;
        //     }
        //     else if(s[i]=='{'){
        //         s2++;
        //     }
        //     else if(s[i]=='['){
        //         s3++;
        //     }
        //     else if(s[i]==')'){
        //         s1--;
        //     }
        //     else if(s[i]=='}'){
        //         s2--;
        //     }
        //     else if(s[i]==']'){
        //         s3--;
        //     }
        // }
        // if(s1==0 && s2==0 && s3==0){
        //     return true;
        // }
        // return false;
    }
};
