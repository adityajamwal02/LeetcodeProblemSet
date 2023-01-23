/*
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return compute the researcher's h-index.
According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.
If there are several possible values for h, the maximum one is taken as the h-index.

Example 1:
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Example 2:
Input: citations = [1,3,1]
Output: 1
*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n=citations.size();
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n-i) return n-i;
        }
    return 0;
    }
};


/// Binary Search

class Solution {
public:
    int hIndex(vector<int>& v) {
        int l = 0 , r = v.size() ;
         int mid;
         sort(v.begin(),v.end());
         int ans = 0 ;
        while(l <= r )
        {
            mid = (l+r)/2;
            int x = v.end()-upper_bound(v.begin(),v.end(),mid);
            cout<<x<<" ";
            if( x >= mid+1 )
            {
                ans = max(ans,mid+1);
                l = mid + 1;
            }
            else
            {
                r = mid -1 ;
            }
        }
        return ans;
    }
};
