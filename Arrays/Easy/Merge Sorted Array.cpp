class Solution {
public:
    // void insertionSort(vector<int>& nums2){
    //     int temp,i,j;
    //     for(int i=1;i<nums2.size();i++){
    //         temp=nums2[i];
    //         for(int j=i-1;j>=0;j++){
    //             if(temp<nums2[j]){
    //                 nums2[j+1]=nums2[j];
    //             }
    //             else if(temp>=nums2[j]){
    //                 nums2[j+1]=temp;
    //                 break;
    //             }
    //         }
    //         if(j==-1){
    //             nums2[0]=temp;
    //         }
    //     }
    // }


    // if(n!=0){
        //     for(int i=0;i<m;i++){
        //         if(n!=0 && nums1[i]>nums2[0]){
        //             swap(nums1[i],nums2[0]);
        //             // if(nums2[0]>nums2[1]){
        //                 sort(nums2.begin(),nums2.end());
        //             // }
        //         }
        //     }
        //     int j=0;
        //     for(int i=m;i<nums2.size()+m;i++){
        //         nums1[i]=nums2[j];
        //         j++;
        //     }
        // }


        // int j=0;
        // for(int i=m;i<nums1.size();i++){
        //     nums1[i]=nums2[j];
        //     j++;
        // }
        // sort(nums1.begin(),nums1.end());
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        int i=m-1,j=n-1,k=(m+n)-1;
        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]){
                nums1[k]=nums2[j];
                j--;
            }
            else{
                nums1[k]=nums1[i];
                i--;
            }
            k--;
        }
        while(j>=0){
            nums1[k]=nums2[j];
            k--;
            j--;
        }
        while(i>=0){
            nums1[k]=nums1[i];
            i--;
            k--;
        }
         
    }
};
