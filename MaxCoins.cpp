/*
Your are given an 2D integer array  ranges whose length is n where  ranges[i]=[starti,endi,coinsi] means all integers from starti to  endi inclusive starti and endi are present and  we get coinsi amount of coins when we select this ith range . You can select atmost two intervals so as to collect maximum coins but if u select two ranges than those two ranges should not intersect or overlapp than can touch each other.
Note : You can select at max 2 ranges and they should not intersect with each other but they can touch themselves.

Example 1:
Input :
n=3
ranges={{1,3,4},{2,3,5},{3,4,2}}
Output: 7
Explanation:
We can see that we can take 2nd and
3rd ranges as they are not intersecting
(only touching) we get maximum Coins by
taking these ranges(5+2=7).

Example 2:
Input :
n=5
ranges={{1,3,4},{2,3,5},{3,4,2},{5,8,9},{2,8,10}}
Output: 14
Explanation:
We can see that we can take 2nd and
4th ranges as they are not intersecting
we get maximum Coins(5+9=14) by taking
these ranges.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes an integer n(length of ranges) and integer 2D integer array ranges and you have to  return the maximum number of coins which you can get after selecting atmost two ranges which are not intersecting.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(n)
*/

//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
       sort(ranges.begin(),ranges.end(),[&](vector<int> &a, vector<int> &b){
           if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
        });
        vector<int> post(n);
        post[n-1]=ranges[n-1][2];
        for(int i=n-2;i>=0;i--){
            post[i]=max(post[i+1],ranges[i][2]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int low=i, high=n;
            while(low<high-1){
                int mid=low+(high-low)/2;
                if(ranges[mid][0]>=ranges[i][1]) high=mid;
                else low=mid;
            }
            int curr=0;
            if(high<n) curr=post[high];
        ans=max(ans,ranges[i][2]+curr);
        }
    return ans;
    }
};
