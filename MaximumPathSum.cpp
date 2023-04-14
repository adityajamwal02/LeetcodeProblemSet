/*
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Example 1:
Input:
     10
    /  \
   2   -25
  / \  /  \
 20 1  3  4
Output: 32
Explanation: Path in the given tree goes
like 10 , 2 , 20 which gives the max
sum as 32.

Example 2:
Input:
     10
   /    \
  2      5
          \
          -2
Output: 17
Explanation: Path in the given tree goes
like 2 , 10 , 5 which gives the max sum
as 17.
Your Task:
You don't need to take input or print anything. Your task is to complete the function findMaxSum() that takes root as input and returns max sum between any two nodes in the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

*/

/// From any node to any node

// User Fuction template for C++

class Solution {
  public:

    int helper(Node* node, int &result){
        if(!node) return 0;

        int left=helper(node->left,result);
        int right=helper(node->right,result);

        int temp=max(max(left,right)+node->data, node->data);
        int ans=max(temp,left+right+node->data);

        result=max(result,ans);

    return temp;
    }

    int findMaxSum(Node* root)
    {
        int result=INT_MIN;
        helper(root,result);
    return result;
    }
};
