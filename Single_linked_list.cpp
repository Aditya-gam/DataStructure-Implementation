#include<iostream>
#include<string>
#include <climits>

using namespace std;

typedef struct database {   
   string name;
   int id;
   int salary;
   int tenure;
   struct database *next;
}Node;

int checkId(Node *first, int requiredId) {
   int index = 0;
   while (first != NULL){
      if (first->id == requiredId){
         return index;
      }
      index += 1;
      first = first->next;
   }
   return (-1);
}

Node *accept(Node *first) {
   Node *a = new Node();
   int tempId;

   cout << "\n    Enter Id : ";
   cin >> tempId;

   if(checkId(first, tempId) == -1) {
      a->id = tempId;

      cout << "    Enter Name : ";
      cin >> a->name;
      
      cout << "    Enter salary : ";
      cin >> a->salary;
      
      cout << "    Enter Tenure : ";
      cin >> a->tenure;

      a->next = NULL;
      return (a);
   }
   else {
       cout << "    Id already exists." << endl;
       return NULL;
   }
   
}

int listLength(Node *first) {
   if (first == NULL){
      return 0;
   }
   else{
      int count = 0;
      while (first != NULL){
         count += 1;
         first = first->next;     
      }
      return count;     
   }
}

void insert_Start(Node **first) {
   Node *temp = accept(*first);
   if(temp != NULL){
      temp->next = *first;
      *first = temp;
   }
}

void insert_End(Node **first) {
   Node *temp;
   temp = *first;
   while(temp->next != NULL){
      temp = temp->next;
   }
   temp->next = accept(*first);  
}

void insert_Mid(Node **first, int position) {
   Node *temp = *first, *store, *check = accept(*first);
   if (check != NULL){
      int count = 0;
      while(count < position-1){
         count ++;
         temp = temp->next;
      }
      store = temp->next;

      temp->next = check;
      temp = temp->next;
      temp->next = store;
   }
}

void insert(Node **first) {

   if (*first == NULL){
      *first = accept(*first);
   }

   else{
      int length = listLength(*first), index = -1;
      while (index < 0 || index > length){
         cout << "    Enter the index at which to be added (0, " << length << ") : ";// Enter only number
         cin >> index;
         while(cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            
            cin>>index;
         }
      }
      if (index == length){
         index = -1;
      }
      
      switch (index){
         case 0:
               insert_Start(first);
               break;

         case -1:
               insert_End(first);
               break;

         default:
               insert_Mid(first, index);
               break;
      }
   }

    
}

void recDisplaySingle(Node *first, int id) {
   Node *temp = first;
   while(temp != NULL){
      if(temp->id == id){
         break;
      }
      temp = temp->next;
   }
     

   string str = "    ";
   str += to_string(temp->id);
   while (str.length() < 11){
      str += " ";
         
   }
   str += temp->name;
   while (str.length() < 31){
      str += " ";
   }
      
   str += to_string(temp->salary);
   while(str.length() < 42){
      str += " ";
   }

   str += to_string(temp->tenure);
   cout << str << endl;
   
}

void display(Node *first, bool single, int id) {
   if (first == NULL){
      cout << "\n    List is Empty.\n";
   }
   else{
      cout << "\n\n    Id     Name                Salary     Tenure" << endl;
      if (single){
         recDisplaySingle(first, id);
      }
      else{
         Node *temp = first;
         while (temp != NULL){
            string str = "    ";
            str += to_string(temp->id);
            while (str.length() < 11){
               str += " ";
               
            }
            str += temp->name;
            while (str.length() < 31){
               str += " ";
            }
            
            str += to_string(temp->salary);
            while(str.length() < 42){
               str += " ";
            }

            str += to_string(temp->tenure);
            cout << str << endl;

            temp = temp->next;
         }
      }
   }
}

void search(Node *first) {
   Node *temp = first;
   int opt;
   cout << "Enter\n1. search by name\n2. search by id\nchoice: ";
   cin >> opt;
   if(opt == 1){
      string nme;
      cout << "\nEnter name to be search: ";
      cin >> nme;
      while(temp != NULL){
         if(temp->name == nme){
            display(first, true, temp->id);
            break;
         }
         temp = temp->next;
      }
      if(temp == NULL){
         cout << "    Name " << nme << " dosent exist." << endl;
      }
   }
   else if(opt == 2){
      int search;
      cout << "\n    Enter Id : ";
      cin >> search;
      int getIndex = checkId(first, search);

      if (getIndex == -1){
         cout << "    Id " << search << " dosent exist." << endl;;
      }
      else{
         for (int i = 0; i < getIndex; i++){
            first = first->next;
         }
         cout << "    Name   : " << first->name << endl;
         cout << "    Salary : " << first->salary <<endl;
         cout << "    Tenure : " << first->tenure <<endl;
      }
   }
   

}

void modify(Node **first) {
   Node *temp = *first;
   int mod;
   
   cout << "\nEnter id of data to be modified";
   cin >> mod;

   while(temp != NULL) {
      if(temp->id == mod) {
         cout << "\nEnter New data\n";
         cout << "\nEnter new Name: ";
         cin >> temp->name;
         // cout << "\nEnter new id: ";
         // cin >> temp->id;
         cout << "\nEnter new Salary: ";
         cin >> temp->salary;
         cout << "\nEnter new Tenure: ";
         cin >> temp->tenure;
         display(*first, true, temp->id);
         break;
      }
      temp = temp->next;
   }
   if(temp == NULL){
      cout<<"\nId does not exist.";
   }
}

void deleteId(Node **first){  
   int check;
   cout << "\n    Enter Id to be deleted : ";
   cin >> check;
   int index = checkId(*first, check);

   if(index == -1){
      cout << "    Id dosent exists." << endl;
   }
   else{
      switch (index){
         case 0:
            Node *temp0;
            temp0 = *first;
            temp0 = temp0->next;
            delete(*first);
            *first = temp0;
            break;

         default:
            Node *temp, *store, *delStore;
            temp = *first;
            for (int i = 0; i < index-1; i++){
               temp = temp->next;
            }
            delStore = temp->next;
            store = delStore->next;
            temp->next = store;
            delete(delStore);
            break;
      }
      cout << "    Record with Id = '" << check << "' deleted" << endl; 
   }
}

int main() {
   database *first = NULL, *temp, *head;
   int cont;

   while (true){ 
      cout << "\nEnter Operation : "<< endl;
      cout << "1 : Add new element." << endl;
      cout << "2 : Display list." << endl;
      cout << "3 : Search " << endl;
      cout << "4 : Modify" << endl;
      cout << "5 : Delete Record." << endl;
      cout << "0 : Exit" << endl; 
      cout << "Operation : "; 
      cin >> cont;
      switch (cont){
         case 1:
            insert(&first);
            break;
         
         case 2:
            display(first, false, 0);
            break;

         case 3: 
            search(first);
            break;

         case 4:
            modify(&first);
            break;

         case 5:
            deleteId(&first);
            break;

         case 0:
            cout << "\n    Exit.\n\n" ;
            exit(0);

         default:
            cout << "    Command didnt match, please try again." << endl;
            break;
      }
      cout << "\n<----------------------------------------------------------->\n";  

   }
}