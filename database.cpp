// Assignment 4 Complete

#include<iostream>
#include<string>
using namespace std;

#define INDEX 100

typedef struct dat {
    string name;
    int id, phn_no;
    float salary;
};

dat d1[INDEX];


int record_pointer = 0;

void add_record() {
    
    cout<<"\nEnter name: ";
    cin >> d1[record_pointer].name;
    cout << "\nEnter id: ";
    cin >> d1[record_pointer].id;
    cout << "\nEnter phone number: ";
    cin >> d1[record_pointer].phn_no;
    cout << "\nEnter Salary: ";
    cin >> d1[record_pointer].salary;
    record_pointer++;
}

void display_record(int num, int rec) {
    cout << "\nid\t\tName\t\tPhone number\t\tsalary\n";
    if (num == 1) {
        for (int i = 0;i < record_pointer;i++) {
            cout<<"\n"<<d1[i].id<<"\t\t"<<d1[i].name;
            cout<<"\t\t"<<d1[i].phn_no<<"\t\t\t"<<d1[i].salary<<"\n";
        }
    }
    else if (num == 0) {
            cout<<"\n"<<d1[rec].id<<"\t\t"<<d1[rec].name;
            cout<<"\t\t"<<d1[rec].phn_no<<"\t\t"<<d1[rec].salary<<"\n";
    }
}

int search_by_name() {
    string nme;
    
    cout << "\nEnter name to be searched: ";
    cin >> nme;
    for(int i = 0;i < record_pointer;i++) {
        if(nme == d1[i].name){
            return i;
            break;
        }
    }
    return (-1);
}

int search_by_id() {
    int elem;
    cout << "\nEnter id to be searched: ";
    cin >> elem;
    for(int i = 0;i < record_pointer;i++) {
        if(elem == d1[i].id){
            return i;
            break;
        }
    }
    return (-1);

}

int search_by_phn_no() {
    int phn_n;
    cout << "\nEnter Phone number to be searched: ";
    cin >> phn_n;
    for(int i = 0;i < record_pointer;i++) {
        if(phn_n == d1[i].phn_no){
            return i;
            break;
        }
    }
    return (-1);
}

void search_record() {
    int opt,index;
    cout << "\nEnter\n1. Search by name\n2. Search by id\n3. Search by Phone number\n";
    cin >> opt;
    switch(opt) {
        case 1:
            index = search_by_name();
            if (index == -1){
                cout<<"\nRecord not found!!";
            }
            else{
                cout << "\nRecord found at " << index+1;
                display_record(0, index);
            }
            break;
        case 2:
            index = search_by_id();
            if (index == -1){
                cout<<"\nRecord not found!!";
            }
            else{
                cout << "\nRecord found at " << index+1;
                display_record(0, index);
            }
            break;
        case 3:
            index = search_by_phn_no();
            if (index == -1){
                cout<<"\nRecord not found!!";
            }
            else{
                cout << "\nRecord found at " << index+1;
                display_record(0, index);
            }
            break;
        default:
            cout << "\nEnter a valid option.";
            break;
    }
}



void delete_record() {
    int del,i,j;
    cout << "\nEnter id of record to be deleted: ";
    cin >> del;
    for(i = 0;i < record_pointer;i++){
        if(d1[i].id == del) {
            j = i+1;
            break;
        }
    }
    if(i == record_pointer){
        cout << "\nRecord does not exist.";
    }
    else{
        for(i;i<record_pointer;i++,j++){
            d1[i].name = d1[j].name;
            d1[i].id = d1[j].id;
            d1[i].phn_no = d1[j].phn_no;
            d1[i].salary = d1[j].salary;
        }
        record_pointer--;
    }
}

int main(){
    int option;
    char ans;
    
    add_record(); 
    do {
        cout << "\nEnter\n1. Add record\n2. Display Database\n3. Search record\n4. Delete record\n";
        cin >> option;
    
        switch(option) {
            case 1:
                add_record();
                break;

            case 2:
                display_record(1,0);
                break;

            case 3:
                search_record();
                break;
            
            case 4:
                delete_record();
                break;
            
            default:
                cout << "\nEnter a valid choice";
                break;
        }
        cout << "\nDo you want to continue(y/n)?: ";
        cin >> ans;
    }
    while(ans == 'Y' || ans == 'y');

}