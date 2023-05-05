/*
You are given a root node of a binary Tree and each node of the binary tree is assigned a value and you are also given an integer k and you have to return the count of Good subtrees of this binary Tree . Good subtree is a subtree such that the number of distinct values in this subtree is less than or equal to k.
Note: Subtree of a node consists of that node and all nodes of the subtrees of left and right child  of that node  if they exist .

Example 1:
Input:
k=2
Output: 4
Explanation:
We can see all leaves 3,4,5 form good subtrees as number of distinct values in subtrees is 1 which is less than k which is given as 2,now  subtree which starts at 2 and has 3 as left node  is also a good subtree because the count of distinct values is 2 which is equal to k so overall 4 good subtrees.

Example 2:
Input:
k=1
Output: 4
Explanation:
we can see all leaves 2,2 form good subtrees as number of distinct values in subtrees is 1 which is equal to k which is given as 1, now  both subtrees which starts at 2 and has 2 as child also forms  a good subtree because count of distinct values is 1 which is equal to k so overall 4 good subtrees.
Your Task:
You don't need to read input or print anything. Your task is to complete the function goodSubtrees() which takes root of binary tree  and an integer k respectively and you have to  return the count of good subtrees .

Expected Time Complexity: O(n*k)
Expected Space Complexity: O(n+n*k), where n is the size of recursion stack.
*/


//User function Template for C++

class Solution{
public:
    int counter=0;
    vector<int> helper(Node* root, int k){
        vector<int> record(26,0);
        if(!root) return record;
        record[root->data]++;
        vector<int> leftSide=helper(root->left,k);
        vector<int> rightSide=helper(root->right,k);
        int c=0;
        for(int i=1;i<=25;i++){
            if(leftSide[i]!=0 or rightSide[i]!=0 or record[i]!=0) c++;
            record[i]=record[i]+leftSide[i]+rightSide[i];
        }
        if(c<=k) counter++;
    return record;
    }
    int goodSubtrees(Node *root,int k){
        if(!root) return 0;
        helper(root,k);
    return counter;
    }
};
