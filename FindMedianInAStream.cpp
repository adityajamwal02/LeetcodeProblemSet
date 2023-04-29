/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5,15)
1 goes to stream --> median 5 (5,15,1)
3 goes to stream --> median 4 (5,15,1 3)


Example 2:

Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5)
10 goes to stream --> median 7.5 (5,10)
15 goes to stream --> median 10 (5,10,15)
Your Task:
You are required to complete the class Solution.
It should have 2 data members to represent 2 heaps.
It should have the following member functions:
insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
getMedian() does not take any arguments. It should return the current median of the stream.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)

*/

class Solution
{
    priority_queue<double> pq1;
    priority_queue<double,vector<double>,greater<double>> pq2;

    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(pq1.size()==0 or pq1.top()>x){
            pq1.push(x);
        }else{
            pq2.push(x);
        }
    balanceHeaps();
    }

    //Function to balance heaps.
    void balanceHeaps()
    {
        if(pq1.size()>pq2.size()+1){
            pq2.push(pq1.top());
            pq1.pop();
        }else if(pq2.size()>pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    //Function to return Median.
    double getMedian()
    {
        double median;

        if(pq1.size()==pq2.size()){
            median=(pq1.top() + pq2.top())/2.0;
        }else{
            median=pq1.top();
        }
    return median;
    }
};
