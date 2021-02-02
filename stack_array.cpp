/*---------------------Stack using array-------------------------*/
#include<iostream>

using namespace std;

#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX];

    Stack() {top = -1;}
    bool push(int x) {
        if (top >= (MAX - 1)) { 
        cout << "\nStack Overflow\n"; 
        return false; 
        } 
        else { 
            a[++top] = x; 
            // cout << x << " pushed into stack\n"; 
            return true; 
        } 
    }

    int pop() {
        if (top < 0) { 
        cout << "\nStack Underflow\n"; 
        return 0; 
        } 
        else { 
            int x = a[top--]; 
            return x; 
        } 
    }

    bool isempty() {
        return (top < 0); 
    }

    void display() {
        int i;
        if(isempty()){
            cout<<"\nstack is empty";
        }
        else{
            for(i = top;i >= 0;i--)
                cout<<a[i]<<endl;
        }
    }
};

int main(){
    class Stack s; 
    int opt,ele;
    bool choice = true;
    while(choice == true) {
        cout << "Enter\n1. Enter element\n2. Remove element\n3. Display Stack\n0. Exit\nChoice: ";
        cin >> opt;
        switch(opt) {
            case 1:
                cout << "\nEnter an element(number): ";
                cin >> ele;
                s.push(ele);
                break;
            
            case 2:
                s.pop();
                break;
            
            case 3:
                s.display();
                break;
            
            case 0:
                choice = false;
                break;
            
            default:
                cout << "\nEnter a valid choice.";
                break;
        }
    }
    return 0;
}