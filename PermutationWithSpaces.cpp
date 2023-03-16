/*
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

Example 1:
Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".

Example 2:
Input:
S = "AB"
Output: (A B)(AB)

Your Task:
You don't need to read input or print anything. Your task is to complete the function permutation() which takes the string S as input parameters and returns the sorted array of the string denoting the different permutation (DON'T ADD '(' and ')' it will be handled by the driver code only).

Expected Time Complexity: O(2^n)
Expected Auxiliary Space: O(1)
*/


class Solution{
public:

    void solve(string input, string output, vector<string> &result){
        if(input.size()==0){
            result.push_back(output);
            return;
        }
        string op1=output;
        string op2=output;
        op1.push_back(' ');
        op1.push_back(input[0]);
        op2.push_back(input[0]);
        input.erase(input.begin()+0);
        solve(input,op1,result);
        solve(input,op2,result);
    }

    vector<string> permutation(string S){
       vector<string> result,ans;
       string output="";
       solve(S,output,result);
       for(int i=0;i<result.size();i++){
           if(result[i][0]!=' '){
               ans.push_back(result[i]);
           }
       }
    return ans;
    }
};
