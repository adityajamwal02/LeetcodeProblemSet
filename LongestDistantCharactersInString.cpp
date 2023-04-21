/*
Given a string S, find length of the longest substring with all distinct characters.

Example 1:

Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest
substring with all distinct characters.
​Example 2:

Input:
S = "aaa"
Output: 1
Explanation: "a" is the longest substring
with all distinct characters.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestSubstrDitinctChars() which takes the string S as input and returns the length of the longest substring with all distinct characters.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(K), where K is Constant.

*/

int longestSubstrDistinctChars (string S)
{
    int minValue=0;
    int n=S.size(), i=0, j=0;
    unordered_map<char,int> mp;
    while(j<n){
        mp[S[j]]++;
        while(i<j and mp[S[j]]>1){
            mp[S[i]]--;
            i++;
        }
        j++;
    minValue=max(minValue,j-i);
    }
return minValue;
}
