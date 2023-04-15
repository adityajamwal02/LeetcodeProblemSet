/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Example 1:
Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6
numbers form the longest consecutive
subsquence.

Example 2:
Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

/// Better Solution

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        if(N==1) return 1;
        set<int> st;
        for(int i=0;i<N;i++){
            st.insert(arr[i]);
        }
        vector<int> temp;
        for(auto it : st){
            temp.push_back(it);
        }
        int n=temp.size();
        int result=1, curr=temp[0], ans=INT_MIN;
        for(int i=1;i<n;i++){
            if((temp[i]-curr)==1){
                result++;
                curr=temp[i];
            }else{
                result=1;
                curr=temp[i];
            }
        ans=max(ans,result);
        }
    return ans;
    }
};


/// Optimal Solution

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> st;
        if(N==1) return 1;
        for(int i=0;i<N;i++){
            st.insert(arr[i]);
        }
        int longest=1;
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int counter=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x+=1;
                    counter+=1;
                }
                longest=max(longest,counter);
            }
        }
    return longest;
    }
};
