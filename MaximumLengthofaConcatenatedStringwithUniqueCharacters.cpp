/*
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
*/

/// Set Recursion approach

class Solution {
public:
    int helper(int index, string temp, vector<string> &arr){
        unordered_set<char> myset(temp.begin(), temp.end());
        if(temp.size()!=myset.size())
            return 0;
        int res=temp.size();
        for(int i=index;i<arr.size();i++)
            res=max(res, helper(i+1,temp+arr[i],arr));

    return res;
    }
    int maxLength(vector<string>& arr) {
        return helper(0,"",arr);
    }
};

/// Frequency Count and Backtracking Method

class Solution {
public:
    int ans=0;
    bool isValid(string s){
        int n=s.size();
        if(n>26)
            return false;
        int freq[26]={0};
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>=2)
                return false;
        }
    return true;
    }
    void maxlength(vector<string> &arr, int i, string s){
        if(s.size()>ans)
            ans=s.size();
        int n=arr.size();
        if(i==n-1)
            return;
        for(int j=i+1;j<n;j++){
            if(isValid(s+arr[j]))
                maxlength(arr,j,s+arr[j]);
        }
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(isValid(arr[i]))
                maxlength(arr,i,arr[i]);
        }
    return ans;
    }
};

