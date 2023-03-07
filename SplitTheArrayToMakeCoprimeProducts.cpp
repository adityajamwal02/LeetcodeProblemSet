/*
You are given a 0-indexed integer array nums of length n.
A split at an index i where 0 <= i <= n - 2 is called valid if the product of the first i + 1 elements and the product of the remaining elements are coprime.
For example, if nums = [2, 3, 3], then a split at the index i = 0 is valid because 2 and 9 are coprime, while a split at the index i = 1 is not valid because 6 and 3 are not coprime. A split at the index i = 2 is not valid because i == n - 1.
Return the smallest index i at which the array can be split validly or -1 if there is no such split.
Two values val1 and val2 are coprime if gcd(val1, val2) == 1 where gcd(val1, val2) is the greatest common divisor of val1 and val2.

Example 1:
Input: nums = [4,7,8,15,3,5]
Output: 2
Explanation: The table above shows the values of the product of the first i + 1 elements, the remaining elements, and their gcd at each index i.
The only valid split is at index 2.

Example 2:
Input: nums = [4,7,15,8,3,5]
Output: -1
Explanation: The table above shows the values of the product of the first i + 1 elements, the remaining elements, and their gcd at each index i.
There is no valid split.
*/

/// FOR SMALL INPUTS

class Solution {
public:
    long long GCD(long long a, long long b)
    {
        if (b == 0)
            return a;

    return GCD(b, a % b);
    }
    long long findValidSplit(vector<int>& nums) {
        int N=nums.size();
        long long prefix[N], suffix[N], i, k;
        prefix[0] = nums[0];
        for (i = 1; i < N; i++) {
            prefix[i] = prefix[i - 1]* nums[i];
        }
        suffix[N - 1] = nums[N - 1];
        for (i = N - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1]* nums[i];
        }
        for (k = 0; k < N - 1; k++) {
            if(GCD(prefix[k],suffix[k + 1])== 1) {
                return k;
            }
        }
    return -1;
    }
};

/// EFFICIENT SOLUTIONS

/// 1. COUNT PRIMES

class Solution {
public:
    vector<int> factorize(int num){
        vector<int> result;
        for(int i=2; num>1 and i<1000; i=i+1+(i%2)){
            if(num%i==0){
                result.push_back(i);
                while(num%i==0){
                    num=num/i;
                }
            }
        }
        if(num>1){
            result.push_back(num);
        }
    return result;
    }

    int findValidSplit(vector<int>& nums) {
        unordered_map<int,int> left, right;
        for(auto num : nums){
            for(auto factor : factorize(num)){
                right[factor]++;
            }
        }
        for(int i=0, common=0;i<nums.size()-1;i++){
            for(auto factor : factorize(nums[i])){
                common = common + (left[factor]++ == 0) - (left[factor]==right[factor]);
            }
            if(common==0) return i;
        }
    return -1;
    }
};


/// 2. PRIME INTERVALS

vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; n > 1 && i < 1000; i += 1 + (i % 2))
        if (n % i == 0) {
            res.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    if (n > 1)
        res.push_back(n);
    return res;
}
int findValidSplit(vector<int>& nums) {
    unordered_map<int, int> fi;
    int line[10001] = {};
    for (int i  = 0; i < nums.size(); ++i)
        for (int f : factorize(nums[i])) {
            if (fi.count(f) == 0)
                fi[f] = i;
            ++line[fi[f]];
            --line[i];
        }
    partial_sum(begin(line), end(line), begin(line));
    int res = find(begin(line), end(line), 0) - begin(line);
    return res < nums.size() - 1 ? res : -1;
}


/// C++ Prime Factorization + Set Intersection, O(N sqrt N)

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int cnt = 0;
        map<int, int> suf, pref, vis;
        for(auto i : nums){
            for(int j = 2; j <= sqrt(i); j++){
                while(i%j == 0){
                    suf[j]++;
                    i/=j;
                }
            }
            if(i>=2) suf[i]++;
        }
        int k = 0;
        for(auto i : nums){
            for(int j = 2; j <= sqrt(i); j++){
                while(i%j == 0){
                    pref[j]++;
                    suf[j]--;
                    i/=j;
                    if(suf[j] == 0 && vis[j]++ == 0) cnt++;
                }
            }
            if(i>=2) {
                pref[i]++;
                suf[i]--;
                if(suf[i] == 0 && vis[i]++ == 0) cnt++;
            }
            if(cnt == pref.size() && k<nums.size()-1) return k;
            k++;
        }
        return -1;
    }
};
