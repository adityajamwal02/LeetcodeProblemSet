/*
Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to both the lists and return the list in sorted order. Duplicates may be there in the output list.

Example:

Input:
n = 5
v1[] = {3, 4, 2, 2, 4}
m = 4
v2[] = {3, 2, 2, 7}
Output:
2 2 3
Explanation:
The common elements in sorted order are {2 2 3}
Your Task:
This is a function problem. You need to complete the function common_element that takes both the lists as parameters and returns a list of common elements.
*/

//Back-end complete function Template for C++

class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        vector<int> result;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int n=v1.size(), m=v2.size(), i=0, j=0;
        while(i<n and j<m){
            if(v1[i]==v2[j]){
                result.push_back(v1[i]);
                i++; j++;
            }else if(v1[i]>v2[j]){
                j++;
            }else{
                i++;
            }
        }
    return result;
    }
};
