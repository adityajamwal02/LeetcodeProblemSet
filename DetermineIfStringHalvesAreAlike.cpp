/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').
Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false.
*/


class Solution {
public:
    bool halvesAreAlike(string s) {
        int left=0,right=0;
        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
            if(i<s.size()/2){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||s[i]=='o' || s[i]=='u')
                    left++;
            }else{
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||s[i]=='o' || s[i]=='u')
                    right++;
            }
        }
    return (left==right);
    }
};
