/*
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.
You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).
For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

Example 1:
Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]
Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
*/


class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for(int index: w){
            if(s.empty()){
                s.push_back(index);
            }else{
                s.push_back(index+s.back());
            }
        }
    }
    int pickIndex() {
        int x=s.back();
        int index=rand()%x;
        auto it = upper_bound(s.begin(), s.end(), index);
    return it-s.begin();
    }
};
