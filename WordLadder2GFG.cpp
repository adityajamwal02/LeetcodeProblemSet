/*
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here.


Example 1:

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
Example 2:

Input:
startWord = "gedk", targetWord = "geek",
wordList = {"geek", "gefk"}
Output:
"gedk" -> "geek"

Your Task:
You don't need to read or print anything, Your task is to complete the function findSequences() which takes startWord, targetWord and wordList as input parameter and returns a list of list of strings of the shortest transformation sequence from startWord to targetWord.
Note: You don't have to return -1 in case of no possible sequence. Just return the Empty List.


Expected Time Compelxity: O(N*(logN * M * 26))
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|
*/


//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> curr;
        curr.push_back(beginWord);
        int level=0;
        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();
            if(vec.size()>level){
                level++;
                for(auto it: curr){
                    st.erase(it);
                }
            }
            string word=vec.back();
            if(word==endWord){
                if(result.size()==0){
                    result.push_back(vec);
                }else if(result[0].size()==vec.size()){
                    result.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        curr.push_back(word);
                        vec.pop_back();
                    }
                }
            word[i]=original;
            }
        }
    return result;
    }
};


