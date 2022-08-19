//Largest BST in Binary Tree

class Node{
    int maxNode,minNode,maxSize;

    Node(int minNode,maxNode,maxSize){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
    }
};

class Solution{
private:
    Node largestBST(TreeNode* root){
        if(!root)
            return Node(INT_MAX,INT_MIN,0);

        auto left=largestBST(root->left);
        auto right=largestBST(root->right);

        if(left.maxNode<root->val and root->val<right.minNode){
            return Node(min(root->val,left.minNode), max(root->val,maxNode),left.maxSize+right.maxSize+1);
        }
        return Node(INT_MIN, INT_MAX,max(left.maxSize,right.maxSize));
    }
public:
    int largestBSTsubtree(TreeNode* root){
        return largestBSTsubtree(root).maxSize;
    }
};
