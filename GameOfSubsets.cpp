/*
Elena is the topper of the class. Once her teacher asked her a problem. He gave Elena an array of integers of length n. He calls a subset of array arr good if its product can be represented as a product of one or more distinct prime numbers. He asked her to find the number of different good subsets in arr modulo 109 + 7.

As a good friend of Elena help her to solve the problem.

Example 1:

Input:
N: 4
arr: {1,2,3,4}
Output: 6
Explanation:
The good subsets are:
- [1,2]: product is 2, which is the product of distinct
prime 2.
- [1,2,3]: product is 6, which is the product of
distinct primes 2 and 3.
- [1,3]: product is 3, which is the product of distinct
prime 3.
- [2]: product is 2, which is the product of distinct
 prime 2.
- [2,3]: product is 6, which is the product of distinct
primes 2 and 3.
- [3]: product is 3, which is the product of distinct
prime 3.
Example 2:

Input:
N : 3
arr : {2, 2, 3}
Output: 5
Explanantion:
The good subsets are : {2}, {2}, {2, 3}, {2, 3}, {3}
Your Task:
The task is to complete the function goodSubsets() which takes an integer n and an array arr as the input parameters and should return the number of different good subsets.

Expected Time Complexity: O(NlogN)
Expected Space Complexity: O(N)
*/

class Solution{
    unordered_map<int,int>cap;
    int mod = (int)(1e9+7);
    bool check(int n) {
        int c = 2;
        while (n > 1) {
            if (n % c == 0) {
                n/= c;
                if (n % c == 0) return false;
            } else {
                c++;
            }

        }
        true;
    }
    int fun(int i, vector<int>temp, vector<int>&arr) {
    if (i < 0) return 0;
    long long not_pick = fun(i-1,  temp, arr);
    long long pick = 0;
    bool flag = true;

    for (auto &x: temp) {
        if (arr[i] % x == 0) {
            flag = false;
            break;
        }
    }

    if (flag == true) {
        int val = arr[i];
        int c = 2;
        int m = 0;
        vector<int>temp2;
        bool flag2 = true;
        while (val > 1) {
            if (val % c == 0) {
                val = val / c;
                if (val % c == 0) {
                    flag2 = false;
                    break;
                }
                temp2.push_back(c);
            } else {
                c++;
            }
        }
        if (flag2 == true) {
            for (auto &x : temp2) {
                temp.push_back(x);
            }

            pick = (1 + fun(i-1 , temp, arr));
        }
    }


    long long val2 = cap[arr[i]];
    return  (val2*pick + not_pick)%mod;
}
public:
    int goodSubsets(vector<int> &arr, int n){
       int ones = 0;
        vector<int>nums;
       for (auto &x : arr) {
           if (x == 1) ones++;
           else {
            if (cap[x] == 0 && check(x)) {
                nums.push_back(x);
            }
            cap[x]++;
           }
       }

       vector<int>s;
       int ans = fun(nums.size()-1, s, nums);
       cap.clear();

       return ans*pow(2, ones);
    }
};
