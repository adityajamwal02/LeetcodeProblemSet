/*
Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list,
so that the concatenation of the two words words[i] + words[j] is a palindrome.

Example 1:
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

Example 2:
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Example 3:
Input: words = ["a",""]
Output: [[0,1],[1,0]]
*/

struct TrieNode{
    TrieNode *child[26]={};
    int currIndex=-1;
    vector<int> wordIndex;
};


class Solution {
public:

    bool isPalindrome(string &s, int i, int j){
        while(i<j)
            if(s[i++]!=s[j--])  return false;

    return true;
    }

    TrieNode* root;

    void insert(string &s, int index){
        TrieNode *curr=root;
        for(int i=s.size()-1;i>=0;i--){
            int c=s[i]-'a';
            if(curr->child[c]==NULL)
                curr->child[c]=new TrieNode();
            if(isPalindrome(s, 0, i))
                curr->wordIndex.push_back(index);
            curr=curr->child[c];
        }
        curr->wordIndex.push_back(index);
        curr->currIndex=index;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        root=new TrieNode();
        for(int i=0;i<words.size();i++){
            insert(words[i], i);
        }
        vector<vector<int>> ans;

        for(int i=0;i<words.size();i++){
            TrieNode *curr=root;
            string &s=words[i];
            for(int j=0;j<s.size();j++){
                if(curr->currIndex!=-1 and curr->currIndex!=i and isPalindrome(s,j,s.size()-1))
                    ans.push_back({i, curr->currIndex});
                curr=curr->child[s[j]-'a'];
                if(curr==NULL)
                    break;
            }
            if(curr==NULL)
                continue;
            for(int j : curr->wordIndex){
                if(i==j)
                    continue;
                ans.push_back({i, j});
            }
        }
    return ans;
    }
};


