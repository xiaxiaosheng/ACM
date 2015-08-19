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
    ListNode* removeElements(ListNode* head, int val) {
         if(NULL == head) return NULL;
        ListNode* hh = new ListNode(0);
        hh->next = head;
        ListNode* pre = hh,*p = head;
        while(p)
        {
            if(p->val == val)
            {
                pre->next = p->next;
                delete p;
                p = pre->next;
            }
            else
            {
                p = p->next;
                pre = pre->next;
            }
        }
        return hh->next;
    }
};
