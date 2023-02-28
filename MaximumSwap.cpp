/*
You are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.

Example 1:
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:
Input: num = 9973
Output: 9973
Explanation: No swap.
*/

/// Greedy (String convertion and N-> no. of char. in string)

class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int n = temp.size();
        for(int i=0;i<n;i++){
            char ch=temp[i];
            int max_index=i;
            for(int j=i+1;j<n;j++){
                if(temp[j]>=ch){
                    ch=temp[j];
                    max_index=j;
                }
            }
            if(ch>temp[i]){
                swap(temp[i], temp[max_index]);
                break;
            }
        }
    return stoi(temp);
    }
};


/// Extra Space Vector used


class Solution {
public:
    int maximumSwap(int n) {
        vector<int> a;

        for(int m=n; m; m /= 10)
            a.emplace_back(m%10);

        int len=a.size();
        int ans=n;

        vector<int>p10(10);

        p10[0]=1;

        for(int i=1;i<10;++i)
            p10[i] = p10[i-1]*10;

        for(int i=0;i<len;++i)
            for(int j=i+1;j<len;++j){
                int curr = n - p10[i]*a[i] + p10[i]*a[j] - p10[j]*a[j] + p10[j]*a[i];
                ans = max(ans, curr);
            }

        return ans;
    }
};
