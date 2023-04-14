/*
You are given a 0-indexed binary string s which represents a sequence of train cars. s[i] = '0' denotes that the ith car does not contain illegal goods and s[i] = '1' denotes that the ith car does contain illegal goods.
As the train conductor, you would like to get rid of all the cars containing illegal goods. You can do any of the following three operations any number of times:
Remove a train car from the left end (i.e., remove s[0]) which takes 1 unit of time.
Remove a train car from the right end (i.e., remove s[s.length - 1]) which takes 1 unit of time.
Remove a train car from anywhere in the sequence which takes 2 units of time.
Return the minimum time to remove all the cars containing illegal goods.
Note that an empty sequence of cars is considered to have no cars containing illegal goods.

Example 1:
Input: s = "1100101"
Output: 5
Explanation:
One way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end. Time taken is 1.
- remove the car containing illegal goods found in the middle. Time taken is 2.
This obtains a total time of 2 + 1 + 2 = 5.

An alternative way is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end 3 times. Time taken is 3 * 1 = 3.
This also obtains a total time of 2 + 3 = 5.

5 is the minimum time taken to remove all the cars containing illegal goods.
There are no other ways to remove them with less time.

Example 2:
Input: s = "0010"
Output: 2
Explanation:
One way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the left end 3 times. Time taken is 3 * 1 = 3.
This obtains a total time of 3.

Another way to remove all the cars containing illegal goods from the sequence is to
- remove the car containing illegal goods found in the middle. Time taken is 2.
This obtains a total time of 2.

Another way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the right end 2 times. Time taken is 2 * 1 = 2.
This obtains a total time of 2.

2 is the minimum time taken to remove all the cars containing illegal goods.
There are no other ways to remove them with less time.
*/

class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        vector<int> left(n,0), right(n,0);
        /// Prefix
        if(s[0]=='1'){
            left[0]=1;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                left[i]=min(left[i-1]+2, i+1);
            }else{
                left[i]=left[i-1];
            }
        }
        /// Suffix
        if(s[n-1]=='1'){
            right[n-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1'){
                right[i]=min(right[i+1]+2, n-i);
            }else{
                right[i]=right[i+1];
            }
        }
        int result=result=min(left[n-1], right[0]);
        for(int i=0;i<n-1;i++){
            result=min(result,left[i]+right[i+1]);
        }
    return result;
    }
};
