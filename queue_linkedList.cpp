/*---------------------------Queue using Linked List---------------------------*/
#include <iostream>

using namespace std;

struct Node { 
    int data; 
    Node* next; 
    Node(int d) 
    { 
        data = d; 
        next = NULL; 
    } 
}; 
  
class queue { 

public:
    Node *front, *rear; 
    queue() 
    { 
        front = rear = NULL; 
    } 
    void enQueue(int x) 
    { 
  
        // Create a new LL node 
        Node* temp = new Node(x); 
  
        // If queue is empty, then 
        // new node is front and rear both 
        if (rear == NULL) { 
            front = rear = temp; 
            return; 
        } 
  
        // Add the new node at 
        // the end of queue and change rear 
        rear->next = temp; 
        rear = temp; 
    } 
  
    // Function to remove 
    // a key from given queue q 
    void deQueue() 
    { 
        // If queue is empty, return NULL. 
        if (front == NULL) 
            return; 
  
        // Store previous front and 
        // move front one node ahead 
        Node* temp = front; 
        front = front->next; 
  
        // If front becomes NULL, then 
        // change rear also as NULL 
        if (front == NULL) 
            rear = NULL; 
  
        delete (temp); 
    } 

    void display(){
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<"  <--  ";
            temp=temp->next;
        }
        cout << endl;
    }
};

int main(){
    int opt, data;
    
    queue q; 
    while(true){
        cout << "\nEnter\n1. Add element to queue\n2. Remove First element from queue\n3. Display queue\n0. Exit\nChoice: ";
        cin >> opt;

        switch(opt){
            case 1:
                cout << "\nEnter data: ";
                cin >> data;
                q.enQueue(data);
                break;
            
            case 2:
                q.deQueue();
                break;

            case 3:
                q.display();
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