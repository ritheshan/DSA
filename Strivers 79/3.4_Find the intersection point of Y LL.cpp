#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
       ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            unordered_set<ListNode*> seen;
    
            while (headA != nullptr) {
                seen.insert(headA);
                headA = headA->next;
            }
    
            while (headB != nullptr) {
                if (seen.find(headB) != seen.end()) {
                    return headB; // Found intersection
                }
                headB = headB->next;
            }
    
            return nullptr; // No intersection
        }
    };