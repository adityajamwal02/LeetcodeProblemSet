/*
Given a binary tree and a target, find the length of minimum sub-tree with the given sum equal to target which is also a binary search tree.

Example 1:

Input:
           13
         /    \
       5       23
      / \      / \
     N   17   N   N
         /
        16
Target: 38
Output: 3
Explanation: 5,17,16 is the smallest subtree
with length 3.


Example 2:

Input:
             7
           /   \
          N    23
             /   \
            10    23
           /  \   / \
          N   17 N   N
Target: 73
Output: -1
Explanation: No subtree is bst for the given target.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minSubtreeSumBST() which takes the tree root and target as input parameters and returns length of largest subtree having sum equal to the target which is also a binary search tree.

Expected Time Complexity:O(n)
Expected Space Complexity:O(1)
*/

//User function Template for C++

class Solution {
public:

    int get(Node* root, int &count){
        if(!root) return 0;
        count++;
        int l=get(root->left,count);
        int r=get(root->right,count);

    return (root->data + l + r);
    }

    void isBST(Node* node, vector<int> &v){
        if(!node) return ;
        isBST(node->left,v);
        v.push_back(node->data);
        isBST(node->right,v);
    }

    bool check(vector<int> v){
        for(int i=0;i<v.size();i++){
            if(v[i-1]>=v[i]) return 0;
        }
    return 1;
    }

    void solve(Node* root, int target, int &result){
        if(!root) return;
        int count=0;
        int s=get(root,count);
        if(s==target){
            vector<int> v;
            isBST(root,v);
            bool flag=check(v);
            if(flag){
                result=min(result,count);
            }
        }
        solve(root->left,target,result);
        solve(root->right,target,result);
    }

    int minSubtreeSumBST(int target, Node *root) {
        int result=INT_MAX;
        solve(root,target,result);
        if(result==INT_MAX) return -1;

    return result;
    }
};
