// GFG : -Delete all occurrences of x in doubly linked list
// time complexity: O(n)
// space complexity: O(1)
// 
class Solution {
    public:
      void deleteAllOccurOfX(struct Node** head_ref, int x) {
          // Write your code here
          if(!*head_ref) return;
          
          // If we want to delete the head
          Node* temp = *head_ref;
          
          while(temp && temp->data == x){
              Node* toDelete = temp;
              temp = temp->next;
              if(temp) temp->prev = nullptr;
              delete toDelete;
          }
          *head_ref = temp;
          
          temp = *head_ref;
    
          
          while(temp){
              if(temp->data == x){
                  Node* back = temp->prev;
                  Node* front = temp->next;
                  
                  Node* toDelete = temp;
                  if(back) back->next = temp->next;
                  if(front) front->prev = temp->prev;
                  delete toDelete;
              }
              temp = temp->next;
          }
      }
  };