
#include <iostream>
#include "QueueFactory.hpp"
using namespace std;

int main() {
    Queue<int>* listQueue = QueueFactory<int>::getQueue();
    Queue<int>* arrayQueue = QueueFactory<int>::getQueue(3); 


    listQueue->enqueue(10);
    listQueue->enqueue(20);
    listQueue->enqueue(30);
    arrayQueue->enqueue(10);
    arrayQueue->enqueue(20);
    arrayQueue->enqueue(30);

    cout << "LinkedQueue front: " << listQueue->front() << endl;
    cout << "arrayQueue front: " << arrayQueue->front() << endl;
    cout << "LinkedQueue back: " << listQueue->back() << endl;
    cout << "arrayQueue back: " << arrayQueue->back() << endl;

    listQueue->dequeue();
    arrayQueue->dequeue();
    cout << "After dequeue, listQueue front: " << listQueue->front() << ". But back stays the same: " << listQueue->back() << endl;
    cout << "After dequeue, arrayQueue front: " << arrayQueue->front()<< ". But back stays the same: " << arrayQueue->back() << endl;

    if (listQueue->isEmpty() == false){
        cout << "listQueue is not empty!" << endl;
    }
    if (arrayQueue->isEmpty() == false){
        cout << "arrayQueue is not empty!" << endl;
    }

    listQueue->clear();
    arrayQueue->clear();

    try { listQueue->dequeue(); } 
    catch (const string& msg) { cout << "Cleared listQueue: " << msg << endl; }

    try { arrayQueue->dequeue(); } 
    catch (const string& msg) { cout << "Cleared arrayQueue: " << msg << endl; }

}
