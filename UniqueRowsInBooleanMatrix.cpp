/*
Given a binary matrix your task is to find all unique rows of the given matrix.

Example 1:

Input:
row = 3, col = 4
M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
Output: 1 1 0 1 $1 0 0 1 $
Explanation: Above the matrix of size 3x4
looks like
1 1 0 1
1 0 0 1
1 1 0 1
The two unique rows are 1 1 0 1 and
1 0 0 1 .
Your Task:
You only need to implement the given function uniqueRow(). The function takes three arguments the first argument is a matrix M and the next two arguments are row and col denoting the rows and columns of the matrix. The function should return the list of the unique row of the martrix. Do not read input, instead use the arguments given in the function.

Note: The drivers code print the rows "$" separated.

Expected Time Complexity: O(row * col)
Expected Auxiliary Space: O(row * col)
*/

/// Optimal Solution

class TrieNode {
    public:
    TrieNode* children[2];

    TrieNode() {
        for(int i=0;i<2;i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
    private:
    TrieNode * root;

    public:
    Trie() {
        root = new TrieNode();
    }

    int insert(vector<int> &a) {
        int l = a.size();
        TrieNode * cur = root;

        int flag = 0;
        for(int i=0;i<l;i++) {
            if(cur->children[a[i]]==NULL) {
                cur->children[a[i]] = new TrieNode();
                flag++;
            }
            cur = cur->children[a[i]];
        }
        return flag;
    }
};

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
    vector<vector<int>> given(row, vector<int>(col, 0));
    vector<vector<int>> ans;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            given[i][j] = M[i][j];
        }
    }

    Trie* obj = new Trie();

    for(auto it : given) {
        if(obj->insert(it)>0) {
            ans.push_back(it);
        }
    }
    return ans;
}
