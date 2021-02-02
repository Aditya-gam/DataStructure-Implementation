/*--------------------Stack using linked list--------------------------*/
#include <iostream>

using namespace std;

struct Node {
   int data;
   struct Node *next;
};

struct Node* top = NULL;

void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}

void pop() {
   if(top==NULL)
   cout<<"\nStack Underflow"<<endl;
   else {
      cout<<"\nThe popped element is "<< top->data <<endl;
      top = top->next;
   }
}

void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"\nstack is empty";
   else {
      ptr = top;
      cout<<"\nStack elements are:\n";
      while (ptr != NULL) {
         cout<< ptr->data <<endl;
         ptr = ptr->next;
      }
   }
   cout<<endl;
}

int main() {
   int val,opt;
   bool ch = true;
   
   
   while(ch == true){
      cout<<"\n1) Push in stack\n2) Pop from stack\n3) Display stack\n0) Exit\n";
      cout<<"Enter choice: "<<endl;
      cin>>opt;
      switch(opt) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 0: {
            // cout<<"Exit"<<endl;
            ch = false;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }
   return 0;
}