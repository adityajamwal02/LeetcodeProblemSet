/*
Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special node to another special node.
Note: Here special node is a node which is connected to exactly one different node.

Example 1:
Input:
           3
         /    \
       4       5
      /  \
    -10   4
Output: 16
Explanation:
Maximum Sum lies between special node 4 and 5.
4 + 4 + 3 + 5 = 16.

Example 2:
Input:
            -15
         /      \
        5         6
      /  \       / \
    -8    1     3   9
   /  \              \
  2   -3              0
                     / \
                    4  -1
                       /
                     10
Output:  27
Explanation:
The maximum possible sum from one special node
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

Your Task:
You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as input parameter and returns the maximum sum between 2 special nodes.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int helper(Node* node, int &result){
        if(!node) return INT_MIN;
        if(node->left==NULL and node->right==NULL){
            return node->data;
        }
        int left=helper(node->left,result);
        int right=helper(node->right,result);

        if(node->left!=NULL and node->right!=NULL){
            result=max(result,left+right+node->data);
        }

    return max(left,right)+node->data;
    }
    int maxPathSum(Node* root)
    {
        int result=INT_MIN;
        int temp=helper(root,result);
        if(root->left==NULL or root->right==NULL){
            return max(temp,result);
        }
    return result;
    }
};
