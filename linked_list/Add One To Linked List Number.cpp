class Solution {
  public:
    Node *reverseLL(Node *cur) {
        Node *prev = NULL,*nxt = NULL;
        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        
        return prev;
    }
  
    Node* addOne(Node* head) {
        head = reverseLL(head);
    
        int sum = head->data + 1;
        Node *newHead = new Node(sum%10);
        int carry = sum/10;
        head = head->next;

        
        while(head || carry) {
            sum = carry;

            if(head) {
                sum += head->data;
                head = head->next;
            }
            
            Node *node = new Node(sum%10);
            node->next = newHead;
            newHead = node;
            
            carry = sum/10;
        }
        
        return newHead;
    }
};