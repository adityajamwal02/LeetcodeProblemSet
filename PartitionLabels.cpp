/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.

Example 1:
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Example 2:
Input: s = "eccbbbbdec"
Output: [10]
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int arr[26]={0};
        int last=0;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']=i;
        }
        int low=0, high=arr[s[low]-'a'];
        while(high<s.size() and low<s.size()){
            high=arr[s[low]-'a'];
            while(low < high){
                if(arr[s[low] - 'a'] > high){
                    high = arr[s[low] - 'a'];
                }
                low++;
            }
            result.push_back(high - last + 1);
            last = high+ 1;
            low++;
        }
        return result;
    }
};
