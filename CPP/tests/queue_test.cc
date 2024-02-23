#include "src/main/queue/queue.h"
#include<iostream>
#include <gtest/gtest.h>

class QueueTest: public testing::Test {
    protected:
        void SetUp() override {
            q1_.Enqueue(1);
            q2_.Enqueue(2);
            q2_.Enqueue(3);
        }

        void TearDown() override {
            std::cout << "Not Defined";
        }

        static int Double(int n) { return 2 * n; }

        void MapTester(const Queue<int>* q) {
            // Creates a new queue, where each element is twice as big as the
            // corresponding one in q.
            const Queue<int>* const new_q = q->Map(Double);

            // Verifies that the new queue has the same size as q.
            ASSERT_EQ(q->Size(), new_q->Size());

            // Verifies the relationship between the elements of the two queues.
            for (const QueueNode<int>*n1 = q->Head(), *n2 = new_q->Head();
                n1 != nullptr; n1 = n1->next(), n2 = n2->next()) {
                EXPECT_EQ(2 * n1->element(), n2->element());
            }

            delete new_q;
        }

        // Declares the variables your tests want to use.
        Queue<int> q0_;
        Queue<int> q1_;
        Queue<int> q2_;
};

TEST_F(QueueTest, DefaultConstructor) {
  // You can access data in the test fixture here.
  EXPECT_EQ(0u, q0_.Size());
}


TEST_F(QueueTest, Dequeue) {
  int* n = q0_.Dequeue();
  EXPECT_TRUE(n == nullptr);

  n = q1_.Dequeue();
  ASSERT_TRUE(n != nullptr);
  EXPECT_EQ(1, *n);
  EXPECT_EQ(0u, q1_.Size());
  delete n;

  n = q2_.Dequeue();
  ASSERT_TRUE(n != nullptr);
  EXPECT_EQ(2, *n);
  EXPECT_EQ(1u, q2_.Size());
  delete n;
}

TEST_F(QueueTest, Map) {
  MapTester(&q0_);
  MapTester(&q1_);
  MapTester(&q2_);
}