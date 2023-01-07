/***APPROACH 1: BRUTE-FORCE**
For every element , check its frequency in the array. Store the maximum_frequency_till_now in a variable and update it once you find out the frequency of each element.
This approach involves nested loops :

1. Run a loop on the array.
2. In , the above loop run another loop on the array and count the frequency of the current element of the above array.
3. After calculating the frequency of current_element , update the maximum_frequency variable.
**TC : O(N^2)
SC : O(1)****


**APPROACH 2: USING HASHMAPS (UNORDERED_MAPS)**
Whenever , there is a question involving the calculation of frequency , hashmaps and frequency arrays come handy.
In this approach as well , we will :

1. Evaluate the frequency of each element by storing it in a hashmap.
2. Then we will traverse the hashmap and return the element with maximum frequency.

**TC : O(N)
SC : O(N)

**APPROACH 3 : USING SORTING**
1. Sort the array .
2. Return the element at (N/2 + 1)th position (or (N/2)th index).

**TC : O(NlogN)
SC : O(1)**

**APPROACH 4 : MOORE'S VOTING ALGORITHM**
Think of this array as a collection of votes from the voters for different political parties.
Now as we know the party which has >50% votes can form the government.

So , our above question is analogous to this situation.
Now , if we are certain that one party has > 50% votes . Then , if :

We increment a count variable every time we see the vote from the majority party and decrement it whenever a vote from some other party is occured , we can guarantee that ,
count>0.

Using the above logic ,

1. Create a count=0 and a majority variable that stores the current majority element.
2. Traverse the array , and if count =0 , then store the current element as the majority element and increment the count.
3. Else , if the current element is equal to the current majority element , increment count , else decrement it.
4. At the end return the majority element.

This approach works because ,

We simply know that the majority element has a frequency greater than half of the total elements.
So , the value of count > 0.
But whenever it becomes 0 , it means that till now the majority element has either not occured , or if it has then the its frequency is equal to the sum of frequency of rest of the others. So , the next element will be the majority element till now . But eventually by the end , the final answer will always be the majority element of the array , as when the "count" becomes 0 for the final time , the next element will be the majority element.

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
        // int c=1,i;
        // for(i=0;i<nums.size()-1;i++){
        //     if(nums[i]!=nums[i+1]){
        //         c=1;
        //     }
        //     else{
        //         c++;
        //         if(c>nums.size()/2){
        //             break;
        //         }
        //     }
        // }
        // return nums[i];

        int major,c=0;
        for(int i=0;i<nums.size();i++){
           
        }
    }
};
