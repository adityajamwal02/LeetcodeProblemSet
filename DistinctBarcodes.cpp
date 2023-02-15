/*
In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

Example 1:
Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]

Example 2:
Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
*/


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()<=1) return barcodes;

        vector<int> result;
        unordered_map<int, int> mp;
        for(auto it : barcodes){
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        while(pq.top().first>0){
            pair<int,int> p1=pq.top();
            pq.pop();
            result.push_back(p1.second);
            p1.first--;
            pair<int,int> p2=pq.top();
            pq.pop();
            if(p2.first>0){
                result.push_back(p2.second);
                p2.first--;
            }
            pq.push(p1);
            pq.push(p2);
        }
    return result;
    }
};
