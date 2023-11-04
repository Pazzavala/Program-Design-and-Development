#include "queue.h"

#include "gtest/gtest.h"

class QueueTest : public ::testing::Test {
 public:
  void SetUp() {
    // code here will execute just before the test ensues
    q1 = Queue(q1Cap);
    q2 = Queue(q2Cap);
    q3 = Queue();
    zeroQ = Queue(zeroCap);

    for (int i = 0; i < q1.getCapacity(); i++) q1.enqueue(i);

    for (int i = 0; i < q2.getCapacity(); i++) q2.enqueue(i * -1);
  }
  void TearDown() {}

 protected:
  Queue q1;
  Queue q2;
  Queue q3;
  Queue zeroQ;
  int q1Cap = 5;
  int q2Cap = 20;
  int zeroCap = 0;
};

TEST_F(QueueTest, QueueConstructorTest) {
  EXPECT_EQ(q1.size(), q1Cap) << "Queue q1 not created with correct size";
  EXPECT_EQ(q2.size(), q2Cap) << "Queue q2 not created with correct size";
  EXPECT_EQ(q3.size(), 0) << "Queue q3 not created with correct size";
  EXPECT_EQ(q1.getCapacity(), q1Cap)
      << "Queue q1 not created with correct capacity";
  EXPECT_EQ(q2.getCapacity(), q2Cap)
      << "Queue q2 not created with correct capacity";
  EXPECT_EQ(q3.getCapacity(), 1000)
      << "Queue q3 not created with correct capacity";

  Queue q5(10);
  EXPECT_NE(q5.size(), 10) << "Queue q5 not created with correct size";
  EXPECT_EQ(q5.getCapacity(), 10)
      << "Queue q5 not created with correct capacity";

  Queue q6(6.6);
  EXPECT_NE(q6.size(), 6) << "Queue q6 not created with correct size";
  EXPECT_EQ(q6.getCapacity(), 6)
      << "Queue q6 not created with correct capacity";

  Queue asciiQ('8');
  EXPECT_NE(asciiQ.size(), 8) << "Queue asciiQ not created with correct size";
  EXPECT_EQ(asciiQ.getCapacity(), 56)
      << "Queue asciiQ not created with correct capacity";
}

TEST_F(QueueTest, QueueDestructor) {
  Queue* qBye = new Queue;
  delete qBye;
  ASSERT_DEATH({ qBye->enqueue(100); }, ".*");
}

TEST_F(QueueTest, QueueConstructorInvalidSizeTest) {
  EXPECT_THROW({ Queue negQ = Queue(-5); }, std::bad_array_new_length);
}

TEST_F(QueueTest, QueueCopyConstructorTest) {
  Queue copyQ1 = Queue(q1);
  Queue copyQ2 = Queue(q2);

  EXPECT_EQ(copyQ1.size(), q1.size());
  EXPECT_EQ(copyQ1.getCapacity(), q1.getCapacity());

  for (int i = 0; i < q1.size(); i++) {
    EXPECT_EQ(copyQ1.indexOf(i), q1.indexOf(i))
        << "Queue q1 not copied correctly to copyQ1";
  }

  // If making changes to one should make changes to other
  for (int i = 0; i < q1.size(); i++) {
    copyQ1.dequeue();
  }

  EXPECT_NE(copyQ1.size(), q1.size());
  EXPECT_EQ(copyQ2.size(), q2.size());
  EXPECT_EQ(copyQ2.getCapacity(), q2.getCapacity());

  for (int i = 0; i < q2.size(); i++) {
    EXPECT_EQ(copyQ2.indexOf(i), q2.indexOf(i))
        << "Queue q2 not copied correctly to copyQ2";
  }
}

TEST_F(QueueTest, QueueAssignmentOperatorTest) {
  // Check if types are correct
  Queue copyQ1 = q1;
  Queue copyQ2 = q2;

  EXPECT_EQ(copyQ1.size(), q1.size())
      << "Queue q1 not assigned correctly to copyQ1";
  EXPECT_EQ(copyQ2.size(), q2.size())
      << "Queue q2 not assigned correctly to copyQ2";
}

