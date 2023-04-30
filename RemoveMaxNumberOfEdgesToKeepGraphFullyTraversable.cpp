/*
Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

Example 1:
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

Example 2:
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.

Example 3:
Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
*/

class DSU{
private:
    vector<int> parent;
    int distinct_components;
public:
    DSU(int n){
        distinct_components=n;
        for(int i=0;i<=n;i++){
            parent.push_back(i);
        }
    }
    int findParent(int u){
        if(parent[u]!=u){
            parent[u]=findParent(parent[u]);
        }
    return parent[u];
    }
    bool UnionFind(int u, int v){
        if(findParent(u)==findParent(v)){
            return false;
        }
        parent[findParent(u)]=v;
        distinct_components--;
    return true;
    }
    bool check(){
        return distinct_components == 1;
    }
};

class Solution {
public:
    static const bool comp(vector<int> &it1, vector<int> &it2){
        return it1[0]>it2[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), comp);

        DSU bob(n), alice(n);
        int added_edges=0;
        for(auto it : edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];
            switch(type){
                case 3: {
                    added_edges+=(bob.UnionFind(u,v) and alice.UnionFind(u,v));
                    break;
                }
                case 2: {
                    added_edges+=bob.UnionFind(u,v);
                    break;
                }
                case 1: {
                    added_edges+=alice.UnionFind(u,v);
                    break;
                }
            }
        }
    return (bob.check() and alice.check()) ? edges.size() - added_edges : -1;
    }
};
