// Leetcode:- 23. Merge k Sorted Lists

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
// class Solution {
// public:

// ---------------------Better approach---------------------
    // ListNode* mergeList(ListNode* l1, ListNode* l2){

    //     ListNode* dummyNode = new ListNode(-1);
    //     ListNode* current = dummyNode;

    //     while(l1 && l2){

    //         if(l1->val < l2->val){
    //             current->next = l1;
    //             current = l1;
    //             l1 = l1->next;
    //         }
    //         else if(l1->val > l2->val){
    //             current->next = l2;
    //             current = l2;
    //             l2 = l2->next;
    //         }
    //         else{
    //             current->next = l1;
    //             current = l1;
    //             l1 = l1->next;

    //             current->next = l2;
    //             current = l2;
    //             l2 = l2->next;
    //         }
    //     }
    //     // If Loop break then remaining Nodes
    //     if(l1) current->next =  l1;
    //     else current->next = l2;
    //     return dummyNode->next;
    // }

    class Solution {
        public:
            ListNode* mergeKLists(vector<ListNode*>& lists) {
                // Min heap to store (value, pointer to node)
                priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
                // Push head of each list into the min heap
                for (int i = 0; i < lists.size(); ++i) {
                    if (lists[i]) {
                        pq.push({lists[i]->val, lists[i]});
                    }
                }
        
                // Dummy node to form the merged list
                ListNode* dummy = new ListNode(-1);
                ListNode* current = dummy;
        
                while (!pq.empty()) {
                    auto [val, node] = pq.top();
                    pq.pop();
        
                    // Add the smallest node to result list
                    current->next = node;
                    current = current->next;
        
                    // If the node has a next, push it into the heap
                    if (node->next) {
                        pq.push({node->next->val, node->next});
                    }
                }
        
                return dummy->next;
            }
        };
        
                
                // if(lists.empty()) return nullptr;
        
                // ListNode* merged = nullptr;
        
                // for(auto list : lists){
        
                //     merged = mergeList(merged, list);
                // }
                // return merged;
        
        // ------------------------Brute Foce-------------------------
        // Time Complexity :- O(nLogn)
        // space Complexity :- O(N)
                // vector<int> values;
        
                // for(auto list: lists){
                //     while(list){
                //         values.push_back(list->val);
                //         list = list->next;
                //     }
                // }
        
                // sort(values.begin(), values.end());
        
                // // Convert the Array to LL
        
                // ListNode* dummy = new ListNode(-1);
                // ListNode* current = dummy;
        
                // for(int val : values){
                //     current->next = new ListNode(val);
                //     current =  current->next;
                // }
                // return dummy->next;
        //     }
        // };