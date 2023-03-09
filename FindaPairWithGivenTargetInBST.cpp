/*
Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum.

Example 1:

Input:
        2
      /   \
     1     3
sum = 5
Output: 1
Explanation:
Nodes with value 2 and 3 sum up to 5.
Example 2:

Input:
           6
          /
         5
        /
       3
     /  \
    1    4
sum = 2
Output: 0
Explanation:
There's no pair that sums up to 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isPairPresent() that takes a root node and a target value as a parameter and returns 1 if there's a pair of Nodes in the BST with values summing up to the target sum, else returns 0.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).
*/

/*Complete the function below
Node is as follows
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

class BSTIterator{

    stack<Node*> st;
    int reverse=1;
public:

    BSTIterator(Node* root, int isReverse){
        reverse=isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        Node* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
    return temp->data;
    }

    void pushAll(Node* node){
        for(; node!=NULL; ){
            st.push(node);
            if(reverse==1){
                node=node->right;
            }else{
                node=node->left;
            }
        }
    }
};


class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        if(!root) return 0;
        BSTIterator l(root,0);
        BSTIterator r(root,1);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==target) return 1;
            else if(i+j<target) i=l.next();
            else j=r.next();
        }
    return 0;
    }
};
