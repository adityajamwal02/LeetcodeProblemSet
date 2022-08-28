/*
You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.
*/

class Solution {
public:
    TreeNode* recur(int start, int end, vector<int> &nums){
        int maxnum=-1;
        int pos=start;
        for(int i=start;i<=end;i++){
             if(nums[i]>maxnum){
                 maxnum=nums[i];
                 pos=i;
             }
        }

        TreeNode* root=new TreeNode(maxnum);
        if(pos-1>=start)
            root->left=recur(start,pos-1,nums);
        if(pos+1<=end)
            root->right=recur(pos+1,end,nums);

    return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return recur(0, nums.size()-1, nums);
    }
};
