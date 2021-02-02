/*
    PSEUDO CODE
    1) enter the number of queries
    2) enter the query ie 1 for pushing book in the shelf and -1 for poping from the shelf
    3) if 1 is entered :
        Enter the number which is to be pasted on the book
        check whether the stack is full
        if stack is not full then increment the top variable and assign the number in a[number]
        else print stack overflow

    4) else if -1 is entered : 
        if stack is empty print kuchbhi
        else print the top and remove that book from stack.
        
*/

#include <iostream>
using namespace std;
#define MAX 1000

class Stack {
private: 
    int top;

public:
    int a[MAX];

    Stack() {top = -1;}

    bool isempty() {
        return (top < 0); 
    }
    bool isfull(){
        return (top >= (MAX - 1));
    }

    void push(int x) {

        if ( isfull() == true ) {             //stack overflow case
        cout << "\nStack Overflow\n";

        } 
        else { 
            a[++top] = x;                   //increment stack top and assign value to it
             
        } 
    }

    int pop() {
        if (isempty()==true) {                     //stack underflow case
        cout << "kuchbhi?" << endl; 
        return 0; 
        } 
        else { 
            int x = a[top--]; 
            return x; 
        } 
    }
};

int main(){
    class Stack bookshelf;
    int number_of_queries, number ,query;

    cin>>number_of_queries;

    while(number_of_queries-- > 0){
        
        cin>>query;             // 1 for pushing books in bookshelf and -1 for poping books from shelf
        if(query == 1){         //for push operation

            cin>>number;        //number to be pasted on the book
            bookshelf.push(number);

        }else if(query == -1){                  //for pop operation

            if(bookshelf.isempty()){            //if bookshelf is empty
                cout << "kuchbhi?" << endl;
            }
            else{
                int x = bookshelf.pop();
                cout << x << endl;
            }
        }
    }
    return 0;
}