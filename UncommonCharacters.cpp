/*
Given two strings A and B. Find the characters that are not common in the two strings.

Note :- Return the string in sorted order.

Example 1:

Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation:
The characters 'f', 'i', 'o', 'q', 'r', 'u','z'
are either present in A or B, but not in both.
Example 2:

Input:
A = characters
B = alphabets
Output: bclpr
Explanation: The characters 'b','c','l','p','r'
are either present in A or B, but not in both.

Your Task:
You dont need to read input or print anything. Complete the function UncommonChars() which takes strings A and B as input parameters and returns a string that contains all the uncommon characters in sorted order. If no such character exists return "-1".


Expected Time Complexity: O(M+N) where M and N are the sizes of A and B respectively.
Expected Auxiliary Space: O(M+N)
*/

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            string result="";
            unordered_set<char> st1, st2;
            for(auto ch : A){
                st1.insert(ch);
            }
            for(auto ch : B){
                st2.insert(ch);
            }

            map<char,int> mp;
            for(auto ch : st1){
                mp[ch]++;
            }
            for(auto ch : st2){
                mp[ch]++;
            }
            int count=0;
            for(auto it : mp){
                if(it.second<=1){
                    result+=it.first;
                }else{
                    count++;
                }
            }
            if(count==mp.size()) return "-1";
        return result;
        }
};

