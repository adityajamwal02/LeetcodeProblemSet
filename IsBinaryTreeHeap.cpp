/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
*/

/// Use Level Order Traversal

class Solution {
  public:
    bool isHeap(struct Node* tree) {
        // code here
        if(tree==NULL) return true;

        queue<struct Node*> q;
        q.push(tree);

        bool seen = false;
        while(!q.empty()){
            struct Node*temp = q.front();
            q.pop();
            if(temp->left)
            {
                if(seen || temp->left->data>temp->data) return false;
                q.push(temp->left);
            }else
            seen = true;

            if(temp->right)
            {
                if(seen || temp->right->data>temp->data) return false;
                q.push(temp->right);
            }else
            seen =true;
        }
        return true;

    }
};
