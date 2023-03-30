/*
We are given n different types of stickers. Each sticker has a lowercase English word on it.
You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random word

Example 1:
Input: stickers = ["with","example","science"], target = "thehat"
Output: 3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.

Example 2:
Input: stickers = ["notice","possible"], target = "basicbasic"
Output: -1
Explanation:
We cannot form the target "basicbasic" from cutting letters from the given stickers.
*/

class Solution {
public:

    int helper(unordered_map<string,int> &dp, vector<vector<int>> &mp, string target){
        if(target=="") return 0;
        if(dp[target]){
            return dp[target];
        }
        int ans=INT_MAX-1;
        vector<int> temp(26);
        string remainder;
        int m=mp.size();
        for(int i=0;i<m;i++){
            if(mp[i][target[0]-'a']){
                temp=mp[i];
                remainder="";
                for(int j=0;j<target.size();j++){
                    if(temp[target[j]-'a']){
                        temp[target[j]-'a']--;
                    }else{
                        remainder+=target[j];
                    }
                }
            ans=min(ans,1+helper(dp,mp,remainder));
            }
        }
    return dp[target]=ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        int n=stickers.size();
        vector<vector<int>> mp(n, vector<int> (26,0));
        unordered_map<string, int> dp;
        for(int i=0;i<n;i++){
            for(char c: stickers[i]){
                mp[i][c-'a']++;
            }
        }
        dp[""]=0;
        int ans=helper(dp,mp,target);

    return ans==INT_MAX-1 ? -1 : ans;
    }
};
