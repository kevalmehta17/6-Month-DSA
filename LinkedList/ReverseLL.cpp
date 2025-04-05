
//  Reverse a linked list
// Optimal solution is O(n) time and O(1) space complexity
// Approach :- Iterative approach
// Think Approach :- Our task is to reverse the Link so that we take the prev and current node and change curr to prev but we have to also move forward thats why we need a nextNode that stores the next node of curr so that we can move forward in the list. and we also we need prev so we assign the prev = curr.
// At last we have to return the prev bcz curr becomes null.
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
  public:
      ListNode* reverseList(ListNode* head) {
          if(!head) return head;
  
          ListNode* prev = nullptr;
          ListNode* current = head;
  
          while(current){
              ListNode* nextNode = current->next;
              current->next = prev;
              prev = current;
              current = nextNode;
          }
          return prev;
      }
  };


// Approach :- Recursive approach

  // Recursion Method
// Think Approach :- We can also do this using recursion. The base case is when the head is null or head->next is null. In that case we return the head. Then we call the function recursively with head->next and store it in newHead. Then we take the front node which is head->next and assign front->next = head and head->next = null. At last we return newHead.
// Time Complexity :- O(n)
// Space Complexity :- O(n) (due to recursion stack)
class Solution {
  public:
      ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
       }
};  