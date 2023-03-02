/*
Given a stack with push(), pop(), empty() operations, delete the middle of the stack without using any additional data structure.
Middle: ceil((size_of_stack+1)/2) (1-based index)


Example 1:
Input:
Stack = {1, 2, 3, 4, 5}
Output:
ModifiedStack = {1, 2, 4, 5}
Explanation:
As the number of elements is 5 ,
hence the middle element will be the 3rd
element which is deleted

Example 2:
Input:
Stack = {1 2 3 4}
Output:
ModifiedStack = {1 3 4}
Explanation:
As the number of elements is 4 ,
hence the middle element will be the 2nd
element which is deleted
*/


//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int k=ceil((sizeOfStack+1)/2);
        if(s.size()==k){
            s.pop();
            return;
        }
        int temp=s.top();
        s.pop();
        deleteMid(s,sizeOfStack);
        s.push(temp);
    }
};
