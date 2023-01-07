/***Naive Solution:  **

*Approach: The idea is quite simple and involves checking every pair of boundaries or array element and find out the maximum area under any pair of boundaries.*

Algorithm: 
1. Create a nested loop, the outer loop traverses the array from 0 to end (index of this loop is i).
2. The inner loop traverses the array from i + 1 to end (index of this loop is j).
3. Find the water that can be contained in the container with height of boundaries as array[i] and array[j], i.e     area = (j – i)* min(array[i],array[j]), if this area is greater than current maximum, update the current maximum
4. Print the current maximum.

**Complexity Analysis:** 

**Time Complexity:** O(n^2). 
As nested traversal of the array is required, so time complexity is O(n^2)
**Space Complexity:** O(1). 
As no extra space is required, so space complexity is constant.**


**Efficient Solution:**  

*Approach: *Given an array of heights of lines of boundaries of the container, find the maximum water that can be stored in a container. So start with the first and last element and check the amount of water that can be contained and store that container. Now the question arises is there any better boundaries or lines that can contain maximum water. So there is a clever way to find that. Initially, there are two indices the first and last index pointing to the first and the last element (which acts as boundaries of the container), if the value of first index is less than the value of last index increase the first index else decrease the last index. As the decrease in width is constant, by following the above process the optimal answer can be reached.
The GIF below explains the approach

Algorithm: 
1. Keep two index, first = 0 and last = n-1 and a value max_area that stores the maximum area.
2. Run a loop until first is less than the last.
3. Update the max_area with maximum of max_area and min(array[first] , array[last])*(last-first)
   if the value at array[first] is greater the array[last] then update last as last – 1 else update first as first+1.
4. Print the maximum area.

**Complexity Analysis: **

**Time Complexity:** O(n). 
As only one traversal of the array is required, so time complexity is O(n).
**Space Complexity:** O(1). 
No extra space is required, so space complexity is constant.***/

class Solution {
public:
    int maxArea(vector<int>& height) {
        // int max_area=INT_MIN;
        // for(int i=0;i<height.size();i++){
        //     for(int j=0;j<height.size();j++){
        //         max_area=max(max_area,(min(height[i],height[j])*(j-i)));
        //     }
        // }
        // return max_area;

        int i=0,j=height.size()-1,max_area=INT_MIN;
        while(i<j){
            // max_area=max(max_area,(min(height[i],height[j])*(j-i)));
            int area=(j-i)*min(height[i],height[j]);
            max_area=max(max_area,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return max_area;
    }
};
