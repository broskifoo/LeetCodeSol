/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:


    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow= slow->next;
            fast=fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* previous = nullptr;
        while(second != nullptr){
            ListNode* nextNode = second->next;
            second->next = previous;
            previous = second;
            second = nextNode;
        }

        second = previous;

        ListNode* first = head;
        while(second != nullptr){
            ListNode* firstnext = first->next;
            ListNode* secondnext = second->next;

            first->next = second;
            second->next = firstnext;

            first = firstnext;
            second = secondnext;
        }
        
        
    }
};