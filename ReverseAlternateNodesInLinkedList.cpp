/*
Given a linked list, you have to perform the following task:
Extract the alternative nodes starting from second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.

Example 1:
Input:
LinkedList = 10->4->9->1->3->5->9->4
Output: 10 9 3 9 4 5 1 4
Explanation: Reversing the alternative
nodes from the given list, and then
appending them to the end of the list
results in a list with the elements as
10 9 3 9 4 5 1 4.

Example 2:
Input:
LinkedList = 1->2->3->4->5
Output: 1 3 5 4 2
Explanation:
Your Task:
You don't have to read input or print anything. Your task is to complete the function rearrange() which takes the head of the linked list as input and rearranges the list as required.

Note: Try to solve the problem without using any extra memory.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

///


/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };

*/

class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        Node *start = odd;
        Node *start_alt = odd->next;
        Node *a = start;
        Node *b = start_alt;
        while(b!=NULL and b->next!=NULL){
            a->next = a->next->next;
            a = a->next;
            b->next = b->next->next;
            b = b->next;
        }
        Node *curr=start_alt;
        Node *prev = NULL;
        while(curr!=NULL){
            Node *next=curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

    a->next=prev;
    }
};

