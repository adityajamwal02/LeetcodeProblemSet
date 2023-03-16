/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/


class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
    return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            int height=envelopes[i][1];
            if(height>temp.back()){
                temp.push_back(height);
            }else{
                auto it = lower_bound(temp.begin(),temp.end(),height);
                *it=height;
            }
        }
    return temp.size();
    }
};
