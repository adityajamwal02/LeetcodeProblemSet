/*
You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
Return the length of the maximum length awesome substring of s.

Example 1:
Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.

Example 2:
Input: s = "12345678"
Output: 1

Example 3:
Input: s = "213123"
Output: 6
Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
*/


/// BitMasking

class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();
        int result=1, mask=0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            int digit=s[i]-'0';
            int p=1<<digit;
            mask^=p;
            if(mp.count(mask)==0){
                mp[mask]=i;
            }else{
                result=max(result,i-mp[mask]);
            }

            if(mask&(mask-1)==0){
                result=max(result,i+1);
            }

            for(int j=0;j<10;j++){
                int nmask=mask^(1<<j);
                if(mp.count(nmask)){
                    result=max(result,i-mp[nmask]);
                }
            }
        }
    return result;
    }
};
