/*
Given two Lists of strings s1 and s2, you have to count the number of strings in s2 which is either a suffix or prefix of at least one string of s1.

Example 1:
Input:
s1 = ["cat", "catanddog", "lion"]
s2 = ["cat", "dog", "rat"]
Output:
2
Explanation:
String "cat" of s2 is prefix of "catanddog"
& string "dog" of s2 is suffix of "catanddog"

Example 2:
Input:
s1 = ["jrjiml", "tchetn", "ucrhye", "ynayhy",
       "cuhffd", "cvgpoiu", "znyadv"]
s2 = ["jr", "ml", "cvgpoi", "gpoiu", "wnmkmluc",
      "geheqe", "uglxagyl", "uyxdroj"]
Output:
4
Explanation:
String "jr" of s2 is prefix of "jrjiml",
"ml" of s2 is suffix of "jrjiml",
"cvgpoi" of s2 is prefix of "cvgpoiu" &
"gpoiu" of s2 is suffix of "cvgpoiu"
Your Task:
You don't need to read input or print anything. Your task is to complete the function prefixSuffixString(), which takes 2 strings s1 and s2 as input and returns an integer value as the number of strings in s2 which is a prefix or suffix in s1.

Expected Time Complexity: O(max(len(s1) , len(s2) ))
Expected Space Complexity: O(1)
*/

/// Trie Based

class Solution{
public:
    struct trieNode
    {
        trieNode* children[26];
    };

    trieNode* getNode()
    {
        trieNode* newNode = new trieNode();
        for(int i = 0; i<26; i++)
        {
            newNode->children[i]=NULL;
        }
        return newNode;
    }

    void insert_trie(trieNode* root, string &word)
    {
        trieNode* crawler = root;
        for(int i = 0; i<word.length(); i++)
        {
            char ch = word[i];
            if(crawler->children[ch-'a']==NULL)
            {
                crawler->children[ch-'a']=getNode();
            }
            crawler = crawler->children[ch-'a'];
        }
    }

    bool find_word(trieNode* root, string &word)
    {
        trieNode* crawler = root;
        for(int i = 0; i<word.length(); i++)
        {
            if(crawler->children[word[i]-'a']==NULL)
                return false;

            crawler=crawler->children[word[i]-'a'];
        }
        return true;
    }

    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        trieNode* root_front = getNode();
        trieNode* root_back = getNode();
        for(auto str: s1)
        {
            insert_trie(root_front, str);
            string s = str;
            reverse(s.begin(), s.end());

            insert_trie(root_back, s);
        }
        int ans = 0;
        for(auto str: s2)
        {
            string s = str;
            reverse(s.begin(), s.end());
            if(find_word(root_front, str) || find_word(root_back, s))
                ans++;
        }
        return ans;
    }
};


/// Non Trie Based

//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        unordered_map<string, int> mp;
        for(auto it : s2){
            mp[it]++;
        }
        int counter=0;
        for(int i=0;i<s1.size();i++){
            string a,b;
            for(int j=0;j<s1[i].size()-1;j++){
                a+=s1[i][j];
                b=s1[i][s1[i].size()-1-j]+b;
                if(mp.find(a)!=mp.end()){
                    if(mp[a]>0){
                        counter++;
                        mp[a]--;
                    }
                }
                if(mp.find(b)!=mp.end()){
                    if(mp[b]>0){
                        counter++;
                        mp[b]--;
                    }
                }
            }
        }
    return counter;
    }
};
