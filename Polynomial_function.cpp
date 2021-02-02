#include<iostream>

using namespace std;

struct Node{ 
    int coeff; 
    int pow; 
    struct Node *next; 
}; 

Node* addnode(Node* start, int coeff, int power){
    // Create a new node
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->pow = power;
    newNode->next = NULL;
 
    // If linked list is empty
    if (start == NULL){
        return newNode;
    }
    // If linked list has nodes
    Node* ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
    return start;
}

void removeDuplicates(Node* start){
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        // Compare the picked element
        // with rest of the elements
        while (ptr2->next != NULL) {
 
            // If powerer of two elements are same
            if (ptr1->pow == ptr2->next->pow) {
 
                // Add their coefficients and put it in 1st element
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
 
                // remove the 2nd element
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

Node* polyMultiply(Node* poly1, Node* poly2, Node* poly3){
 
    // Create two pointer and store the
    // address of 1st and 2nd polynomials
    Node *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, power;
 
            // Multiply the coefficient of both
            // polynomials and store it in coeff
            coeff = ptr1->coeff * ptr2->coeff;
 
            // Add the powerer of both polynomials
            // and store it in power
            power = ptr1->pow + ptr2->pow;
 
            // Invoke addnode function to create
            // a newNode by passing three parameters
            poly3 = addnode(poly3, coeff, power);
 
            // move the pointer of 2nd polynomial
            // two get its next term
            ptr2 = ptr2->next;
        }
 
        // Move the 2nd pointer to the
        // starting point of 2nd polynomial
        ptr2 = poly2;
 
        // move the pointer of 1st polynomial
        ptr1 = ptr1->next;
    }
 
    // this function will be invoke to add
    // the coefficient of the elements
    // having same powerer from the resultant linked list
    removeDuplicates(poly3);
    return poly3;
}

Node* polyAdd(struct Node *poly1, struct Node *poly2, struct Node *poly){ 
    while(poly1 && poly2) { 
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is 
        // and move its pointer
        int power, coef; 
        if(poly1->pow > poly2->pow) { 
            power = poly1->pow; 
            coef = poly1->coeff; 
            poly = addnode(poly, coef, power);
            poly1 = poly1->next; 
        } 
          
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is 
        // and move its pointer 
        else if(poly1->pow < poly2->pow) { 
            power = poly2->pow; 
            coef = poly2->coeff; 
            poly = addnode(poly, coef, power);
            poly2 = poly2->next; 
        } 
          
        // If power of both polynomial numbers is same then add their coefficients 
        else{ 
            power = poly1->pow; 
            coef = poly1->coeff+poly2->coeff; 
            poly = addnode(poly, coef, power);
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
    }
    return poly;
} 

void printList(struct Node* ptr){
    while (ptr->next != NULL) {
        cout << ptr->coeff << "x^" << ptr->pow ;
       if( ptr->next!=NULL && (ptr->next->coeff >=0))
          cout << " + ";
 
        ptr = ptr->next;
    }
    cout << ptr->coeff << "\n";
}

int main(){
    Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL, *poly = NULL;
    int opt, max_pow, coef, power = 1;

    // Creation of 1st Polynomial
    cout<<"\nEnter 1st polynomial(Last term should be x^0)\n";

    while(power != 0){
        cout << "Enter coefficient and power\n";
        cin >> coef >> power;
        poly1 = addnode(poly1, coef, power);
    }
 
    // Creation of 2nd polynomial

    cout<<"\nEnter 2nd polynomial(Last term should be x^0)\n";
    
    power = 1;
    while(power!=0){
        cout<<"Enter coefficient and power\n";
        cin>>coef>>power;
        poly2 = addnode(poly2, coef, power);
    }
    
    cout << "1st Polynomial:- ";
    printList(poly1);
 
    
    cout << "2nd Polynomial:- ";
    printList(poly2);

    while(true){
        cout<<"Enter\n1.Addition\n2.Multiplication\n0.Exit\nchoice: ";
        cin>>opt;

        switch(opt){
            case 1:
                poly = polyAdd(poly1, poly2, poly);
                cout<<"\nAdded polynomial: ";
                printList(poly);
                break;
            
            case 2:
                poly3 = polyMultiply(poly1, poly2, poly3);
                cout << "Resultant Polynomial:- ";
                printList(poly3);
                break;
            case 0:
                cout<<"\n\nThank You\n\n";
                exit(0);
                break;
            default:
                cout<<"\nEnter a valid choice\n";
                break;
        }
    }
    return 0;
}