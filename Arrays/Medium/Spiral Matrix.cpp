class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int rs=0,cs=0,ce=matrix[0].size()-1,re=matrix.size()-1;
        while(rs<=re || cs<=ce){
            int i=cs;
            while(i<=ce){
                v.push_back(matrix[rs][i]);
                i++;
            }
            rs++;
            if(rs>re || cs>ce){
                break;
            }
            i=rs;
            while(i<=re){
                v.push_back(matrix[i][ce]);
                i++;
            }
            ce--;
            if(rs>re || cs>ce){
                break;
            }
            i=ce;
            while(i>=cs){
                v.push_back(matrix[re][i]);
                i--;
            }
            re--;
            if(rs>re || cs>ce){
                break;
            }
            i=re;
            while(i>=rs){
                v.push_back(matrix[i][cs]);
                i--;
            }
            cs++;
        }
        return v;
    }
};
