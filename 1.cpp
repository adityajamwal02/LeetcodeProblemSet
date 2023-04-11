/*
nums = [10, -23, 1, 2, 100, 5, 23, 25]

mat[][] =[[0, 3], [2, 5]]
*/



#include<bits/stdc++.h>
using namespace std;

/// Brute Force

void PrintRangeOfSums(vector<int> nums, vector<vector<int>> mat) {
    int curr=0;
    for(int i=0;i<mat.size();i++){
        int start=mat[i][0];
        int ending=mat[i][1];
        curr=0;
        for(int i=start;i<=ending;i++){
            curr+=nums[i];
        }
        cout<<curr<<endl;
    }
}

///  PrefixSum Concept

void PrintPrefixAns(int start, int ending,vector<int> nums, vector<vector<int>> mat, vector<int> &prefixSum) {
        if(start-1 ==-1){
            cout<<prefixSum[ending]<<endl;
            return;
        }
        cout<<prefixSum[ending]-prefixSum[start-1]<<endl;
}


int main(){

    vector<int> nums={10, -23, 1, 2, 100, 5, 23, 25};
    int n=nums.size();
    vector<vector<int>> mat={{0, 3}, {2, 5}};
    vector<int> prefixSum(n);
    prefixSum[0]=nums[0];
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    //PrintRangeOfSums(nums,mat);
    for(int i=0;i<mat.size();i++){
        int start=mat[i][0];
        int ending=mat[i][1];
        PrintPrefixAns(start,ending,nums,mat,prefixSum);
    }

    return 0;

}
