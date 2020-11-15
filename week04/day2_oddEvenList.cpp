class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode*even = head->next;
        ListNode*pre = head;
        ListNode*p = head->next;
        int num=0;
        while(p->next){
            pre->next = p->next;
            pre =p;
            p= p->next;
            num++;    
        }
        if(num%2==0)
            pre->next = even;
        else{
            pre->next=nullptr;
            p->next = even;
        }     
        return head;
        
    }
};