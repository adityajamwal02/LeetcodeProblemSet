class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int length=m+n;
        vector<int> v;
        for(int i=0;i<m;i++)
        {
            v.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++)
        {
            v.push_back(nums2[i]);
        }
        sort(v.begin(), v.end());
        for(int i=0;i<length;i++)
            nums1[i]=v[i];
    }
};

/// Optimized 2 pointer solution

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 and j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }else{
                nums1[k--]=nums2[j--];
            }
        }
        while(i>=0)  nums1[k--]=nums1[i--];
        while(j>=0)  nums1[k--]=nums2[j--];
    }
};
