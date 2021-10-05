struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* H1 = l1;
        int count1 = 0;
        int count2 = 0;
        int sum,carry=0,rem;
        struct ListNode* Node = new struct ListNode;
        struct ListNode* Result = Node;
        
        while(H1!= nullptr){
           H1 = H1->next;
            count1++;
        }
        H1 = l2;
        
        while(H1!=nullptr){
           H1 = H1->next;
            count2++;
        }
        
        if(count1 >= count2){
            count1++;
            while(l1 != nullptr){
                if(l2 == nullptr){
                    sum = l1->val + carry;
                    l1 = l1->next;
                    carry = 0;
                }
                else{
                    sum = l1->val + l2->val + carry;
                    l2 = l2->next;
                    l1 = l1->next;
                    carry = 0;
                }
                if(sum > 9){
                    carry = sum/10;
                   rem = sum % 10;
                }
                else{
                    rem = sum;
                }
                if(count1 != 0){
                    Result->next = new struct ListNode(rem);
                    Result = Result->next;
                }
                count1--;
            }
            Node = Node -> next;
            if(carry>0){
                Result->next = new struct ListNode(carry);
            }
        }
        else{
            count2++;
            while(l2 != nullptr){
                if(l1 == nullptr){
                    sum = l2->val + carry;
                    l2 = l2->next;
                    carry = 0;
                }
                else{
                    sum = l1->val + l2->val + carry;
                    l2 = l2->next;
                    l1 = l1->next;
                    carry = 0;
                }
                if(sum > 9){
                    carry = sum/10;
                   rem = sum % 10;
                }
                else{
                    rem = sum;
                }
                if(count2 != 0){
                    Result->next = new struct ListNode(rem);
                    Result = Result->next;
                }
                count2--;
            }
            Node = Node -> next;
            if(carry>0){
                Result->next = new struct ListNode(carry);
            }
        }
            
        
    return Node;
        
    }
};