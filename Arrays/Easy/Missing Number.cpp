/***Approach 1: USing Cyclic Sort**
1. Use cyclic sort to sort the array whenever numbers in array are pesent in the range [1,n]
2. then check if ith index have i as element or not
3. if not, return the element
4. Else when loop ends return the last element of array.

**Time Complexity: O(N)
Auxiliary Space: O(1)***

**Approach 2 (Using summation of first N natural numbers): The idea behind the approach is to use the summation of the first N numbers. **                                                                                                    
 Follow the steps mentioned below to implement the idea:

1. Calculate the sum of the first N natural numbers as sumtotal= N*(N+1)/2.
2. Traverse the array from start to end.
3. Find the sum of all the array elements.
4. Print the missing number as SumTotal – sum of array   

**Time Complexity: O(N)
Auxiliary Space: O(1)***

**Approach 3 (Using Hashing):** The idea behind the following approach is

The numbers will be in the range (1, N), an array of size N can be maintained to keep record of the elements present in the given array

1. Create a temp array temp[] of size n + 1 with all initial values as 0.
2. Traverse the input array arr[], and do following for each arr[i] 
3. if(temp[arr[i]] == 0) temp[arr[i]] = 1 
4. Traverse temp[] and output the array element having value as 0 (This is the missing element).       
**Time Complexity: O(N)
Auxiliary Space: O(N)***

**Approach 4 (Using binary operations):** This method uses the technique of XOR to solve the problem.  

XOR has certain properties 

Assume a1 ⊕ a2 ⊕ a3 ⊕ . . . ⊕ an = a and a1 ⊕ a2 ⊕ a3 ⊕ . . . ⊕ an-1 = b
Then a ⊕ b = an
Follow the steps mentioned below to implement the idea:

1. Create two variables a = 0 and b = 0
2. Run a loop from i = 1 to N:
3. For every index, update a as a = a ^ i
4. Now traverse the array from i = start to end.
5. For every index, update b as b = b ^ arr[i].
6. The missing number is a ^ b

**Time Complexity: O(N)
Auxiliary Space: O(1)****/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=i){
        //         return i;
        //     }
        // }
        // return nums.size();

        // int x1=0,x2=0;
        // for(int i=0;i<nums.size();i++){
        //     x1 ^= nums[i];
        // }
        // for(int i=0;i<=nums.size();i++){
        //     x2 ^= i;
        // }
        // return x1^x2;

        
        int i=0;
        while(i<nums.size()){
            int correct=nums[i];
            if(nums[i]<nums.size() && nums[i]!=nums[correct]){
                swap(nums[i],nums[correct]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return nums.size();
    }
};
