/*
We run a preorder depth-first search (DFS) on the root of a binary tree.
At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
If a node has only one child, that child is guaranteed to be the left child.
Given the output traversal of this traversal, recover the tree and return its root.

Example 1:
Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

Example 2:
Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Example 3:
Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(string &t, int &index, int val){
        int k=index;
        while(index<t.size() and t[index]>='0' and t[index]<='9'){
            index++;
        }
        TreeNode* root=new TreeNode(stoi(t.substr(k,index)));
        if(index==t.size()) return root;
        //Left Subtree
        k=index;
        while(t[index]=='-')
           index++;
        int count=index-k;
        if(count!=val+1){
            index=k;
            return root;
        }
        else{
            root->left=helper(t,index,count);
            if(index==t.size()) return root;
        }
        //Right Subtree
        k=index;
        while(t[index]=='-')
           index++;
        count=index-k;
        if(count!=val+1){
            index=k;
            return root;
        }
        root->right=helper(t,index,count);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int index=0;
        return helper(traversal, index, 0);
    }
};
