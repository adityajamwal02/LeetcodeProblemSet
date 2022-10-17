/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.
Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty() and n==1)
            return 1;
        vector<int> out(n+1,0);
        vector<int> in(n+1,0);
        for(auto edge :trust){
            out[edge[0]]++;
            in[edge[1]]++;
        }
        for(int i=0;i<=n;i++){
            if(out[i]==0 and in[i]==n-1)
                return i;
        }
    return -1;
    }
};
