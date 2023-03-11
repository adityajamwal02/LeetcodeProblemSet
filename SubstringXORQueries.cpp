/*
You are given a binary string s, and a 2D integer array queries where queries[i] = [firsti, secondi].
For the ith query, find the shortest substring of s whose decimal value, val, yields secondi when bitwise XORed with firsti. In other words, val ^ firsti == secondi.
The answer to the ith query is the endpoints (0-indexed) of the substring [lefti, righti] or [-1, -1] if no such substring exists. If there are multiple answers, choose the one with the minimum lefti.
Return an array ans where ans[i] = [lefti, righti] is the answer to the ith query.
A substring is a contiguous non-empty sequence of characters within a string.

Example 1:
Input: s = "101101", queries = [[0,5],[1,2]]
Output: [[0,2],[2,3]]
Explanation: For the first query the substring in range [0,2] is "101" which has a decimal value of 5, and 5 ^ 0 = 5, hence the answer to the first query is [0,2]. In the second query, the substring in range [2,3] is "11", and has a decimal value of 3, and 3 ^ 1 = 2. So, [2,3] is returned for the second query.

Example 2:
Input: s = "0101", queries = [[12,8]]
Output: [[-1,-1]]
Explanation: In this example there is no substring that answers the query, hence [-1,-1] is returned.

Example 3:
Input: s = "1", queries = [[4,5]]
Output: [[0,0]]
Explanation: For this example, the substring in range [0,0] has a decimal value of 1, and 1 ^ 4 = 5. So, the answer is [0,0].
*/

/// Map and Logic xor_combine

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<vector<int>> result;
        unordered_map<long long, pair<int,int>> mp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(!mp.count(0)){
                    mp[0]=make_pair(i,i);
                }
                continue;
            }
            int m=s.size();
            long long num=0;
            for(int j=i;j<=min(i+32,m-1);j++){
                num=(num<<1)+(s[j]-'0');
                if(!mp.count(num)){
                    mp[num]=make_pair(i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            int temp=queries[i][0]^queries[i][1];
            if(mp.count(temp)){
                result.push_back({mp[temp].first, mp[temp].second});
            }else{
                result.push_back({-1,-1});
            }
        }
    return result;
    }
};