TEST_F(QueueTest, QueueDequeueTest) {
  int qElem;
  int qSize = q1.size();
  for (int i = 0; i < qSize; i++) {
    qElem = q1.dequeue();
    EXPECT_EQ(qElem, i) << "Dequeued element doesn't match expected";
  }

  EXPECT_EQ(q1.size(), 0)
      << "Queue q1 didn't return correct size";  // why no work??
  EXPECT_NE(q1.size(), q1Cap) << "Queue q1 didn't return correct size";

  qSize = q2.size();
  for (int i = 0; i < qSize; i++) {
    qElem = q2.dequeue();
    EXPECT_EQ(qElem, i * -1) << "Dequeued element doesn't match expected";
  }

  EXPECT_EQ(q2.size(), 0) << "Queue q2 didn't return correct size";
  EXPECT_NE(q2.size(), q2Cap) << "Queue q2 didn't return correct size";
}

TEST_F(QueueTest, QueueDequeueFromEmptyQueue) {
  Queue queue;
  EXPECT_EXIT({ queue.dequeue(); }, testing::ExitedWithCode(1), ".*");
}

TEST_F(QueueTest, QueueDequeueOutputTest) {
  std::string expected_out_1 = "Removing 0\n";
  std::string expected_out_2 = "Removing 1\n";
  std::string expected_out_3 = "Removing 2\n";
  std::string expected_out_4 = "Removing 3\n";
  std::string expected_out_5 = "Removing 4\n";

  testing::internal::CaptureStdout();
  q1.dequeue();
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  q1.dequeue();
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  q1.dequeue();
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  q1.dequeue();
  std::string output4 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  q1.dequeue();
  std::string output5 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);
  EXPECT_EQ(output5, expected_out_5);
}

TEST_F(QueueTest, QueueEnqueueTest) {
  q1.clear();
  q2.clear();

  for (int i = 0; i < q1.getCapacity(); i++) q1.enqueue(i);
  for (int i = 0; i < q2.getCapacity(); i++) q2.enqueue(i);

  EXPECT_EQ(q1.size(), q1Cap) << "Queue q1 not created with correct size";
  EXPECT_EQ(q2.size(), q2Cap) << "Queue q2 not created with correct size";
}

TEST_F(QueueTest, QueueEnqueueToFullQueue) {
  EXPECT_EXIT({ q1.enqueue(100); }, testing::ExitedWithCode(1), ".*");
}

TEST_F(QueueTest, QueueEnqueueOutputTest) {
  q1.clear();
  std::string expected_out_1 = "Inserting 100\n";
  std::string expected_out_2 = "Inserting -1\n";
  std::string expected_out_3 = "Inserting 2\n";
  std::string expected_out_4 = "Inserting 3\n";
  std::string expected_out_5 = "Inserting 4\n";

  testing::internal::CaptureStdout();
  q1.enqueue(100);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  q1.enqueue(-1);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  q1.enqueue(2);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  q1.enqueue(3);
  std::string output4 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  q1.enqueue(4);
  std::string output5 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);
  EXPECT_EQ(output5, expected_out_5);
}

TEST_F(QueueTest, QueuePeekTest) {
  int peekElem;
  peekElem = q1.peek();
  EXPECT_EQ(peekElem, 0);

  peekElem = q2.peek();
  EXPECT_EQ(peekElem, 0);

  // Remove Element and peek again
  q1.dequeue();
  q2.dequeue();

  peekElem = q1.peek();
  EXPECT_EQ(peekElem, 1);

  peekElem = q2.peek();
  EXPECT_EQ(peekElem, -1);

  // peek empty?
}

TEST_F(QueueTest, QueueIndexOfTest) {
  int index;
  for (int i = 0; i < q1.size(); i++) {
    index = q1.indexOf(i);
    EXPECT_EQ(index, i) << "Returned index doesn't match element index";
  }

  EXPECT_EQ(q1.indexOf(q1Cap), -1)
      << "Returned index doesn't match element index";

  for (int i = 0; i < q2.size(); i++) {
    index = q2.indexOf(i * -1);
    EXPECT_EQ(index, i) << "Returned index doesn't match element index";
  }

  // indexOf non exitent value
  index = q2.indexOf(-43);
  EXPECT_EQ(index, -1) << "Returned index doesn't match element index";
}

