class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
       help(head);
       return res;
    }
    void help(ListNode* head)
    {
        if(!head) return;
        help(head->next);
        res.push_back(head->val);
    }

private:
    vector<int> res;
};