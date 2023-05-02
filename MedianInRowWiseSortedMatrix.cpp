/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:
Input:
R = 3, C = 3
M = [[1, 3, 5],
     [2, 6, 9],
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.

Example 2:
Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives
us {1,2,3}. Hence, 2 is median.

Your Task:
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)
*/


/// Brute Force : O(n) Space + O(n^2) time_base

//User function template for C++

class Solution{
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        vector<int> result;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                result.push_back(matrix[i][j]);
            }
        }
        sort(result.begin(),result.end());
        int n=result.size();
        if(n%2!=0){
            int mid=n/2;
            return result[mid];
        }else{
        int mid=n/2-1;
        return (result[mid]+result[mid+1]);
    }
    return 1;
    }
};

/// Optimal Solution (Binary Search)


class Solution{
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int low=0, high=0;
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int counter=0;
            for(int i=0;i<R;i++){
                counter+=upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            }
            if(counter<(R*C+1)/2){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return low;
    }
};


