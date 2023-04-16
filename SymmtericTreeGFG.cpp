/*
Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: True
Explanation: Tree is mirror image of
itself i.e. tree is symmetric
Example 2:

Input:
         5
       /   \
      10     10
     /  \     \
    20  20     30
Output: False
Your Task:
You don't need to read input or print anything. Your task is to complete the function isSymmetric() which takes the root of the Binary Tree as its input and returns True if the given Binary Tree is the same as the Mirror image of itself. Else, it returns False.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0<=Number of nodes<=100
*/

/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not

    bool helper(Node* node1, Node* node2){
        if(node1==NULL and node2==NULL) return true;
        if(node1==NULL or node2==NULL) return false;
        if(node1->data!=node2->data) return false;
        if(!helper(node1->left,node2->right) or !helper(node1->right,node2->left)) return false;
    return true;
    }

    bool isSymmetric(struct Node* root)
    {
        if(!root) return true;

	    return helper(root->left, root->right);
    }
};

