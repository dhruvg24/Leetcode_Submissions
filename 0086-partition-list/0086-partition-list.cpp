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
    ListNode* partition(ListNode* head, int x) {
        //can have the seperate lists of lesser and greater items and merge at the end
        ListNode* init1 = new ListNode(-1);
        ListNode* init2 = new ListNode(-1);
        ListNode* iter1 = init1, *iter2 = init2;
        while(head){
            if(head->val < x){
                iter1->next = head;
                iter1 = iter1->next;
            }
            else{
                iter2->next = head;
                iter2 = iter2->next;
            }
            head = head->next;
        }
        // now need to merge both partitions
        iter1->next = init2->next;
        iter2->next = NULL;
        return init1->next;
    }

};