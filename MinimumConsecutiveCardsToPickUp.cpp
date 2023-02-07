/*
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

Example 1:
Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.

Example 2:
Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,vector<int>> mp;
        int n=cards.size(), ans=INT_MAX;
        for(int i=0;i<n;i++){
            mp[cards[i]].push_back(i);
        }
        for(auto iter: mp){
            if(iter.second.size()>1){
                int temp=INT_MAX;
                for(int j=0;j<iter.second.size()-1;j++){
                    temp=min(temp, iter.second[j+1] - iter.second[j] + 1);
                }
                ans=min(ans, temp);
            }
        }
    return (ans==INT_MAX) ? -1 : ans;
    }
};
