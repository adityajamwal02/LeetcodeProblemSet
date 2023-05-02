/*
Geek is organizing a birthday party, so his friends brought a cake for him. The cake consists of N chunks, whose individual sweetness is represented by the sweetness array. Now at the time of distribution, Geek cuts the cake into K + 1 pieces to distribute among his K friends. One piece he took for himself. Each piece consists of some consecutive chunks. He is very kind, so he left the piece with minimum sweetness for him.
You need to find the maximum sweetness that the Geek can get if he distributes the cake optimally.

Example 1:
Input:
N  = 6, K = 2
sweetness[] = {6, 3, 2, 8, 7, 5}
Output:
9
Explanation:
Geek can divide the cake to [6, 3], [2, 8], [7, 5]
with sweetness level 9, 10 and 12 respectively.

Example 2:
Input:
N  = 7, K = 3
sweetness[] = {1, 2, 4, 7, 3, 6, 9}
Output:
7
Explanation:
Geek can divide the cake to [1, 2, 4], [7], [3, 6], [9]
with sweetness level 7, 7, 9 and 9 respectively.
Your Task:
You need to complete the maxSweetness() function which takes an integer array of sweetness, an integer N and an integer K as the input parameters and returns an integer denoting the maximum sweetness that the Geek can get.

Expected Time Complexity: O(NlogM), where M is the sum of elements in the array.
Expected Space Complexity: O(1)
*/


/// Binary Search

class Solution{
    public:
    bool ifPossible(vector<int> &sweetness, int val, int k){
        int sum=0, counter=0;
        for(auto it: sweetness){
            sum+=it;
            if(sum>=val){
                counter++;
                sum=0;
            }
        }
    return (counter>=k+1);
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        int low=0, high=0, result=0;
        for(auto it : sweetness){
            high+=it;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ifPossible(sweetness,mid,K)){
                result=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return result;
    }
};

