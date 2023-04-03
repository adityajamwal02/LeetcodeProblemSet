/*
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other.
Note:-
If the strings are anagrams you have to return True or else return False
|s| represents the length of string s.

Example 1:
Input:a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same characters with
        same frequency. So, both are anagrams.

Example 2:
Input:a = allergy, b = allergic
Output: NO
Explanation: Characters in both the strings are
        not same, so they are not anagrams.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isAnagram() which takes the string a and string b as input parameter and check if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.

Expected Time Complexity:O(|a|+|b|).
Expected Auxiliary Space: O(Number of distinct characters).
*/

/// Sorting

bool isAnagram(string a, string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b){
            return true;
        }else{
            return false;
        }


/// Mapping

class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        if(a.size()!=b.size()) return false;
        map<char,int> mp;
        for(char c : a){
            mp[c]++;
        }
        for(char c : b){
            mp[c]--;
        }
        for(auto it : mp){
            if(it.second!=0){
                return false;
            }
        }
    return true;
    }

};

/// Hashing

vector<int>v(26,0);

    for(int i=0;i<a.size();i++)
    {
        v[a[i]-'a']++;
    }

    for(int i=0;i<b.size();i++)
    {
        v[b[i]-'a']--;
    }

    for(int i=0;i<26;i++)
    {
        if(v[i]!=0)
        return false;
    }

    return true;

    }
