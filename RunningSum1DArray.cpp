// O(n) time complexity

// APPROACH 1

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int sum=nums[0];
        res.push_back(sum);

        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            res.push_back(sum);
        }

    return res;
    }
};


// APPROACH 2 (Efficient)

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            nums[i]+=nums[i-1];
        }

    return nums;
    }
};
