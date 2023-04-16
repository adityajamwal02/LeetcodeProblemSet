/*
Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.
A string is called valid if it can be formed by concatenating the string "abc" several times.

Example 1:
Input: word = "b"
Output: 2
Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "a" to obtain the valid string "abc".

Example 2:
Input: word = "aaa"
Output: 6
Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".

Example 3:
Input: word = "abc"
Output: 0
Explanation: word is already valid. No modifications are needed.
*/

/// Logically

class Solution {
public:
    int addMinimum(string word) {
        int n=word.size();
        int i=0, counter=0, value=0;
        while(i<n){
            if(word[i]-'a'==value){
                i++;
            }else{
                counter++;
            }
        value=(value+1)%3;
        }
        int sum=counter+n;
        int s=(sum+2)/3;
    return s*3-n;
    }
};

/// Stack based

class Solution {
public:
    int addMinimum(string word) {
        int cnt=0;
        if(word[0]!='a'){word='a'+word;cnt++;}
        if(word[word.length()-1]!='c'){word+='c';cnt++;}

        stack<char> st;
        st.push(word[0]);
        for(int i=1;i<word.length();){
            if(st.top()=='a'){
              if(word[i]!='b'){
                  cnt++;
                  st.push('b');
              }
              else{
                  st.push('b');
                  i++;
              }
            }
            else if(st.top()=='b'){
                if(word[i]!='c'){
                  cnt++;
                  st.push('c');
              }
              else{
                  st.push('c');
                  i++;
              }
            }
            else{
                if(word[i]!='a'){
                  cnt++;
                  st.push('a');
              }
              else{
                  st.push('a');
                  i++;
              }
            }
        }
        return cnt;
    }
};
