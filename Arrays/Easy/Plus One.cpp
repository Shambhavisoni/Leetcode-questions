/*1.  traverse through the array in reverse order.
2.  if the bumber is greater less 9, simply add 1 to it and return the array
3.  If the number is greater than or equal to 9, replace that element by 0
4.  after the loop ends, push back 0 to the array and replce 0th index by 1(this is done because the array is not returned till now this mean that the first number is also 9 . Eg: 99 +1 =100)

Time Complexity: O(n), where n is the size of the array.
Auxiliary Space: O(1)*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i]=0;
            }
        }
        digits.push_back(0);
        digits[0]=1;
        return digits;
    }
};
