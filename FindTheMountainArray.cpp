/*
(This problem is an interactive problem.)
You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.
You cannot access the mountain array directly. You may only access the array using a MountainArray interface:
MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

Example 1:
Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

Example 2:
Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
*/


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearchL(MountainArray &mountainArr, int low, int high, int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid)<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return -1;
    }

    int binarySearchR(MountainArray &mountainArr, int low, int high, int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }else if(mountainArr.get(mid)>target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int low=0, high=n-1;
        int peak;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid+1)>mountainArr.get(mid)){
                low=mid+1;
                peak=mid+1;
            }else{
                high=mid;
            }
        }
        int left = binarySearchL(mountainArr,0,peak,target);
        int right= binarySearchR(mountainArr,peak,n-1,target);
    return left>=0 ? left:right;
    }
};
