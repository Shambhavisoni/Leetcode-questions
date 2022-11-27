/*13. Roman to Integer
Easy

8149

476

Add to List

Share
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999]*/

//FIRST APPROACH
// 1. create a map with char as key and integer value
// 2. refer to the map and keep adding to the num
// 3. but be careful in certain cases as mentioned in the question.
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int num=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='I' && i!=s.length()-1 && (s[i+1]=='V' || s[i+1]=='X')){
                if(s[i+1]=='V'){
                    num+=4;
                }
                else
                    num+=9;
                i++;
            }
            else if(s[i]=='X' && i!=s.length()-1 && (s[i+1]=='L' || s[i+1]=='C')){
                if(s[i+1]=='L'){
                    num+=40;
                }
                else
                    num+=90;
                i++;
            }
            else if(s[i]=='C' && i!=s.length()-1 && (s[i+1]=='D' || s[i+1]=='M')){
                if(s[i+1]=='D'){
                    num+=400;
                }
                else
                    num+=900;
                i++;
            }
            else{
                num+=m[s[i]];
            }
        }
        return num;
    }
};


// SECOND APPROACH
// 1. create a map with char as key and integer value as value check if current element is greater than or less than next element
// 2. if curr elem < next elem sum=sum+curr elem integer value from map
// 3. else num=num-curr elem integer value from map.
// 4. after end of loop add last elem integer value to num amd return num
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int num=0;
        for(int i=0;i<s.length()-1;i++){
            if(m[s[i]]<m[s[i+1]]){
                num-=m[s[i]];
            }
            else{
                num+=m[s[i]];
            }
        }
        num+=m[s.back()];
        return num;
    }
};
