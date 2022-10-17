/*
You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount of water supply available.
Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.
If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one or both buckets by the end.
Operations allowed:
Fill any of the jugs with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.

Example 1:
Input: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
Output: true
Explanation: The famous Die Hard example

Example 2:
Input: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
Output: false

Example 3:
Input: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
Output: true
*/


/// Queue Approach (BFS)

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x=jug1Capacity;
        int y=jug2Capacity;
        int z=x+y;
        int operations[]={x,-x,-y,y};
        queue<int> q;
        vector<int> vis(z+1, 0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==targetCapacity)
                return true;
            for(int i=0;i<4;i++){
                int newnode=node+operations[i];
                if(newnode>=0 and newnode<=z and vis[newnode]==0){
                    q.push(newnode);
                    vis[newnode]=1;
                }
            }
        }
    return false;
    }
};


/// Direct Mathematical Approach

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        return targetCapacity%__gcd(jug1Capacity,jug2Capacity)==0 and targetCapacity<=jug1Capacity+jug2Capacity;
    }
};

/// GCD Approach

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity)
            return false;
        return targetCapacity % gcd (jug1Capacity, jug2Capacity) == 0;
    }
};
