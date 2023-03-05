/*
You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
Note that two nodes are on the same level if they have the same distance from the root.

Example 1:
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.

Example 2:
Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
*/


int kthLargestLevelSum(TreeNode* root, int k) {
    if (!root) return -1;

    unordered_map<int, long long> levelSum;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        TreeNode* node = curr.first;
        int level = curr.second;
        levelSum[level] += node->val;
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (auto& pair : levelSum) {
        pq.push(pair.second);
        if (pq.size() > k) pq.pop();
    }

    return pq.size() == k ? pq.top() : -1;
}
