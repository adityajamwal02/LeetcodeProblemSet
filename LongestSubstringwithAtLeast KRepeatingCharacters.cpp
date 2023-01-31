/*
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

Example 1:
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/



class Solution {
public:
    int fx(string &s, int k, int totalU){   //totalU : Total Unique
        int n = s.size();
        int i=0, j=0;

        unordered_map<char, int> mpp;  //Character Frequency Map Of The Window.
        int windowU = 0;    //Unique Characters In Window.
        int atleastK = 0;   //Characters In Window With Atleast k Occurences.
        int maxi = 0;

        while(j<n){
            if(mpp.find(s[j]) == mpp.end()) windowU++;    //If element in not already in the window. Increase atleastK of unique elements.

            mpp[s[j]]++; if(mpp[s[j]] == k) atleastK++;  //If the count of element >= k : Increase atleastK variable.

            //If the count of unique element exceeds the limit, decrease window. Else increase window.
            if(windowU > totalU){
                while(windowU > totalU){
                    if(mpp[s[i]] == k) atleastK--;  //If the frequency of character is k, decrease the atleastK.
                    mpp[s[i]]--;

                    if(mpp[s[i]]==0){
                        windowU--;
                        mpp.erase(mpp.find(s[i]));
                    }

                    i++;
                }
            }

            if(atleastK == windowU) maxi = max(maxi, (j-i+1)); //If all the elements in the window occurs atleast k times.
            j++;
        }

        return maxi;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(k>n) return 0;

        vector<int> mpp(26, 0);
        int unique = 0;
        for(const char &c: s){
            if(mpp[c-'a']==0) unique++;
            mpp[c-'a']++;
        }

        int maxi = 0;
        for(int i=1; i<=unique; i++){
            maxi = max(maxi, fx(s, k, i));
        }

        return maxi;
    }
};
