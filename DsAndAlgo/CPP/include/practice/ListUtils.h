//
// Created by raj on 14/6/25.
//

#ifndef LISTUTILS_H
#define LISTUTILS_H
#include <iostream>
#include "ListNode.h"


class ListUtils {
public:
    static ListNode* CreateList(std::vector<int> array) {
        if (array.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(array[0]);
        ListNode* current = head;
        for (size_t i = 1; i < array.size(); ++i) {
            current->next = new ListNode(array[i]);
            current = current->next;
        }
        return head;
    }

    static void PrintList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif //LISTUTILS_H