//
// Created by raj on 14/6/25.
//

#ifndef LISTNODE_H
#define LISTNODE_H



class ListNode {
public:
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};



#endif //LISTNODE_H
