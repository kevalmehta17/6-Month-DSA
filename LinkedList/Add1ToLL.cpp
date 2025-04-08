// Check the GFG
// Add 1 to LL:- 
// Approach:- 
// 1. Reverse the linked list
// 2. take carry = 1 and add it to the first node of the reversed linked list
// 3. If the sum is greater than 9, carry will be 1 and the node value will be sum%10   
// 4. If the sum is less than 9, carry will be 0 and the node value will be sum%10 and break the loop reversed linked list and return the head
// 5. If the carry is still 1 and we reach the end of the linked list, create a new node with value 1 and attach it to the end of the linked list
// 6. Reverse the linked list again to restore the original order and return the head of the modified linked list
// TC : O(N)
// SC : O(1) (no extra space used)

class Solution {
    public:
    
     Node* reverseLL(Node* head){
          Node* prev = nullptr;
          Node* temp = head;
          while(temp){
              Node* nextNode = temp->next;
              temp->next = prev;
              prev = temp;
              temp = nextNode;
          }
          return prev;
      }
      Node* addOne(Node* head) {
          // Your Code here
      //   Reverse the LL
      head = reverseLL(head);
      
      int carry = 1;
      int sum = 0;
      Node* temp = head;
      
          while(temp){
              sum = temp->data + carry;
              temp->data = sum % 10;
              carry = sum / 10;
              
              if(carry == 0) break;
              
              if(temp->next == NULL && carry){
                  Node* newNode = new Node(carry);
                  temp->next = newNode;
                  carry = 0;
                  break;
              }
              
              temp = temp->next;
          }
          head = reverseLL(head);
          return head;
  
      }
  };