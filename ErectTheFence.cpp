/*
You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed.
Return the coordinates of trees that are exactly located on the fence perimeter.

Example 1:
Input: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[3,3],[2,4],[4,2]]

Example 2:
Input: points = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
*/


class Solution {
public:
    int checkrightleft(vector<int> A, vector<int> B, vector<int> C) {

        return ((B[0] - A[0]) * (C[1] - A[1])) - ((B[1] - A[1]) * (C[0] - A[0]));
    }


    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 3) return trees;
        sort(trees.begin(), trees.end());

		// Upper HULL
        vector<vector<int>> Uppr_tree;
        Uppr_tree.push_back(trees[0]);
        Uppr_tree.push_back(trees[1]);

        for (int i = 2; i < trees.size(); i++) {
         int ls= Uppr_tree.size();
            while (Uppr_tree.size() >= 2 && checkrightleft(Uppr_tree[ls-2], Uppr_tree[ls-1], trees[i]) > 0) {
                Uppr_tree.pop_back();
              ls--;
            }
            Uppr_tree.push_back(trees[i]);
        }

		// Lower HULL
        vector<vector<int>> rTrees;
        rTrees.push_back(trees[trees.size() - 1]);
        rTrees.push_back(trees[trees.size() - 2]);
        for (int i = trees.size() - 3; i >= 0; --i) {
            int rs = rTrees.size();
            while (rTrees.size() >= 2 && checkrightleft(rTrees[rs-2], rTrees[rs-1], trees[i]) > 0) {
                rTrees.pop_back();
                rs--;
            }
            rTrees.push_back(trees[i]);
        }

		 vector<vector<int>> answer(Uppr_tree.size()+rTrees.size());
        merge(Uppr_tree.begin(),
                   Uppr_tree.end(),
                   rTrees.begin(),
                   rTrees.end(),
                   answer.begin());


        sort(answer.begin(), answer.end());
        answer.erase(std::unique(answer.begin(), answer.end()), answer.end());

        return answer;
    }
};
