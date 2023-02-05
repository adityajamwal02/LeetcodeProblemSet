/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:
Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation:

Example 2:
Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram
will be 8  and there will be 2 consecutive
histogram. And hence the area of the
histogram will be 8x2 = 16.
*/

// Nearest Smaller to Right
vector<long long> NSR(long long arr[], int n){
        vector<long long> right;
        stack<pair<long long, long long>> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top().first>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right.push_back(n);
            }else{
                right.push_back(st.top().second);
            }
        st.push({arr[i],i});
        }
        reverse(right.begin(), right.end());

    return right;
    }

    // Nearest Smaller to Left
    vector<long long> NSL(long long arr[], int n){
        vector<long long> left;
        stack<pair<long long, long long>> st1;
        for(int i=0;i<n;i++){
            while(!st1.empty() and st1.top().first>=arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                left.push_back(-1);
            }else{
                left.push_back(st1.top().second);
            }
        st1.push({arr[i],i});
        }

    return left;
    }

    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> right=NSR(arr,n);
        vector<long long> left=NSL(arr,n);
        vector<long long> output;

        for(int i=0;i<n;i++){
            output.push_back((right[i]-left[i]-1)*arr[i]);
        }
        long long ans=*max_element(output.begin(), output.end());

    return ans;
    }
