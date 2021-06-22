/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
      if (!head || !head->next) return head;
      
      ListNode d(0);
      d.next = head;
      head = &d;
      
      while (head && head->next && head->next->next) {
          auto n1 = head->next;
          auto n2 = n1->next;
          
          n1->next = n2->next;
          n2->next = n1;
          
          head->next = n2;
          head = n1;
      }
      return d.next;
  }
};
