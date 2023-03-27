/*
Given an array sequence [A1 , A2 ...An], the task is to find the maximum possible sum of increasing subsequence S of length K such that Si1<=Si2<=Si3.........<=Sin.

Example 1:
Input:
N = 8 K = 3
A[] = {8 5 9 10 5 6 19 8}
Output: 38
Explanation:
Possible increasing subsequence of
length 3 with maximum possible
sum is 9 10 19.

Example 2:
Input:
N = 2,K = 2
A[] = {10 5}
Output: -1
Explanation:
Can't make any increasing subsequence
of length 2
*/


/// DP Recursion

class Solution
{
	public:
	    int helper(vector<int> &a, int k, int i, int prev){
	        if(k<0) return INT_MIN;
	        if(i>=a.size()){
	            if(k==0) return 0;
	        return INT_MIN;
	        }
	        int ans=INT_MIN;
	        if(prev==-1){
	            int temp1=a[i]+helper(a,k-1,i+1,i);
	            int temp2=helper(a,k,i+1,prev);
	            ans=max({ans,temp1,temp2});
	        }else{
	            if(a[prev]<=a[i] and k>0){
	                int temp1=a[i]+helper(a,k-1,i+1,i);
	                int temp2=helper(a,k,i+1,prev);
	                ans=max({ans,temp1,temp2});
	            }else{
	                ans=max(ans,helper(a,k,i+1,prev));
	            }
	        }
	       return ans;
	    }

		int max_sum(vector<int> &a, int k)
		{
		    return helper(a,k,0,-1) < 0 ? -1 : helper(a,k,0,-1);
		}
};


/// PQ Solution (Partial Correct)

class Solution
{
	public:
		int max_sum(vector<int> &a, int k)
		{
		    int n=a.size();
		    priority_queue<pair<int,int>> pq;
		    for(int i=0;i<n;i++){
		        pq.push({a[i],i});
		    }
		    int currSum=pq.top().first;
		    int prevIndex=pq.top().second;
		    pq.pop();
		    int counter=1;
		    while(!pq.empty()){
		        if(counter==k) break;
		        int nextIncrease=pq.top().first;
		        int nextIndex=pq.top().second;
		        if(prevIndex>nextIndex){
		            currSum+=nextIncrease;
		            prevIndex=nextIndex;
		            counter++;
		        }
		        pq.pop();
		    }
		    if(counter<k) return -1;
		return currSum;
		}
};

