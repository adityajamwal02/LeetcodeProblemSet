/*
You are given a list of strings of the same length words and a string target.
Your task is to form target using the given words under the following rules:
target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
Repeat the process until you form the string target.
Notice that you can use multiple characters from the same string in words provided the conditions above are met.
Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

Example 1:
Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

Example 2:
Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
*/

/// Memoization

class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9+7;

    long long solve(vector<vector<int>> &freq, string &target, int i, int j){
        int len = freq.size();
        if(i >= len){
            if(j >= target.size()) return 1;
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        long long inc = 0, exc = 0;
        if(j < target.size()) inc = (freq[i][target[j]-'a']%mod*solve(freq, target, i+1, j+1)%mod) % mod;
        exc = solve(freq, target, i+1, j)%mod;

        return dp[i][j] = (inc%mod + exc%mod)%mod;
    }

    int numWays(vector<string>& words, string target) {
        int n = words.size(), m=words[0].size();
        vector<vector<int>> freq(m, vector<int>(26, 0));

        for(auto &w : words){
            for(int i=0; i<m; ++i){
                freq[i][w[i]-'a']++;
            }
        }

        memset(dp, -1, sizeof(dp));
        return solve(freq, target, 0, 0);
    }
};


/// Tabulation

class Solution {
public:
    int mod=1e9+7;
    int numWays(vector<string>& words, string target) {
        int n=words[0].size(), m=target.size();
        vector<int> dp(m+1,0);
        vector<vector<int>> count(n,vector<int>(26,0));
        dp[0]=1;
        for(string word : words){
            for(int i=0;i<n;i++){
                count[i][word[i]-'a']++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                dp[j+1]+=(int)((long)dp[j]*count[i][target[j]-'a']%mod);
                dp[j+1]%=mod;
            }
        }
    return dp[m];
    }
};
