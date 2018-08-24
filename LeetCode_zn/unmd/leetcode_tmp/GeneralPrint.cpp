//
// Created by Cookie on 2018/8/13.
//

#include "GeneralPrint.h"

namespace general{
    void print_List(ListNode* root){
        while (root){
            std::cout << root-> val;
            if (root->next)
                std::cout << " -> ";
            root = root -> next;
        }
        std::cout << std::endl;
    }
}