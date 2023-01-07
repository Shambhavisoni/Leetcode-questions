/*Traverse the given array ‘arr’ from left to right. While traversing, maintain count of non-zero elements in array. Let the count be ‘count’. 
For every non-zero element arr[i], put the element at ‘arr[count]’ and increment ‘count’. After complete traversal, 
all non-zero elements have already been shifted to front end and ‘count’ is set as index of first 0. Now all we need to do is run a loop that makes
all elements zero from ‘count’ till end of the array.*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
                c++;
            }
        }
        for(int i=j;i<nums.size();i++){
            nums[i]=0;
        }
    }
};
