#pragma once 

#include <stdlib.h>
#include <stddef.h>

template <typename E>
class Queue;


template<typename E>
class QueueNode {
    friend class Queue<E>;

    public:
        const E& element() const { return element_; }
        QueueNode* next() { return next_; }
        const QueueNode* next() const { return next_; }
    private:
        explicit QueueNode(const E& an_element)
            :element_(an_element), next_(nullptr) {}
        // disable default assignment and copy constructor
        const QueueNode& operator=(const QueueNode &);
        QueueNode(const QueueNode&);

        E element_;
        QueueNode* next_;
};

template <typename E>
class Queue {
    public:
        Queue(): 
            head_(nullptr), last_(nullptr), size_(0) {}
        ~Queue() { Clear(); }


        void Clear() {
            if (size_ > 0) {
                QueueNode<E> *node = head_;
                QueueNode<E> *next = node->next();
                for(;;) {
                    delete node;
                    node = next;
                    if (node == nullptr) break;
                    next = node->next();
                }

                head_ = last_ = nullptr;
                size_ = 0;
            }
        }

        size_t Size() const { return size_; }

        QueueNode<E>* Head() { return head_; }
        const QueueNode<E>* Head() const { return head_; }

        QueueNode<E>* Last() { return last_; }
        const QueueNode<E>* Last() const { return last_; }

        void Enqueue(const E& element) {
            QueueNode<E> * new_node = new QueueNode<E>(element);
            if (size_ == 0) {
                head_ = last_ = new_node;
                size_ = 1;
            } else {
                last_->next_ = new_node;
                last_ = new_node;
                size_ = size_ + 1;
            }
        }

        E* Dequeue() {
            if (size_ == 0) {
                return nullptr;
            }
            const QueueNode<E> * const old_head = head_;
            head_ = head_->next_;
            size_ = size_ - 1;
            if (size_ == 0 ) {
                head_ = last_ = nullptr;
            }
            E* element = new E(old_head->element());
            delete old_head;
            return element;
        }

        template <typename F>
        Queue *Map(F function) const {
            Queue* new_queue = new Queue();
            for (const QueueNode<E> * node = head_; 
                node != nullptr; node = node->next_) {
                    new_queue->Enqueue(function(node->element()));
            }
            return new_queue;
        }

    private:
        QueueNode<E> *head_;
        QueueNode<E> *last_;
        size_t size_;

        // disallow copy constructor and copy assignment
        Queue(const Queue&);
        const Queue & operator=(const Queue&);
};

