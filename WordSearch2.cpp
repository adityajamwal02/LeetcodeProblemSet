/*
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
*/

class Solution {
public:
    vector<vector<int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
    struct Trie{
        Trie* links[26];
    };
    Trie *makenode(){
        Trie* node=new Trie();
        for(int i=0;i<26;i++){
            node->links[i]=NULL;
        }
        return  node;
    }
    bool query(Trie* root, string s){
        Trie* temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->links[s[i]-'a']){
                temp = temp->links[s[i]-'a'];
            }else{
                return false;
            }
        }
        return true;
    }
    void dfs(Trie* root, int i, int j, int index, int n, int m, int &mx, vector<vector<char>>& board, vector<vector<bool>>&vis){
        if(i<0 or j<0 or i>=n or j>=m or index==mx or vis[i][j]){
            return;
        }
        vis[i][j]=true;
        if(!root->links[board[i][j]-'a']){
            root->links[board[i][j]-'a'] = makenode();
        }
        root=root->links[board[i][j]-'a'];
        for(int l=0;l<4;l++){
            dfs(root,i+dir[l][0],j+dir[l][1],index+1,n,m,mx,board,vis);
        }
        vis[i][j]=false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        int mx=0;
        for(auto word : words){
            mx=max(mx,(int)(word.size()));
        }
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        Trie* root=new Trie();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(root,i,j,0,n,m,mx,board,vis);
            }
        }
        vector<string> ans;
        for(auto word : words){
            if(query(root, word)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};
