/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.
After each operation, the count will start from k+1th person. The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

Example 1:
Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so
skipping 1 person i.e 1st person 2nd
person will be killed. Thus the safe
position is 3.


Example 2:
Input:
n = 5 k = 3
Output: 4
Explanation: There are 5 persons so
skipping 2 person i.e 3rd person will
be killed. Thus the safe position is 4.

Your Task:
You don't need to read input or print anything. You are required to complete the function josephus () that takes two parameters n and k and returns an integer denoting safe position.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

/// Recursion Based Solution

class Solution {
private:
    void solve(int i, int k, vector<int> &nums) {

        if (nums.size() == 1) {
            return;
        }

        // updating the value of index(i) to help us iterate
        i += k;

        // this line help us to rotate in the array when we reach the end of it.
        if (i >= nums.size()-1) {
            i %= nums.size();
        }

        // removing the person from the array.
        nums.erase(nums.begin() + i);

        // recursive call
        solve(i, k, nums);
    }

public:
    int findTheWinner(int n, int k) {

        vector<int> nums;
        // push all the numbers int the array
        for (int i=0; i<n; i++) {
            nums.push_back(i+1);
        }

        // decrease the value of k by 1 because the person has to select himself also.
        k--;

        solve(0, k, nums);

        return nums[0];
    }
};

/// Queue Based Solution

/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k)
    {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            for(int i=k;i>1;i--){
                int first=q.front();
                q.pop();
                q.push(first);
            }
            q.pop();
        }
    return q.front();
    }
};


