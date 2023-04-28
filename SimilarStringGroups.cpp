/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?



Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1
*/


/// DFS + Check

class Solution {
public:
    void dfs(int i, int n, vector<string> &strs, vector<int> &vis){
        vis[i]=1;
        for(int j=0;j<n;j++){
            if(vis[j]) continue;
            if(isSimilar(strs[i],strs[j])){
                dfs(j,n,strs,vis);
            }
        }
    }

    bool isSimilar(string a, string b){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) count++;
        }
        return (count==2 or count==0);
    }

    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size(), result=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            result++;
            dfs(i,n,strs,vis);
        }
    return result;
    }
};
