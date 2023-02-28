/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:
Input:
Stack: 3 2 1
Output: 3 2 1

Example 2:
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task:
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.
*/



/// Better Approach

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void helper(stack<int> &s, int temp){
    if(s.empty() or temp>s.top()){
        s.push(temp);
        return;
    }
    int nums=s.top();
    s.pop();
    helper(s,temp);
    s.push(nums);
}
void SortedStack :: sort()
{
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    sort();
    helper(s,temp);
}
