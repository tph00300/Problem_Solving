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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode* head=new ListNode();
        ListNode* currentNode = head;
        while(l1 != nullptr || l2 != nullptr)
        {
            currentNode->next = new ListNode();
            currentNode= currentNode->next;
            int sum2=sum;
            if(l1!=nullptr)
                sum2+=l1->val;
            if(l2!=nullptr)
                sum2+=l2->val;
            sum=sum2/10;
            sum2%=10;
            currentNode->val=sum2;
            if(l1!=nullptr)
                l1=l1->next;
            if(l2!=nullptr)
                l2=l2->next;
        }
        if(sum>0)
            currentNode->next=new ListNode(sum);
        return head->next;
    }
};