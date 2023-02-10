/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

Example 1:
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

Example 2:
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<routes.size();i++){
            for(auto stop : routes[i]){
                mp[stop].push_back(i);
            }
        }
        vector<bool> bus(routes.size());
        queue<int> q;
        int ans=0;
        for(auto taken : mp[source]){
            bus[taken]=1;
            q.push(taken);
        }
        while(!q.empty()){
            ans++;
            for(int i=q.size();i>0;i--){
                int curr=q.front();
                q.pop();
                for(auto route : routes[curr]){
                    if(route==target) return ans;
                    for(int j=0;j<mp[route].size();j++){
                        if(!bus[mp[route][j]]){
                            bus[mp[route][j]]=1;
                            q.push(mp[route][j]);
                        }
                    }
                }
            }
        }
    return -1;
    }
};

