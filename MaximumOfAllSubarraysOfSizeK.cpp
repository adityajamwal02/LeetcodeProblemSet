/// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> result;
        deque<int> dq;
        int i=0, j=0;
        while(j<n){
            while(dq.size()>0 and dq.back()<arr[j]){
                    dq.pop_back();
                }
            dq.push_back(arr[j]);
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                result.push_back(dq.front());
                if(dq.front()==arr[i]){
                    dq.pop_front();
                }
            i++;
            j++;
            }
        }
    return result;
    }
};
