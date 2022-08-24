/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit.
Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.
For example, the saying and conversion for digit string "3322251":
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string word=countAndSay(n-1);
        string new_word="";
        int letter_count=1;
        char curr_letter=word[0];
        for(int i=1;i<word.size();i++){
            if(word[i]==curr_letter)
                letter_count++;
            else{
                new_word+=to_string(letter_count)+curr_letter;
                letter_count=1;
                curr_letter=word[i];
            }
        }
        new_word+=to_string(letter_count)+curr_letter;

    return new_word;
    }
};

