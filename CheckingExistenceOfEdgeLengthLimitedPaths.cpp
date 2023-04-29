/*
An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.
Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .
Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.

Example 1:
Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
Output: [false,true]
Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.

Example 2:
Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
Output: [true,false]
Exaplanation: The above figure shows the given graph.
*/


class DSU {
    vector<int> par, size;
public:
    DSU(int n) {
        par.resize(n + 1, -1);
        size.resize(n + 1, 1);
    }

    int findPar(int u) {
        return par[u] == -1 ? u : (par[u] = findPar(par[u]));
    }

    bool unite(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if (u == v) return false;
        if (size[u] > size[v]) swap(u, v);
        par[u] = v;
        size[v] += size[u];
        return true;
    }
};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& el, vector<vector<int>>& qs) {
        int len = qs.size();
        vector<bool> ans(len, 0);
        DSU dsu(n);

        auto cmp = [&](vector<int>& a, vector<int>& b) {
            return a[2] <= b[2];
        };

        auto isInSameGrp = [&](int u, int v) {
            return dsu.findPar(u) == dsu.findPar(v);
        };

        for (int i = 0; i < len; i++) qs[i].push_back(i);
        sort(el.begin(), el.end(), cmp);
        sort(qs.begin(), qs.end(), cmp);

        for (int i = 0, j = 0; i < len; i++) {
            while (j < el.size() && el[j][2] < qs[i][2]) dsu.unite(el[j][0], el[j][1]), j++;
            ans[qs[i][3]] = isInSameGrp(qs[i][0], qs[i][1]);
        }
        return ans;
    }
};
