/*
Given a string str and another string patt. Find the minimum index of the character in str that is also present in patt.

Example 1:
Input:
str = geeksforgeeks
patt = set
Output: 1
Explanation: e is the character which is
present in given str "geeksforgeeks"
and is also presen in patt "set". Minimum
index of e is 1.

Example 2:
Input:
str = adcffaet
patt = onkl
Output: -1
Explanation: There are none of the
characters which is common in patt
and str.

Your Task:
You only need to complete the function minIndexChar() that returns the index of answer in str or returns -1 in case no character of patt is present in str.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
*/

/// map find approach

//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        unordered_map<char,int> mp;
        mp[str[0]]=0;
        int minIndex=INT_MAX;
        for(int i=1;i<str.size();i++){
            if(mp[str[i]]==0 and str[i]!=str[0]){
                mp[str[i]]=i;
            }
        }
        for(int i=0;i<patt.size();i++){
            if(mp.find(patt[i])==mp.end()) continue;
            if(mp.find(patt[i])!=mp.end() or mp[patt[i]]!=0){
                minIndex=min(minIndex,mp[patt[i]]);
            }
        }
        if(minIndex==INT_MAX) return -1;
    return minIndex;
    }
};
