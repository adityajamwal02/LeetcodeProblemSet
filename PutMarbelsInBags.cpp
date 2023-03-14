/*
You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.
Divide the marbles into the k bags according to the following rules:
No bag is empty.
If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
The score after distributing the marbles is the sum of the costs of all the k bags.
Return the difference between the maximum and minimum scores among marble distributions.

Example 1:
Input: weights = [1,3,5,1], k = 2
Output: 4
Explanation:
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6.
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10.
Thus, we return their difference 10 - 6 = 4.

Example 2:
Input: weights = [1, 3], k = 2
Output: 0
Explanation: The only distribution possible is [1],[3].
Since both the maximal and minimal score are the same, we return 0.
*/


/// Sorting approach

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();

        if(k==1 or k==n) return 0;

        vector<long long> sum1, sum2;
        for(int i=0;i<n-1;i++){
            sum1.push_back(weights[i]+weights[i+1]);
            sum2.push_back(weights[i]+weights[i+1]);
        }
        sort(sum1.begin(), sum1.end());
        sort(sum2.rbegin(), sum2.rend());   // reverse sorting
        long long ans1=0, ans2=0;
        for(int i=0;i<k-1;i++){
            ans1+=sum1[i];
            ans2+=sum2[i];
        }
    return ans2-ans1;
    }
};

/// PQ based (one min heap, one max heap)

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;

        int n = weights.size();
        for (int i = 0; i < n - 1; i++) {
            maxQ.push(weights[i] + weights[i + 1]);
            if (maxQ.size() == k) {
                maxQ.pop();
            }

            minQ.push(weights[i] + weights[i + 1]);
            if (minQ.size() == k) {
                minQ.pop();
            }
        }


        long long diff = 0;
        while (!minQ.empty()) {
            diff += minQ.top() - maxQ.top();
            minQ.pop(); maxQ.pop();
        }

        return diff;
    }
};
