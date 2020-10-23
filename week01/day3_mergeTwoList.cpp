   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        while(l1&&l2){
            if(l1->val<=l2->val){
                p->next = l1;
                p=p->next;
                l1=l1->next;
            }
            else{
                p->next =l2;
                p = p->next;
                l2=l2->next;
            }
        }
        while(l1) {p->next=l1;p = p->next;l1=l1->next;}
        while(l2) {p->next=l2;p=p->next;l2=l2->next;}

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
        
    }