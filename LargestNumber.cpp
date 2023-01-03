/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"
*/

/// Custom sort


class Solution {
public:
    struct{
        bool operator()(string &a, string &b){
        string res1=a+b;
        string res2=b+a;
        for(int i=0;i<res1.size();i++){
            if(res1[i]<res2[i]){
                return false;
            }else if(res1[i]>res2[i]){
                return true;
                }
            }
        return false;
        }
    }comparator;

    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int x: nums){
            str.push_back(to_string(x));
        }
        sort(str.begin(), str.end(), comparator);
        if(str[0]=="0"){
            return "0";
        }
        string res="";
        for(string s: str){
            res+=s;
        }
    return res;
    }
};


/// Selection Sort


