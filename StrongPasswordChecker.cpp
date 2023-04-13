/*
A password is considered strong if the below conditions are all met:
It has at least 6 characters and at most 20 characters.
It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.
In one step, you can:
Insert one character to password,
Delete one character from password, or
Replace one character of password with another character.

Example 1:
Input: password = "a"
Output: 5

Example 2:
Input: password = "aA1"
Output: 3

Example 3:
Input: password = "1337C0d3"
Output: 0
*/


class Solution {
public:
    int helper(string password, int n){
        int digits=1, lower=1, upper=1;
        for(int i=0;i<n;i++){
            if(password[i]>='0' and password[i]<='9') digits=0;
            else if(password[i]>='a' and password[i]<='z') lower=0;
            else if(password[i]>='A' and password[i]<='Z') upper=0;
        }
    return lower+upper+digits;
    }

    int strongPasswordChecker(string password) {
        int n=password.size();
        int charSum = helper(password,n);
        if(n<6) return max(charSum,6-n);
        int replace=0, ones=0, twos=0;
        for(int i=0;i<n;){
            int len=1;
            while(i+len<n and password[i+len]==password[i+len-1]){
                len++;
            }
            if(len>=3){
                replace+=len/3;
                if(len%3==0) ones+=1;
                if(len%3==1) twos+=2;
            }
            i+=len;
        }
        if(n<=20) return max(charSum, replace);
        int deleteCount = n-20;
        replace-=min(deleteCount,ones);
        replace-=min(twos,max(deleteCount-ones,0))/2;
        replace-=max(deleteCount-ones-twos, 0)/3;

    return deleteCount+max(charSum,replace);
    }
};
