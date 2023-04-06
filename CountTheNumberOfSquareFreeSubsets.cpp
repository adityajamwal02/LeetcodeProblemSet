/*
You are given a positive integer 0-indexed array nums.
A subset of the array nums is square-free if the product of its elements is a square-free integer.
A square-free integer is an integer that is divisible by no square number other than 1.
Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.
A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

Example 1:
Input: nums = [3,4,4,5]
Output: 3
Explanation: There are 3 square-free subsets in this example:
- The subset consisting of the 0th element [3]. The product of its elements is 3, which is a square-free integer.
- The subset consisting of the 3rd element [5]. The product of its elements is 5, which is a square-free integer.
- The subset consisting of 0th and 3rd elements [3,5]. The product of its elements is 15, which is a square-free integer.
It can be proven that there are no more than 3 square-free subsets in the given array.

Example 2:
Input: nums = [1]
Output: 1
Explanation: There is 1 square-free subset in this example:
- The subset consisting of the 0th element [1]. The product of its elements is 1, which is a square-free integer.
It can be proven that there is no more than 1 square-free subset in the given array.
*/

class Solution {
public:
    int mod=1e9+7;
    vector<int> prime={2,3,5,7,11,13,17,19,23,29};

    int helper(int n){
        int result=0;
        for(int i=0;i<10;i++){
            int count=0;
            while((n%prime[i])==0){
                count++;
                n=n/prime[i];
            }
            if(count>1) return -1;
            if(count==1) result=result+(1<<i);
        }
    return result;
    }

    int squareFreeSubsets(vector<int>& nums) {
        nums.insert(nums.begin(),0);
        long long res=0, n=nums.size();
        vector<vector<int>> dp(n, vector<int> (1<<10));
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<(1<<10);j++){
                if(nums[i]==1){
                    dp[i][j]=2*dp[i-1][j]%mod;
                    continue;
                }
                dp[i][j]=dp[i-1][j];
                int temp=helper(nums[i]);
                if(temp==-1) continue;
                if((j&temp)==temp){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-temp])%mod;
                }
            }
        }
        for(int i=0;i<(1<<10);i++){
            res=(res+dp[n-1][i])%mod;
        }
    return (res+mod-1)%mod;
    }
};
