/*
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),i=0,k=0;
        while(i<n){
            if(s[i]==' ')
            {
                reverse(s.begin()+k,s.begin()+i);
                k=i+1;
            }
            i++;
        }
        reverse(s.begin()+k,s.begin()+i);
        return s;
    }
};
