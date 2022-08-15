/*
Given the root of a binary tree, the value of a target node target, and an integer k,
return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level++ ==k) break;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left and !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right and !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent[curr] and !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            result.push_back(curr->val);
        }

    return result;
    }
};
