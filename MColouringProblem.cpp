/*
Given the maximum occurrences of a, b, and c in a string. Your task is to make the largest length string containing only a, b, and c such that no three consecutive characters are the same. Return the longest possible string length.

Example 1:
Input:
a = 3, b = 3, c = 3
Output:
9
Explanation:
No three consecutive character of
the string "abcabcabc" is same.

Example 2:
Input:
a = 11, b = 2, c = 2
Output:
-1
Explanation:
If we build a string of these character's,
the string will be"aabaacaabaacaaa", here
we can see that there will be three consecutive a. So
there is no solution exist.
Your Task:
You don't need to read input or print anything. Your task is to complete the function solve( ) which takes integers a, b, and c as input parameters and returns the longest possible string length. If there is no possible answer return -1.

Expected Time Complexity: O(a+b+c)
Expected Auxiliary Space: O(1)
*/

class Solution{
public:
    bool isSafe(int node, int color[], bool graph[101][101], int n, int i){
        for(int k=0;k<n;k++){
            if(k!=node and graph[k][node]==1 and color[k]==i){
                return false;
            }
        }
    return true;
    }
    bool solve(int node, int color[], bool graph[101][101], int m, int n){
        if(node==n) return true;
        for(int i=1;i<=m;i++){
            if(isSafe(node, color, graph, n, i)){
                color[node]=i;
                if(solve(node+1,color,graph,m,n)) return true;
                color[node]=0;
            }
        }
    return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n]={0};
        if(solve(0,color,graph,m,n)) return true;
    return false;
    }
};

