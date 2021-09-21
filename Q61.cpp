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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==nullptr || head->next == nullptr){
            return head;
        }
        int n = 1;
        ListNode *p = head;
        while(p->next != nullptr){
            p = p->next;
            n++;
        }
        int change = n - k%n;
        if(change == n){
            return head;
        } 
        p->next = head;
        while(change--){
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};