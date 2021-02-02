/*----------------------------------Queue Using Array------------------------*/
#include<iostream>

using namespace std;

class Queue { 
public:
    int front, rear, capacity; 
    int* queue; 
    Queue(int c) 
    { 
        front = rear = 0; 
        capacity = c; 
        queue = new int; 
    } 
  
    ~Queue() { 
        delete[] queue; 
    } 
  
    // function to insert an element 
    // at the rear of the queue 
    void queueEnqueue(int data) 
    { 
        // check queue is full or not 
        if (capacity == rear) { 
            cout<<"\nQueue is full\n"; 
            return; 
        } 
  
        // insert element at the rear 
        else { 
            queue[rear] = data; 
            rear++; 
        } 
        return; 
    } 
  
    // function to delete an element 
    // from the front of the queue 
    void queueDequeue() 
    { 
        // if queue is empty 
        if (front == rear) { 
            cout<<"\nQueue is  empty\n"; 
            return; 
        } 
  
        // shift all the elements from index 2 till rear 
        // to the left by one 
        else { 
            for (int i = 0; i < rear - 1; i++) { 
                queue[i] = queue[i + 1]; 
            } 
  
            // decrement rear 
            rear--; 
        } 
        return; 
    } 
  
    // print queue elements 
    void queueDisplay() 
    { 
        int i; 
        if (front == rear) { 
            cout<<"\nQueue is Empty\n"; 
            return; 
        } 
  
        // traverse front to rear and print elements 
        for (i = front; i < rear; i++) { 
            cout << queue[i] << "  <--  "; 
        } 
        cout << endl;
        return; 
    } 
  
  
    
}; 

int main(){
    int cap, opt, data;
    cout<<"\nEnter max size of queue\n";
    cin>>cap;
    Queue q(cap); 
    while(true){
        cout << "\nEnter\n1. Add element to queue\n2. Remove First element from queue\n3. Display queue\n0. Exit\nChoice: ";
        cin >> opt;

        switch(opt){
            case 1:
                cout << "\nEnter data: ";
                cin >> data;
                q.queueEnqueue(data);
                break;
            
            case 2:
                q.queueDequeue();
                break;

            case 3:
                q.queueDisplay();
                break;

            case 0:
                cout<<"\n\nThank You\n\n";
                exit(0);
                break;

            default:
                cout << "\nEnter a valid choice\n";
                break;

        }
    }
    return 0;
}