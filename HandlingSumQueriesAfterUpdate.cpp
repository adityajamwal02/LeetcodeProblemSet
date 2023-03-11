/*
You are given two 0-indexed arrays nums1 and nums2 and a 2D array queries of queries. There are three types of queries:
For a query of type 1, queries[i] = [1, l, r]. Flip the values from 0 to 1 and from 1 to 0 in nums1 from index l to index r. Both l and r are 0-indexed.
For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.
Return an array containing all the answers to the third type queries.

Example 1:
Input: nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
Output: [3]
Explanation: After the first query nums1 becomes [1,1,1]. After the second query, nums2 becomes [1,1,1], so the answer to the third query is 3. Thus, [3] is returned.

Example 2:
Input: nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
Output: [5]
Explanation: After the first query, nums2 remains [5], so the answer to the second query is 5. Thus, [5] is returned.
*/


/// Brute

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size();
        vector<long long> result;
        vector<pair<int, pair<int,int>>> vec;
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<3;j++){
                vec.push_back({queries[0],{queries[1],queries[2]}});
            }
        }
        for(int i=0;i<vec.size();i++){
            int choice = vec.first;
            if(choice==1){
                int leftIndex=vec.second.first;
                int rightIndex=vec.second.second;
                for(int i=leftIndex;i<=rightIndex;i++){
                    nums[i]=(!nums[i]);
                }
            }else if(choice==2){
                int p=vec.second.first;
                for(int i=0;i<n;i++){
                    nums2[i]=nums2[i]+nums1[i]*p;
                }
            }else{
                int currSum=0;
                for(auto num : nums2){
                    currSum+=num;
                }
            result.push_back(currSum);
            }
        }
    return result;
    }
};

/// Lazy Segment Tree


class SegmentTree{
    public:
    vector<long long> seg,lazy;
    SegmentTree(long long n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }
    void build(int index,int low, int high, vector<int> &arr){
        if(low==high){
            seg[index]=arr[low];
            return;
        }
        long long mid=(low+high)>>1;
        build(2*index+1, low, mid, arr);
        build(2*index+2, mid+1, high, arr);
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }

    void update(int index, int low, int high, int l, int r, int val){
        if(lazy[index]!=0){
            seg[index]=(high-low+1)-seg[index];
            if(low!=high){
                lazy[2*index+1]=!lazy[2*index+1];
                lazy[2*index+2]=!lazy[2*index+2];
            }
            lazy[index]=0;
        }
        if(high<l or r<low) return;
        if(low>=l and high<=r){
            seg[index]=(high-low+1)-seg[index];
            if(low!=high){
                lazy[2*index+1]=!lazy[2*index+1];
                lazy[2*index+2]=!lazy[2*index+2];
            }
        return;
        }

        long long mid=(low+high)>>1;
        update(2*index+1,low,mid,l,r,val);
        update(2*index+2,mid+1,high,l,r,val);
        seg[index] = seg[2*index+1] + seg[2*index+2];
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        long long n=nums1.size();
        SegmentTree st(n+1);
        st.build(0,0,n-1,nums1);
        vector<long long> result;
        long long currSum=0;
        for(auto it : nums2){
            currSum+=it;
        }
        for(auto query : queries){
            if(query[0]==1){
                st.update(0,0,n-1,query[1],query[2],0);
            }else if(query[0]==2){
                currSum+=st.seg[0]*query[1];
            }else{
                result.push_back(currSum);
            }
        }
    return result;
    }
};
