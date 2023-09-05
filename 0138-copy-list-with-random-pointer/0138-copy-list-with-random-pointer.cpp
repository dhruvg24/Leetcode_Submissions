/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*ptr = head;
        while(ptr!=NULL){
            Node*temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = ptr->next->next;
        }
        // reset
        ptr = head;
        while(ptr!=NULL){
            if(ptr->random==NULL){
                ptr->next->random = NULL;
            }
            else{
                ptr->next->random=ptr->random->next;
            }
            ptr=ptr->next->next;
        }

        Node*dummy = new Node(0);
        Node*item = head;
        ptr = dummy;
        Node*fast;
        while(item!=NULL){
            fast = item->next->next;
            ptr->next = item->next;
            item->next = fast;
            ptr=ptr->next;
            item = fast;
        }
        return dummy->next;
    
    }
};


