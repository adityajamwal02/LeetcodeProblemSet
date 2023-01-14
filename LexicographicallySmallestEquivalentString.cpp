/*
You are given two strings of the same length s1 and s2 and a string baseStr.
We say s1[i] and s2[i] are equivalent characters.
For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:
Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.
Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

Example 1:
Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".

Example 2:
Input: s1 = "hello", s2 = "world", baseStr = "hold"
Output: "hdld"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".

Example 3:
Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
Output: "aauaaaaada"
Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
*/

class Solution {
public:
    char find_parent(char c, vector<char> &parent){
        if(parent[c-97]==c) return c;

        parent[c-97]=find_parent(parent[c-97], parent);
    return parent[c-97];
    }
    void union_find(char a, char b, vector<char> &parent){
        a=find_parent(a,parent);
        b=find_parent(b,parent);
        if(a==b) return;
        else if(a>b) parent[a-97]=b;
        else parent[b-97]=a;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> parent(26);
        for(int i=0;i<26;i++){
            parent[i]='a'+i;
        }
        for(int i=0;i<s1.size();i++){
            union_find(s1[i],s2[i],parent);
        }
        for(int i=0;i<baseStr.size();i++)
            baseStr[i]=find_parent(baseStr[i], parent);

    return baseStr;
    }
};
