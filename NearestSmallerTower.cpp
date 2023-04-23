/*
Given an array where each element (arr[i]) represents the height of the tower. Find for each tower, the nearest possible tower that is shorter than it. You can look left or right on both sides.
Note :

If two smaller towers are at the same distance, pick the smallest tower.

If two towers have the same height then we choose the one with a smaller index.

Example 1:

Input:
arr[] = {1,3,2}
Output:
{-1,0,0}
Explanation:
For 0th Index : no tower is smallest, so -1.
For 1st Index : For 3, here 1 & 2 both are
small & at a same distance, so we will pick 1,
beacuse it has smallest value, so 0(Index)
For 2nd Index : here 1 is smaller, so 0(Index)
So the final output will be which consistes
Indexes are {-1,0,0}.
Example 2:

Input:
arr[] = {4,8,3,5,3}
Output:
{2,2,-1,2,-1}

Explanation:
For 0th Index : here 3 is the smaller, so 2(Index)
For 1st Index : For 8, here 4 & 3 both are
small & at a same distance, so we will pick 3, so 2(Index)
For 2nd Index : no tower is smallest, so -1.
For 3rd Index : For 5, here 3 & 3 both are
small & at a same distance, so we will pick
3(2nd Index) because it smaller Index, so 2(Index)
For 4th Index : no tower is smallest, so -1.
So the final output will be which consistes
Indexes are {2,2,-1,2,-1}.
Your Task:
You don't need to read input or print anything. Your task is to complete the function nearestSmallerTower() which takes an array of heights of the towers as input parameter and returns an array of indexes of the nearest smaller tower. If there is no smaller tower on both sides then return -1 for that tower.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/


//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        stack<int> s;
        int n = arr.size();
        vector<int> right(n), left(n), res(n, -1);
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() and arr[s.top()] >= arr[i])
                s.pop();

            if(s.empty()) right[i] = -1;
            else right[i] = s.top();

            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i = 0; i < n; i++) {
            while(!s.empty() and arr[s.top()] >= arr[i])
                s.pop();

            if(s.empty()) left[i] = -1;
            else left[i] = s.top();

            s.push(i);
        }

        for(int i = 0; i < n; i++) {
            if(left[i] == -1 and right[i] == -1)
                res[i] = -1;

            else if(left[i] == -1) {
                res[i] = right[i];
                continue;
            }

            else if(right[i] == -1) {
                res[i] = left[i];
                continue;
            }

            else {
                int d1 = abs(i - left[i]), d2 = abs(i - right[i]);

                if(d1 == d2) {
                    if(arr[left[i]] < arr[right[i]]) res[i] = left[i];

                    else if(arr[left[i]] > arr[right[i]]) res[i] = right[i];

                    else res[i] = left[i];
                }
                else if(d1 < d2)
                    res[i] = left[i];

                else res[i] = right[i];
            }
        }

        return res;
    }
};
