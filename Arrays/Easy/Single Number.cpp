/*We can use sorting to do it in O(nLogn) time. We can also use hashing, it has the worst-case time complexity of O(n), but requires extra space.
The idea is to use bitwise operators for a solution that is O(n) time and uses O(1) extra space. The solution is not easy like other XOR-based solutions, 
because all elements appear an odd number of times here. The idea is taken from here.*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x = x ^ nums[i];
        }
        return x;
    }

    // int singleNumber(vector<int>& nums) {
    //     int x=0;
    //     for(int i=0;i<nums.size();i++){
    //         x = x ^ nums[i];
    //     }
    //     return x;

    // }
    // TC: O(n)
    // SC: O(1)


    //  int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> m;
    //     for(int i=0;i<nums.size();i++){
    //        m[nums[i]]++;
    //     }
    //     return x;
    //     int i;
    //     for(i=0;i<nums.size();i++){
    //         if( m[nums[i]]==1){
    //             break;
    //         }
    //     }
    //     return nums[i];
    // }
    // TC: O(n)
    // SC: O(n)
};
