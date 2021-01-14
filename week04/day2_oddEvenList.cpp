ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode*even = head->next;
        ListNode*pre = head;
        ListNode*p = head->next;
        while(pre && p && pre->next &&p->next){
            pre->next = pre->next->next;
            p->next = p->next->next;
            pre = pre->next;
            p = p->next;
        }
        pre->next = even;    
        return head;  
    }
