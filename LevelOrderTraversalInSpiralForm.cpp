/*
Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.
Example 1:
Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:
Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    if(!root) return {};
    vector<int> result;
    queue<Node*> q;
    q.push(root);
    int flag=1;
    while(!q.empty()){
        vector<int> temp;
        int n=q.size();
        for(int i=0;i<n;i++){
            Node *curr=q.front();
            q.pop();
            temp.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(flag){
            reverse(temp.begin(),temp.end());
            flag=0;
        }else flag=1;
        for(int num : temp){
            result.push_back(num);
        }
    }
    return result;
}
