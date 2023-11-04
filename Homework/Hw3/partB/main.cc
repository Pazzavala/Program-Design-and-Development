// this file is just to write some sample code that uses the class
// use this file to test out the class and figure out the expected functionality
#include "queue.h"

// we've given you some sample code to start out with
// feel free to modify this file as much as you want
int main()
{
    // create a queue of capacity 5
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "The front element is " << q.peek() << endl;

    cout << "need to dequeue " << q.indexOf(1) << " elements before 1 is at the front" << endl;
    cout << "need to dequeue " << q.indexOf(2) << " elements before 2 is at the front" << endl;
    cout << "need to dequeue " << q.indexOf(3) << " elements before 3 is at the front" << endl;
    cout << "need to dequeue " << q.indexOf(4) << " elements before 4 is at the front" << endl;

    q.dequeue();

    q.enqueue(4);

    cout << "The queue size is " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.isEmpty()) {
      cout << "The queue is empty\n" << q.size(); //exits with underflow
    }
    else if (q.isFull()) {
      cout << "The queue is full\n";
    }
    else {
      cout << "The queue is not empty\n";
    }

    q.enqueue(24);
    q.enqueue(42);
    q.enqueue(38);
    q.enqueue(15);
    cout << "need to dequeue " << q.indexOf(15) << " elements before 15 is at the front" << endl;
    cout << "need to dequeue " << q.indexOf(38) << " elements before 38 is at the front" << endl;
    cout << "Running bubble sort algorithm: \n";
    q.bubbleSort();
    cout << "\n";
    q.clear();

    
    // cout << "Peek of empty: " << q.peek() << endl; // Cant do this its underflow

    q.enqueue(24);
    q.enqueue(42);
    q.enqueue(38);
    q.enqueue(15);

    cout << "Index of non Exitent: " << q.indexOf(-1) << endl;

    cout << "Running merge sort algorithm: \n";
    q.mergeSort();
    cout << "\n";
    q.clear();

    return 0;
}
