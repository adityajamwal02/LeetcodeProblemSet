/*
Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

Note: Here's the Output of every Node printed in the Pre-Order tree traversal format. Arrange nodes in the answer array based on the lexicographically incresing order of their preorder traversal of subtree.
For Example: if we have 3 preorder traversal as {1,2,3},{1},{11,2,3} than your lexicographically increasing order is {1},{1,2,3},{11,2,3}, you are supposed to output the head of all these subtrees in the same order.

Example:

Input :

Output : 2 4
         4
Explanation: Above Trees are two
duplicate subtrees.i.e  and
Therefore,you need to return above trees
root in the form of a list.
Your Task:
You don't need to take input. Just complete the function printAllDups() that takes the root node as a parameter and returns an array of Node*, which contains all the duplicate subtree.


*/


//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

string helper(Node* node, unordered_map<string,int> &mp, vector<Node*> &result){
    if(!node) return "#";
    string left=helper(node->left,mp,result);
    string right=helper(node->right,mp,result);
    string s = left + "," + right + "," + to_string(node->data);
    if(mp[s]==1) result.push_back(node);
    mp[s]++;
return s;
}
vector<Node*> printAllDups(Node* root)
{
    vector<Node*> result;
    unordered_map<string,int> mp;
    helper(root, mp, result);

    return result;
}
