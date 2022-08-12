/*

You are given an array nums consisting of non-negative integers.
You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi.
In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
*/

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit]=node;
    }
};

class Trie
{
    Node * root;

public:
    Trie()
    {
        root=new Node();
    }

    void insert(int num)
    {
        Node * node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node=node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node * node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxNum=maxNum|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int i=0;
        sort(nums.begin(), nums.end());
        int q=queries.size();
        int n=nums.size();
        vector<pair<int, pair<int, int>>> offlineQueries;
        for(auto &it: queries){
            offlineQueries.push_back({it[1], {it[0], i++}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        vector<int> ans(q, 0);
        int index=0;
        for(auto &it: offlineQueries){
            while(index<n and nums[index]<=it.first){
                trie.insert(nums[index]);
                index++;
            }
            if(index==0)
                ans[it.second.second]=-1;
            else
                ans[it.second.second]=trie.getMax(it.second.first);
        }
    return ans;
    }
};

