/*
You are given a Binary Search Tree and a target value. You must find the maximum difference between the sum of node data from root to target and from target to a child leaf node (target exclusive). Initially, you are at the root node.
Note: If the target node is not present in the tree then return -1.

Example 1:
Input:
Target = 20
Output: 10
Explanation: From root to target the sum of node data is 25 and from target to the children leaf nodes the sums of the node data are 15 and 25. So, the maximum difference will be (25-15) = 10.

Example 2:
Input:
Target = 50
Output: -1
Explanation: The target node is not present in the tree.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxDifferenceBST() which takes BST(you are given the root node of the BST ) and target as input, and returns an interger value as the required answer. If the target is not present in the BST then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(H), H - Height of the Tree.
*/


//User function Template for C++

class Solution{
    vector<Node*> targetNodes;
    int maxSumToTarget=INT_MIN, minSumToLeaf=INT_MAX;

public:

    void findMax2(Node* root, int target, int &sum){
        if(!root) return;
        sum+=root->data;
        if(!root->left and !root->right){
            minSumToLeaf=min(minSumToLeaf, sum);
        }
        findMax2(root->left,target,sum);
        findMax2(root->right,target,sum);
        sum-=root->data;
    }

    void findMax1(Node* root, int target, int &sum){
        if(!root) return;
        if(root->data==target){
            targetNodes.push_back(root);
            maxSumToTarget=max(maxSumToTarget,sum);
        }
        sum+=root->data;
        findMax1(root->left,target,sum);
        findMax1(root->right,target,sum);
        sum-=root->data;
    }

    int maxDifferenceBST(Node *root,int target){
        int sum=0;
        findMax1(root,target,sum);
        if(maxSumToTarget==INT_MIN) return -1;
        sum=0;
        for(auto node : targetNodes){
            findMax2(node->left,target,sum);
            sum=0;
            findMax2(node->right,target,sum);
            sum=0;
        }
        if(minSumToLeaf==INT_MAX) return maxSumToTarget;
    return maxSumToTarget-minSumToLeaf;
    }
};
