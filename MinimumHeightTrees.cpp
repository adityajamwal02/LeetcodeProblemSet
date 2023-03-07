/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Example 1:
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

Example 2:
Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
*/

/// DFS Solution

class Solution {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>len;
    int dfs(int curr,vector<int>adj[],int par){
        int ans=0;
        int maxno=0;
        for(int i:adj[curr]){
            if(i==par){
                continue;
            }
            int first=dfs(i,adj,curr);
            maxno=max(maxno,first);
        }
        maxno++;
        mp[curr]=maxno;
        return maxno;
    }
    void dfs2(int node,vector<int>adj[],int par,int piche){
        int maxno=max(mp[node]-1,piche);
        len[node]=maxno;
        maxno=0;
        int minno=0;
        for(int i:adj[node]){
            if(i==par){
                continue;
            }
            int first=mp[i];
            if(first>maxno){
                minno=maxno;
                maxno=first;
            }
            else if(first>minno){
                minno=first;
            }

        }
        for(int i:adj[node]){
            if(i==par){
                continue;
            }
            int temp=mp[i];
            if(maxno==temp){

                int num=piche+1;
                num=max(num,minno+1);
                dfs2(i,adj,node,num);
            }
            else{
                int num=piche+1;
                num=max(num,maxno+1);
                dfs2(i,adj,node,num);
            }
        }
        return;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        //graph done
        dfs(0,adj,-1);
        dfs2(0,adj,-1,0);
        unordered_map<int,vector<int>>res;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            //cout<<len[i]<<endl;
            ans=min(ans,len[i]);
            res[len[i]].push_back(i);
        }
        return res[ans];
    }
};


/// Topological Sort Solution

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        vector<int> result; queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            result.clear();
            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();
                result.push_back(curr);
                for(auto x : adj[curr]){
                    indegree[x]--;
                    if(indegree[x]==1) q.push(x);
                }
            }
        }
    return result;
    }
};
