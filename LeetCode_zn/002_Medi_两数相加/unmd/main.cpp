#include <iostream>
//#include <unordered_map>
//#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = & preHead;
        int extra = 0;
        while (l1 || l2 || extra){
            int sum = (l1? l1->val : 0) + (l2 ? l2 ->val: 0) + extra;
            extra = sum / 10;
            p -> next = new ListNode(sum % 10);
            p = p->next;

            l1 = l1 ? l1->next: l1;
            l2 = l2 ? l2->next: l2;
        }
        return preHead.next;
    }
};


void print_List(ListNode* root){
    while (root){
        std::cout << root-> val;
        if (root->next)
            std::cout << " -> ";
        root = root -> next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode L1_0(2);
    ListNode L1_1(4);
    ListNode L1_2(3);
    L1_0.next = &L1_1;
    L1_1.next = &L1_2;

    ListNode L2_0(5);
    ListNode L2_1(6);
    ListNode L2_2(4);
    L2_0.next = &L2_1;
    L2_1.next = &L2_2;


    print_List( Solution().addTwoNumbers(&L1_0, &L2_0) );
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}/*output:
7 -> 0 -> 8
Hello, World!
 */