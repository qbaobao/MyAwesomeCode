class MyCircularQueue {
public:
    int len;
    int rear;
    int front;
    int count;
    int* vec;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        len = k;
        front = rear = 0;
        count = 0;
        vec = new int[k];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (count == len) {
            return false;
        }
        vec[rear] = value;
        rear = (rear + 1) % len;
        count++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (count == 0) {
            return false;
        }
        vec[front] = 0xffff;
        front = (front + 1) % len;
        count--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : vec[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : vec[(rear + len - 1) % len];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count == len;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */