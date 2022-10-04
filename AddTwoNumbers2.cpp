/*
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
*/


/// REVERSE + ADD + REVERSE METHOD

class Solution {
public:

    ListNode* reverse(ListNode* head){

    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL){
        ListNode* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry == 1){
            int sum = 0;

            if(l1 != NULL){
              sum = sum + l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum = sum + l2 -> val;
                l2 = l2 -> next;
            }

            sum = sum + carry;
            carry = sum/10;
            ListNode* ans = new ListNode(sum%10);
            temp -> next = ans;
            temp = temp -> next;
        }
        return reverse(dummy -> next);
    }
};


///  WITHOUT REVERSING

class Solution {
public:
     ListNode *getnextdigit(ListNode *l,ListNode *stop)
    {
        while(l!=stop and l->next!=stop)
            l=l->next;
        return l==stop ? NULL : l;
    }

     ListNode *addTwoNumbers(ListNode* l1, ListNode* l2){
         int carry=0,s=0;
         ListNode *dig1=getnextdigit(l1,NULL), *dig2=getnextdigit(l2,NULL), *sum=NULL, *temp;
         while(dig1!=NULL or dig2!=NULL or carry){
             s=(dig1 ? dig1->val : 0) + (dig2 ? dig2->val : 0) + carry;
             temp=new ListNode(s%10);
             temp->next=sum;
             sum=temp;
             if(dig1)
                 dig1=getnextdigit(l1, dig1);
             if(dig2)
                 dig2=getnextdigit(l2, dig2);

             carry=s/10;
         }
        return sum;
     }
};
