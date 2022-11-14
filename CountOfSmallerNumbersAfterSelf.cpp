/*
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:
Input: nums = [-1]
Output: [0]

Example 3:
Input: nums = [-1,-1]
Output: [0,0]
*/


const long long N = 6e5 + 9;

class Solution {
public:
    vector<long long> vec;
    Solution(){
        vec.resize(N,0);
    }
    void update(int pos, int x){
        for(int i=pos;i<N;i+=i&(-i)){
            vec[i]=vec[i]+x;
        }
    }

    long long sum(int pos){
        long long ans=0;
        for(int i=pos;i>0;i-=i&(-i)){
            ans+=vec[i];
        }
    return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            nums[i]+=1e5;
        }
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            int x=sum(nums[i]-1);
            cout<<nums[i]<<endl;
            update(nums[i],1);
            ans[i]=x;
        }
    return ans;
    }
};
