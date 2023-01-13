/*
You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.
You are also given a string s of length n, where s[i] is the character assigned to node i.
Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.

Example 1:
Input: parent = [-1,0,0,1,1,2], s = "abacbe"
Output: 3
Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
It can be proven that there is no longer path that satisfies the conditions.

Example 2:
Input: parent = [-1,0,0,0], s = "aabc"
Output: 3
Explanation: The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.
*/


class Solution {
public:
    int dfs(int node, vector<vector<int>> &graph, string &s, int &ans){
        int max1=0, max2=0;
        for(int i : graph[node]){
            int val=dfs(i, graph, s, ans);
            if(s[i]==s[node]) continue;
            if(val>max1){
                max2=max1;
                max1=val;
            }else if(val>max2){
                max2=val;
            }
        }
        ans=max(ans, max1+max2+1);
    return max1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> graph(n, vector<int>());
        for(int i=1;i<n;i++){
            graph[parent[i]].push_back(i);
        }
        int ans=1;
        dfs(0, graph, s, ans);
    return ans;
    }
};
