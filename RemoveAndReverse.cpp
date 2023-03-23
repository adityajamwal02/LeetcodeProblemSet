/*
Given a string S which consists of only lower case English alphabets, you have to perform the below operations:
If the string S contains any repeating character, remove the first repeating character and reverse the string and again perform the above operation on the modified string, otherwise, you stop.
You have to find the final string.

Example 1:

Input: S = "abab"
Output: ba
Explanation:
In 1st operation: The first non repeating
character is a. After Removing the first
character, S = "bab". After Reversing the
string, S = "bab".
In 2nd operation: The first non repeating
character is b. After Removing the first
character, S = "ab". After Reversing the
string, S = "ba".
Now the string S does not contain any
repeating character.
Example 2:

Input: S = "dddd"
Output: d
Your Task:
You don't need to read input or print anything. Your task is to complete the function removeReverse( ) which accepts a string S input parameter and returns the modified string.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(K), K <= 26.
*/

//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        int n=S.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[S[i]]++;
        }
        bool flag=0;
        int i=0;
        while(true){
            if(n==1) return S;
            if(mp[S[i]]>1){
                mp[S[i]]--;
                S.erase(i,1);
                if(flag==0){
                    i=S.size()-1;
                    flag=1;
                }else{
                    i=0;
                    flag=0;
                }
            continue;
            }else if(S.size()==mp.size()){
                if(flag==1){
                    reverse(S.begin(), S.end());
                }
            return S;
            }
            if(flag==0) i++;
            else i--;
        }
    return "";
    }
};
