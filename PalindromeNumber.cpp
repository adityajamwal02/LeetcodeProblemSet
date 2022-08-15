

class Solution {
public:

    bool isPalindrome(int x) {
        if(x<0)
            return false;

        int lastDigit = 0;
        int copy = x;
        unsigned int rev = 0;
        while(x != 0)
        {
            lastDigit = x % 10;
            rev = (rev * 10) + lastDigit;
            x = x / 10;
        }

        if(copy == rev)
            return true;
        else
            return false;
    }
};
