class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    vector<int>dq;
    int capacity;
    int front,rear,count;
    MyCircularDeque(int k) 
    {
        dq.resize(k);
        capacity=k;
        front=0;
        rear=capacity-1;
        count=0;
        
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) 
    {
        if(isFull())
            return false;
        front=(front-1+capacity)%capacity;
        dq[front]=value;
        count++;
        return true;
        
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) 
    {
        if(isFull())
            return false;
        rear=(rear+1)%capacity;
        dq[rear]=value;
        count++;
        return true;
        
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() 
    {
        if(isEmpty())
            return false;
          front=(front+1)%capacity;
        count--;
        return true;
        
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        rear=(rear-1+capacity)%capacity;
        count--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
               if (isEmpty())
            return -1;
        
        return dq[front];
 
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        
        return dq[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(count==0)
            return true;
        else
            return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(capacity==count)
            return true;
        else 
            return false;
    }
};

/**