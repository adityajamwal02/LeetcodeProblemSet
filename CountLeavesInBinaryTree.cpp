/*
Given a Binary Tree of size N, You have to count leaves in it. For example, there are two leaves in following tree

        1
     /      \
   10      39
  /
5



Example 1:


Input:
Given Tree is
               4
             /   \
            8     10
           /     /   \
          7     5     1
         /
        3
Output:
3
Explanation:
Three leaves are 3 , 5 and 1.


Your Task:
You don't have to take input. Complete the function countLeaves() that takes root node of the given tree as parameter and returns the count of leaves in tree. The printing is done by the driver code.

*/



//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \
   20       30 */

int helper(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL){
        return 1;
    }
    int l=helper(root->left);
    int r=helper(root->right);

return l+r;
}

int countLeaves(Node* root)
{
    return helper(root);
}
