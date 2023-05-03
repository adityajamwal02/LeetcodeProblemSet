/*
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets.

Example 1:
Input:
S = "timetopractice"
P = "toc"
Output:
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.

Example 2:
Input:
S = "zoomlazapzo"
P = "oza"
Output:
apzo
Explanation: "apzo" is the smallest
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)
*/

/// Sliding Window + Hashmap

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int n=s.size(), m=p.size();
        if(m>n) return "-1";
        int i=0, j=0, counter=0, minLen=INT_MAX, startIndex=-1;
        int mp1[26]={0}, mp2[26]={0};
        for(int i=0;i<m;i++) {
            mp2[p[i]-'a']++;
        }
        while(j<n){
            mp1[s[j]-'a']++;
            if(mp1[s[j]-'a']<=mp2[s[j]-'a']){
                counter++;
            }
            if(counter==m){
                while(mp1[s[i]-'a'] > mp2[s[i]-'a'] or mp2[s[i]-'a']==0){
                    mp1[s[i]-'a']--;
                    i++;
                }
                int windowSize=j-i+1;
                if(minLen>windowSize){
                    minLen=windowSize;
                    startIndex=i;
                }
            }
        j++;
        }
        if(startIndex==-1) return "-1";
    return s.substr(startIndex,minLen);
    }
};
