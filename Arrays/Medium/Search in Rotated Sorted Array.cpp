
/** We calculate the mid value as mid = (l + h) / 2
* Then try to figure out if l to mid is sorted, or (mid+1) to h is sorted
* Based on that decide the next search region and keep on doing this till the element is found or l  overcomes h.


1. Use a recursive function/while loop to implement binary search to find the key:
2. Find middle-point mid = (l + h)/2 
3. If the key is present at the middle point, return mid.
4. Else if the value at l is less than the one at mid then arr[l . . . mid] is sorted
5. If the key to be searched lies in the range from arr[l] to arr[mid], recur for arr[l . . . mid]/h=mid-1.
6. Else recur for arr[mid+1 . . . h]/l=mid+1  
7. Else arr[mid+1. . . h] is sorted: 
8. If the key to be searched lies in the range from arr[mid+1] to arr[h], recur for arr[mid+1. . . h]/l=mid+1.
9. Else recur for arr[l. . . mid]/ h=mid-1.

Time Complexity: O(log N). Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
Auxiliary Space: O(1). As no extra space is required.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int i=0;
        // bool found=false;
        // for(i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         found =true;
        //         break;
        //     }
        // }
        // if(found){
        //     return i;
        // }
        // return -1;


    //     int max_elem=INT_MIN,max_index=0;
    //     for(int i=0;i<nums.size();i++){
    //        if(max_elem<nums[i]){
    //            max_elem=nums[i];
    //            max_index=i;
    //        }
    //     }
    //     int k=(nums.size()-1)-max_index;
    //     sort(nums.begin(),nums.end());
    //     int x=-1,diff=nums.size()-k;
    //     for(int i=0;i<nums.size();i++){
    //         if(target==nums[i]){
    //             if(i<k){
    //                 x=i+diff;
    //             }
    //             else{
    //                 x=i-k;
    //             }
    //         }
    //     }
    //     return x;
    // }

    int low=0, high=nums.size()-1,mid;
    while(low<high){
        mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>=nums[low]){
            if(target>=nums[low] && target<nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target>nums[mid] && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    if(nums[low]==target){
        return low;
    }
    return -1;
    }
};
