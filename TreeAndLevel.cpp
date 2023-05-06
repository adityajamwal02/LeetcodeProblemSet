/*
Given a tree with N nodes rooted at 1. Each node labeled with a value arr[i]. The task is to find the absolute difference between the sum of values of nodes at even level and odd level

Note: All the nodes are numbered from 1 to N.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains a single integer N.
3. The next line contains N space-separated positive integers represents the node value.
4. Next N-1 lines contain two space-separated integers u and v, represents an edge in between them


Output: For each test case, print the answer


Constraints:
1. 1 <= T <= 5
2. 1 <= N <= 105
3. 1 <= arr[i] <= 105
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int,vector<int>> adj;
        for(int i=1;i<=n-1;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int even=0, odd=0;
        queue<pair<int,int>> q;
        q.push({1,1});
        vector<int> vis(n,0);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it.second==1)
                odd+=arr[it.first-1];
            else
                even+=arr[it.first-1];
            vis[it.first-1]=1;
            int flag=1;
            if(it.second==1) flag=2;
            for(int j : adj[it.first]){
                if(vis[j-1]==0) q.push({j,flag});
            }
        }
    cout<<abs(even-odd)<<endl;
    }
	return 0;
}
