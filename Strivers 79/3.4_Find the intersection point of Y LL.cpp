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
// using difference of lengths of the two linked list
   
    int getDifference(ListNode* head1, ListNode* head2) {
        int len1 = 0, len2 = 0;
        while (head1 != NULL || head2 != NULL) {
            if (head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if (head2 != NULL) {
                ++len2; head2 = head2->next;
            }
        }
        return len1 - len2; // if difference is neg-> length of list2 > length of list1 else vice-versa
    }
   
   //utility function to check presence of intersection
ListNode* intersectionPresent(ListNode* head1, ListNode* head2) {
    int diff = getDifference(head1,head2);
           if(diff < 0) 
               while(diff++ != 0) head2 = head2->next; 
           else while(diff-- != 0) head1 = head1->next;
           while(head1 != NULL) {
               if(head1 == head2) return head1;
               head2 = head2->next;
               head1 = head1->next;
           }
           return head1;
   
   
   }
   

// use of two pointers
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}