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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;       //if there is only one node in the list;
        ListNode *slow = head, *fast = head;
        slow = slow->next;
        fast = fast->next->next;
        while(slow != fast && fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast == NULL || fast->next == NULL) return NULL;
        else {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
};
