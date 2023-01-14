/*
There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.
You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.
The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node.
The star sum is the sum of the values of all the nodes present in the star graph.
Given an integer k, return the maximum star sum of a star graph containing at most k edges.

Example 1:
Input: vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
Output: 16
Explanation: The above diagram represents the input graph.
The star graph with the maximum star sum is denoted by blue. It is centered at 3 and includes its neighbors 1 and 4.
It can be shown it is not possible to get a star graph with a sum greater than 16.

Example 2:
Input: vals = [-5], edges = [], k = 0
Output: -5
Explanation: There is only one possible star graph, which is node 0 itself.
Hence, we return -5.
*/

/// Sorting + Hashing

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(k==0){
            int maxi=INT_MIN;
            for(int n:vals)maxi=max(maxi,n);
            return maxi;
        }
        int n=vals.size();
        map<int,vector<pair<int,int>> > adj;
        for(auto p:edges){
            adj[p[0]].push_back({vals[p[1]], p[1]});
            adj[p[1]].push_back({vals[p[0]], p[0],});
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sort(adj[i].rbegin(),adj[i].rend());
            int kk=k;
            int sum=vals[i];
            maxi=max(maxi,sum);
            for(auto p:adj[i]){
                sum+=p.first;
                kk--;
                maxi=max(maxi,sum);
                if(kk==0 || p.first<0)break;
            }
        }
        return maxi;
    }
};

///  Priority_Queue Approach

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(edges.size()==0) return *max_element(vals.begin(), vals.end());
        vector<pair<int, priority_queue<int>>> mp(vals.size());
        for(auto i: edges){
            mp[i[0]].first=vals[i[0]];
            mp[i[0]].second.push(vals[i[1]]);
            mp[i[1]].first=vals[i[1]];
            mp[i[1]].second.push(vals[i[0]]);
        }
        int ans=INT_MIN;
        int index=0;
        for(auto i: mp){
            int temp=i.first;
            if(temp==0) temp=vals[index];
            int x=k;
            ans=max(ans, temp);
            while(!i.second.empty() and x--){
                auto j=i.second.top();
                i.second.pop();
                temp+=j;
                ans=max(ans,temp);
            }
        index++;
        }
        return ans;
    }
};

/// Adj List and Prefix Sum

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<int> adj[n];
        for(int i = 0; i<edges.size(); i++) {
            int s = edges[i][0];
            int d = edges[i][1];
            adj[s].push_back(vals[d]);
            adj[d].push_back(vals[s]);
        }
        int maxVal = INT_MIN;
        for(int i = 0; i<n; i++) {
            sort(adj[i].begin(), adj[i].end(), greater<int>());
            for(int j = 1; j<adj[i].size(); j++) {
                adj[i][j] += adj[i][j-1];
            }
            int j = 0;
            int temp = 0;
            while(j < min(k, (int)adj[i].size()) ) {
                temp = max(temp, adj[i][j]);
                j++;
            }
            maxVal = max({maxVal, temp + vals[i], vals[i]});
        }
        return maxVal;
    }
};
