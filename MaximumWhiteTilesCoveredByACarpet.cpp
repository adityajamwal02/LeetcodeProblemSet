/*
You are given a 2D integer array tiles where tiles[i] = [li, ri] represents that every tile j in the range li <= j <= ri is colored white.
You are also given an integer carpetLen, the length of a single carpet that can be placed anywhere.
Return the maximum number of white tiles that can be covered by the carpet.

Example 1:
Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
Output: 9
Explanation: Place the carpet starting on tile 10.
It covers 9 white tiles, so we return 9.
Note that there may be other places where the carpet covers 9 white tiles.
It can be shown that the carpet cannot cover more than 9 white tiles.

Example 2:
Input: tiles = [[10,11],[1,1]], carpetLen = 2
Output: 2
Explanation: Place the carpet starting on tile 10.
It covers 2 white tiles, so we return 2.
*/

class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end());
    int n = tiles.size();
    int prefix[n + 1], et[n];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
      et[i] = tiles[i][1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int start = tiles[i][0];
      int end = start + carpetLen - 1;
      int indx = upper_bound(et, et + n, end) - et;
      int tsum = prefix[indx] - prefix[i];
      if (indx < n and end >= tiles[indx][0]) tsum += end - tiles[indx][0] + 1;
      ans = max(ans, tsum);
    }
    return ans;
  }
};
