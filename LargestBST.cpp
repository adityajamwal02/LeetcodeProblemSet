/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:
Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.

Example 2:
Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2
Output: 2
Explanation: The following sub-tree is a
BST of size 2:
       2
    /    \
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).
*/

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST

    pair<pair<int,int>,int> solve(Node *root){
        if(!root){
            pair<pair<int,int>,int> p;
            p.first.first=INT_MIN;
            p.first.second=INT_MAX;
            p.second=0;
            return p;
        }
        if(!root->left and !root->right){
            pair<pair<int,int>,int> p;
            p.first.first=root->data;
            p.first.second=root->data;
            p.second=1;
            return p;
        }

        auto lh=solve(root->left);
        auto rh=solve(root->right);
        pair<pair<int,int>,int> p;

        if(lh.first.first < root->data and rh.first.second > root->data){
            p.first.first=max(rh.first.first, root->data);
            p.first.second=min(lh.first.second, root->data);
            p.second=1+lh.second+rh.second;
        }else{
            p.first.first=INT_MAX;
            p.first.second=INT_MIN;
            p.second=max(lh.second,rh.second);
        }
    return p;
    }


    int largestBst(Node *root)
    {
        auto ans = solve(root);

    return ans.second;
    }
};


