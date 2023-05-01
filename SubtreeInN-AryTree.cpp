/*
Given root of a n-ary tree find the number of duplicate subtree in the n-ary tree.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:

Input:
1 N 2 2 3 N 4 N 4 4 3 N N N N N

Output: 2
Explanation: [4], [3] are duplicate subtree.
Example 2:

Input:
1 N 2 3 N 4 5 6 N N N N

Output: 0
Explanation: No duplicate subtree found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function duplicateSubtreeNaryTree() which takes root of n-ary tree as input, and return an integer value as number of duplicate subtrees.
*/

//User function Template for C++

class Solution{
public:
    unordered_map<string,int> mp;

    string helper(Node* root){
        if(root->children.size()==0){
            string str=to_string(root->data);
            mp[str]++;
            return str;
        }
        vector<Node*> temp=root->children;
        sort(temp.begin(), temp.end(), [](Node* left, Node* right){
            return left->data < right->data;
        });
        string result="";
        bool first=true;
        for(auto child : temp){
            string curr=helper(child);
            result+="("+curr+")";
        }
        result+=to_string(root->data);
        mp[result]++;
    return result;
    }

    int duplicateSubtreeNaryTree(Node *root){
        if(!root) return 0;
        helper(root);
        int counter=0;
        for(auto it : mp){
            if(it.second > 1){
                counter++;
            }
        }
    return counter;
    }
};
