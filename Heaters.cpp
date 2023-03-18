/*
Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
Every house can be warmed, as long as the house is within the heater's warm radius range.
Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
Notice that all the heaters follow your radius standard, and the warm radius will the same.

Example 1:
Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:
Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.

Example 3:
Input: houses = [1,5], heaters = [2]
Output: 3
*/

/// Binary Search Solution

class Solution {
public:
    bool isValid(vector<int> &houses, vector<int> &heaters, int mid, int n, int m){
        int index1=0, index2=0;
        while(index1<n and index2<m){
            if(houses[index1]>=heaters[index2]-mid and houses[index1]<=heaters[index2]+mid){
                index1++;
            }else{
                index2++;
            }
        }
        if(index1==n) return true;

    return false;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size(), m=heaters.size();
        long long low=0, high=1e9;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int result=INT_MAX;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isValid(houses,heaters,mid,n,m)){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return result;
    }
};
