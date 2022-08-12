/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

*/


struct Node{
    Node * links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node *get(int bit){
        return links[bit];
    }
    void put(int bit, Node *node){
        links[bit]=node;
    }
};


class Solution {
    Node *root;
public:
    Solution(){
        root=new Node();
    }

    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
                node->put(bit, new Node());

            node=node->get(bit);
        }
    }

    int getMax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum=maxNum|(1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }

    int findMaximumXOR(vector<int>& nums) {
        int m=nums.size()-1;
        for(auto &it : nums)
            insert(it);
        int maxi=0;
        for(auto &itr : nums)
            maxi=max(maxi, getMax(itr));

    return maxi;
    }
};
