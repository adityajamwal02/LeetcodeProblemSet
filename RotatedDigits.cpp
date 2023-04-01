/*
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.
A number is valid if each digit remains a digit after rotation. For example:
0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].

Example 1:
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

Example 2:
Input: n = 1
Output: 0

Example 3:
Input: n = 2
Output: 1
*/

/// Easy Solution

class Solution {
public:
    int rotatedDigits(int n) {
        int counter=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            bool flag=0;
            for(auto i : s){
                if(i=='3' or i=='4' or i=='7'){
                    flag=0; break;
                }
                if(i=='2' or i=='5' or i=='6' or i=='9'){
                    flag=1;
                }
            }
            if(flag){
                counter++;
            }
        }
    return counter;
    }
};

/// DP Solution

class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        vector<int> dp(10,0);
        dp[0] = 2;
        dp[1] = 2;
        dp[2] = 1;
        dp[5] = 1;
        dp[6] = 1;
        dp[8] = 2;
        dp[9] = 1;

        for(int i=1;i<=n;i++){
            int j = i,cnt1 = 0,cnt2 = 0;
            bool flag = true;
            while(j != 0){
                int a = j%10;
                if(dp[a] == 0){
                    flag = false;
                    cnt1 = 0;
                    break;
                }
                else if(dp[a] == 2) cnt1++;
                cnt2++;
                j/=10;
            }
            if(cnt1==cnt2 || !flag) cnt += 0;
            else cnt+=1;
        }
        return cnt;
    }
};
