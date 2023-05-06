/*
You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.
The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.
Return the earliest year with the maximum population.

Example 1:
Input: logs = [[1993,1999],[2000,2010]]
Output: 1993
Explanation: The maximum population is 1, and 1993 is the earliest year with this population.

Example 2:
Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
Output: 1960
Explanation:
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.

Constraints:
1 <= logs.length <= 100
1950 <= birthi < deathi <= 2050
*/


/// Prefix Sum

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        vector<int> v(150,0);
        for(int i=0;i<n;i++){
            v[logs[i][0]-1950]++;
            v[logs[i][1]-1950]--;
        }
        for(int i=1;i<150;i++){
            v[i]=v[i-1]+v[i];
        }
        int year=0, result=0;
        for(int i=0;i<150;i++){
            if(v[i]>result){
                result=v[i];
                year=i+1950;
            }
        }
    return year;
    }
};


/// Sweep Line Algorithm Solution

/// We can mark the start and end of each life as +1 and -1 on the timeline.
/// Then, we go through timeline from 1950 to 2050 and accumulate the current population for each year.


class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int result=0;
        vector<int> timeline(2051,0);
        for(auto log : logs){
            timeline[log[0]]++;
            timeline[log[1]]--;
        }
        for(int i=1950;i<2050;i++){
            timeline[i]+=timeline[i-1];
            if(timeline[i]>timeline[result]){
                result=i;
            }
        }
    return result;
    }
};
