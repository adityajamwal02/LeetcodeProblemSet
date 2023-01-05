/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
Example 1:
Input: n = 3
Output: 5
Example 2:
Input: n = 1
Output: 1
*/

/*
Intuition
Total number of binary search tree is sum of number of subtree with each root
Total = bst(root1) + bst(root2) + bst(root3)
F(x) -> gives number of unique bst with x number of nodes
G(y) -> gives number of BST with root elemnt y
Recursive Define G(Y) :
G(y) = number of left subtree with y root * number of right subtree of y as root

x1 = number of nodes in left subtree
Hence F(x1) = number of left subtree with root y
x2 = number of nodes in right subtree
Hence F(x2) = number of right subtree with root y

G(y)= F(x1)*F(x2)

In this Quesition n nodew with value 1 ,2 ,3 , 4

F(n) = G(1) + G(2) + G(3) + G(4) + G(5) +.....+ G(n)
G(1) = F(0) * F(n-1-0)
G(2) = F(1) * F(n-2)
G(3) = F(2) * F(n-3)

F(n)
{
for( int j = 0 ; j < n ; ++j)
{
res += F(j) * F(n-1-j);
}
}

Number of Subtree is only depend on number of nodes
does not depend on wiche are they numbers
e.g 2 node 1,2 or 3,4
number of bst :
1 2 3 4
\ / \ /
2 1 4 3
we can replace by 1,2 by 3,4
BST : one rule to follow
nodes on left subtree are < root->val
nodes on right subtree are > root->val

*/
/// Tabulation

class Solution {
public:
    int numTrees(int n) {
       long long ans=1;
       for(int i=1;i<n;i++){
           ans*=(n+1+i);
           ans/=i;
       }
       ans=ans/n;
    return ans;
    }
};


/// Memoization Code

int rec(int i )
    {
        if( i ==0 ) return 1; // Number of bst 1 nodes present in tree -> 1 
         if(i ==1) return 1; // Number of BST conting 1 node ->1
         
         int res = 0 ; 
          for( int j = 0 ; j < i ; ++j ) 
          res += rec(j)*rec(i-j-1);  // adding number of subtree with root i+1 
          returnres;
    }
