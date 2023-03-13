/*
The task is to find the smallest number with given sum of digits as S and number of digits as D.

Example 1:
Input:
S = 9
D = 2
Output:
18
Explanation:
18 is the smallest number
possible with sum = 9
and total digits = 2.

Example 2:
Input:
S = 20
D = 3
Output:
299
Explanation:
299 is the smallest number
possible with sum = 20
and total digits = 3.

Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestNumber() which takes the two integers S and D and returns a string which is the smallest number if possible, else return "-1".

Expected Time Complexity: O(D)
Expected Auxiliary Space: O(1)
*/

class Solution{
public:
    string smallestNumber(int S, int D){
        if(S>9*D){
            return "-1";
        }else{
            string result="";
            for(int i=1;i<D;i++){
                if(S>9){
                    S-=9;
                    result+="9";
                }else{
                    result+=to_string(S-1);
                    S=1;
                }
            }
            result+=to_string(S);
            reverse(result.begin(), result.end());
            return result;
        }
    }
};