TEST_F(QueueTest, QueueSizeTest) {
  EXPECT_EQ(q1.size(), q1Cap) << "Queue q1 didn't return correct size";
  EXPECT_EQ(q2.size(), q2Cap) << "Queue q2 didn't return correct size";
  // Before enqueueing anything
  EXPECT_EQ(q3.size(), 0) << "Queue q2 didn't return correct size";
  EXPECT_EQ(zeroQ.size(), zeroCap) << "Queue q2 didn't return correct size";
}

TEST_F(QueueTest, QueueIsEmptyTest) {
  EXPECT_EQ(q1.isEmpty(), false) << "Queue q1 is not empty wrong bool.";
  EXPECT_EQ(q2.isEmpty(), false) << "Queue q2 is not empty wrong bool.";

  q1.clear();
  q2.clear();

  EXPECT_EQ(q1.isEmpty(), true) << "Queue q1 is empty wrong bool.";
  EXPECT_EQ(q2.isEmpty(), true) << "Queue q2 is empty wrong bool.";
  EXPECT_EQ(zeroQ.isEmpty(), true) << "Queue zeroQ is empty wrong bool.";
}

TEST_F(QueueTest, QueueIsFullTest) {
  EXPECT_EQ(q1.isFull(), true) << "Queue q1 is full wrong bool.";
  EXPECT_EQ(q2.isFull(), true) << "Queue q2 is full wrong bool.";
  EXPECT_EQ(zeroQ.isFull(), true) << "Queue zeroQ is empty wrong bool.";

  q1.clear();
  q2.clear();

  EXPECT_EQ(q1.isFull(), false) << "Queue q1 is not full wrong bool.";
  EXPECT_EQ(q2.isFull(), false) << "Queue q2 is not full wrong bool.";
}

TEST_F(QueueTest, QueueGetCapacityTest) {
  EXPECT_EQ(q1.getCapacity(), q1Cap) << "Queue q1 didn't return correct size";
  EXPECT_EQ(q2.getCapacity(), q2Cap) << "Queue q2 didn't return correct size";
  EXPECT_EQ(q3.getCapacity(), 1000) << "Queue q2 didn't return correct size";
  EXPECT_EQ(zeroQ.getCapacity(), zeroCap)
      << "Queue q2 didn't return correct size";
}

TEST_F(QueueTest, QueueClearTest) {
  q1.clear();
  q2.clear();
  zeroQ.clear();

  EXPECT_EQ(q1.isFull(), false) << "Queue q1 was no cleared";
  EXPECT_EQ(q2.isFull(), false) << "Queue q2 was no cleared";

  EXPECT_EQ(q1.isEmpty(), true) << "Queue q1 was no cleared";
  EXPECT_EQ(q2.isEmpty(), true) << "Queue q2 was no cleared";
  EXPECT_EQ(zeroQ.isEmpty(), true) << "Queue zeroQ was no cleared";

  EXPECT_EQ(q1.size(), 0) << "Queue q1 was no cleared";
  EXPECT_EQ(q2.size(), 0) << "Queue q2 was no cleared";
  EXPECT_EQ(zeroQ.size(), 0) << "Queue zeroQ was no cleared";
}

TEST_F(QueueTest, QueueBuddleSortTest) {
  Queue sortQ(10);
  for (int i = sortQ.getCapacity(); i > 0; i--) sortQ.enqueue(i);

  sortQ.bubbleSort();

  int qElem;
  for (int i = 1; i <= q1.getCapacity(); i++) {
    qElem = sortQ.dequeue();
    EXPECT_EQ(qElem, i) << "Queue q2 was no cleared";
  }
}

TEST_F(QueueTest, QueueMergeSortTest) {
  Queue sortQ(10);
  for (int i = sortQ.getCapacity(); i > 0; i--) sortQ.enqueue(i);

  sortQ.mergeSort();

  int qElem;
  for (int i = 1; i <= q1.getCapacity(); i++) {
    qElem = sortQ.dequeue();
    EXPECT_EQ(qElem, i) << "Queue q2 was no cleared";
  }
}

// TEST_F(QueueTest, QueueMergeSortSuccessTest) {
//   Queue sortQ(10);
//   for (int i = sortQ.getCapacity(); i > 0; i--) sortQ.enqueue(i);
//   EXPECT_EXIT({sortQ.mergeSort();}, testing::ExitedWithCode(0), ".*");
// }
