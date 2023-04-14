/*
Given an array arr[] of N positive integers. Find an integer denoting the maximum XOR subset value in the given array arr[].

Example 1:
Input :
N = 3
arr[] = {2, 4, 5}
Output : 7
Explanation :
The subset {2, 5} has maximum
subset XOR value.

Example 2 :
Input :
N= 3
arr[] = {9, 8, 5}
Output : 13
Explanation :
The subset {8, 5} has maximum
subset XOR value.
Your Task :
You don't need to read input or print anything. Your task is to complete the function maxSubsetXOR() which takes the array and an integer as input and returns the maximum subset XOR value.

Expected Time Complexity : O(N*Log(max(arr[i])))
Expected Auxiliary Space : O(1)
*/

// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubsetXOR(int arr[], int N)
    {
        if(N==0) return 0;
        int num=0;
        while(true){
            int maxVal=*max_element(arr,arr+N);
            if(maxVal==0) return num;
            num=max(num,num^maxVal);
            for(int i=0;i<N;i++){
                arr[i]=min(arr[i], arr[i]^maxVal);
            }
        }
    }
};
