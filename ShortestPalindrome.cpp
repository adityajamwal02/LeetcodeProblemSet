/*
You are given a string s. You can convert s to a
palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.

Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: s = "abcd"
Output: "dcbabcd"
*/


/// KMP solution

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};


/// Rolling Hash

class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        long long mod=1e9+7, prime=31, pnos=31;
        // 2 main hash functions (initially at starting index)
        int index=0;
        long long forward_hash = s[0]-'a'+1;
        long long reverse_hash = s[0]-'a'+1;
        for(int i=1;i<n;i++){
            forward_hash = forward_hash + (s[i]-'a'+1)*pnos;
            forward_hash = forward_hash%mod;

            reverse_hash = reverse_hash*prime + (s[i]-'a'+1);
            reverse_hash = reverse_hash%mod;

            // Update prime power
            pnos*=prime;
            pnos=pnos%mod;

            if(forward_hash==reverse_hash){
                index=i;
            }
        }
        string rev=s.substr(index+1);
        reverse(rev.begin(), rev.end());
    return rev+s;
    }
};
