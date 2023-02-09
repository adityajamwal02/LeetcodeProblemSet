/*
You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:
Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.

Example 1:
Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.
The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.

Example 2:
Input: ideas = ["lack","back"]
Output: 0
Explanation: There are no valid selections. Therefore, 0 is returned.
*/

/// o(m*n)

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> arr(26);
        long long ans=0;
        for(auto s : ideas){
            arr[s[0]-'a'].insert(s.substr(1));
        }
        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
                unordered_set<string> st;
                st.insert(arr[i].begin(), arr[i].end());
                st.insert(arr[j].begin(), arr[j].end());
                ans+=(arr[i].size() - st.size())*(arr[j].size() - st.size());
            }
        }
    return 2*ans;
    }
};


/// O(nlogn)

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, bool> mp;
        vector<bool> store(26, 0);

        for(auto s : ideas){
            mp[s] = true;
            store[s[0] - 'a'] = 1;
        }

        vector<vector<int>> DP(26, vector<int>(26, 0));

        for(auto &s : ideas){
            char ch = s[0];

            for(int i=0; i<26; i++){
                if(store[i] == 0) continue;
                if(i+'a' == ch) continue;

                char c = i + 'a';
                s[0] = c;
                if(mp.find(s) == mp.end()) DP[ch-'a'][c-'a']++;
            }
        }

        long long ans = 0;

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(DP[i][j] == 0) continue;

                ans = ans + (DP[i][j] * DP[j][i] * 2);
                DP[i][j] = 0;
                DP[j][i] = 0;
            }
        }

        return ans;
    }
};
