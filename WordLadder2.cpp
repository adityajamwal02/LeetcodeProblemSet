/*
A transformation sequence from word beginWord to word endWord using a dictionary
wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList,
return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists.
Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

/// Striver Approach Gives TLE on leetcode (BFS+Backtrack)

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
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


/// DFS (TO BACKTRACK) + BFS

class Solution {
public:
    string b;
    vector<vector<string>> ans;
    unordered_map<string,int> m;
    void dfs(string end,vector<string> &seq)
    {
        if(end==b)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
             reverse(seq.begin(),seq.end());
            return;
        }
        int steps=m[end];
        int q=end.size();
        for(int i=0;i<q;i++)
            {
                char temp=end[i];
                for(char p='a';p<='z';p++)
                {
                    end[i]=p;
                    if(m.find(end)!=m.end() && m[end]+1==steps)
                    {
                        seq.push_back(end);
                        dfs(end,seq);
                        seq.pop_back();
                    }
                }
                end[i]=temp;
            }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {

        b=beginWord;
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push({beginWord});
        m[beginWord]=1;
        int sz=beginWord.size();
        s.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front();
            int steps=m[word];
            q.pop();
            if(word==endWord)break;
             for(int i=0;i<sz;i++)
            {
                string temp=word;
                for(char p='a';p<='z';p++)
                {
                    temp[i]=p;
                    if(s.find(temp)!=s.end())
                    {
                        s.erase(temp);
                        q.push({temp});
                        m[temp]=steps+1;
                    }
                }
            }
        }

        if(m.find(endWord)!=m.end())
        {
            vector<string> temp;
            temp.push_back(endWord);
            dfs(endWord,temp);
        }
        return ans;
    }
};
