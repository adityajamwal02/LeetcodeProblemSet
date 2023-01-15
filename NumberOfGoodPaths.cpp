/*
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.
You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
A good path is a simple path that satisfies the following conditions:
The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.
Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

Example 1:
Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].

Example 2:
Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.

Example 3:
Input: vals = [1], edges = []
Output: 1
Explanation: The tree consists of only one node, so there is one good path.
*/

class Solution {
public:
    int find(vector<int> &y, int i){
        if(i==y[i]) return i;
        y[i]=find(y,y[i]);
        return y[i];
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int m=edges.size(), ans=0;
        vector<vector<int>> x(n);
        vector<int> y(n);
        for(int i=0;i<n;i++){
            y[i]=i;
            x[i]={vals[i], 1};
        }
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
	    	return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
		});
        for(int i=0;i<m;i++){
            int a=find(y,edges[i][0]);
            int b=find(y,edges[i][1]);
            if(x[a][0]!=x[b][0]){
                if(x[a][0]>x[b][0]) y[b]=a;
				else y[a]=b;
            }else{
                y[a]=b;
                ans+=x[a][1]*x[b][1];
                x[b][1]+=x[a][1];
            }
        }
    return ans+n;
    }
};

/// DSU Solution

class UnionFind {
    vector<int> parent,rank;
    int size;
public:
    UnionFind(int n) :size(n){
        parent.resize(n); rank.resize(n);
        for (int i = 0; i < n; i++) // graph nodes 0 to n-1...
            parent[i] = i, rank[i] = 0;
    }
    int findParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]); // Path compression
    }
    bool isConnected(int p, int q) {
        return findParent(p) == findParent(q);
    }
    bool connect(int p, int q) {
           int i = findParent(p), j = findParent(q);
            if (i == j) return false; // already connected...
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                if (rank[i] == rank[j]) rank[j]++;
            }
            --size;
            return true;
        }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), goodPaths = 0;
        vector<vector<int>> adjList(n);
        map<int, vector<int>> sameValues; // nodes having same values... in a single map...

        for (int i = 0; i <n; i++) {
            sameValues[vals[i]].push_back(i);
        }
        for(auto &e: edges){
            int u =e[0], v=e[1];
            if(vals[u]>=vals[v]) adjList[u].push_back(v);
            else adjList[v].push_back(u);
        }
        // till here we prepared adjList and map of val having same nodes...now using union find

        UnionFind uf(n);
        for(auto &[val,nodes]: sameValues){
// now we gonna connect/union the graph value by value...means we pick a value let's say 3.. and we have nodes that have 3 also we have edges that have those nodes.. so we connect like that first...

            for(auto u: nodes){
                for(auto v: adjList[u])
                    uf.connect(u,v);
            }


             unordered_map<int,int> group;
             for(auto u: nodes){
                int p = uf.findParent(u);
                group[p]++;
             }

             goodPaths+=nodes.size(); // each node themselve full fill both the conditions...

             for(auto &g: group){
                int size = g.second;
                goodPaths += (size * (size - 1) / 2);
             }
         }
        return goodPaths;
    }
};
