/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, return any of them.
It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 4, denominator = 333
Output: "0.(012)"
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if((numerator<0 and denominator>0) or (numerator>0 and denominator<0)){
            result+='-';
        }
        numerator=abs(numerator);
        denominator=abs(denominator);
        long long quotient = numerator/denominator;
        long long remainder = numerator%denominator;
        result+=to_string(quotient);
        if(!remainder) return result;
        result+=".";
        map<int, map<int,int>> mp;
        int index=0, start_index=-1;
        bool flag=false;
        string after_point;
        while(remainder){
            remainder*=10;
            long long temp=remainder/denominator;
            if(mp[temp][remainder]){
                flag=true;
                start_index=mp[temp][remainder];
                break;
            }else{
                after_point+=to_string(temp);
                mp[temp][remainder]=index++;
            }
            remainder=remainder%denominator;
        }
        if(!flag){
            result+=after_point;
        }else{
            for(int i=0;i<after_point.size();i++){
                if(i==start_index) result+='(';
                result+=after_point[i];
            }
            result+=')';
        }
    return result;
    }
};t
