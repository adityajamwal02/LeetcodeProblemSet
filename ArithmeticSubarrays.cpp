/*
A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two
consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.
For example, these are arithmetic sequences:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic:
1, 1, 2, 5, 7
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries,
where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]]
can be rearranged to form an arithmetic sequence, and false otherwise
*/

/// Brute Force Solution

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();i++){
            vector<int> temp;
            bool flag=1;
            for(int j=l[i];j<=r[i];j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            if(temp.size()==2)
                res.push_back(true);
            else{
                int diff=temp[1]-temp[0];
                for(int j=2;j<temp.size();j++){
                    if(temp[j]-temp[j-1]!=diff){
                        flag=0;
                        break;
                    }
                }
            if(flag)
                res.push_back(true);
            else
                res.push_back(false);
            }
        }
    return res;
    }
};

