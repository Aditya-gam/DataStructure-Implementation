#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

struct pizza{
    string phoneNo;
    string order;
    int orderNo;
    int amount;  
};

void giveSpaces(int num){
    while(num > 0){
        cout << " ";
        num --;
    }
}

void displayOrderQueue(int noOfElements, vector<pizza> arr, int frontIndex, int sizeOfArr){
    int i;
    // 12 16
    if(!arr.empty()){
        cout << "\nOrder-no    Phone-no        Bill    Order Detail" << endl;
        for(i=0; i<noOfElements; i++){
            cout << arr[(frontIndex+i)%sizeOfArr].orderNo;
            giveSpaces(12 - to_string(arr[(frontIndex+i)%sizeOfArr].orderNo).length());
            cout << arr[(frontIndex+i)%sizeOfArr].phoneNo;
            giveSpaces(16 - (arr[(frontIndex+i)%sizeOfArr].phoneNo).length());
            cout << arr[(frontIndex+i)%sizeOfArr].amount;
            giveSpaces(8 - to_string(arr[(frontIndex+i)%sizeOfArr].amount).length());
            cout << arr[(frontIndex+i)].order << endl;
        }
        cout << endl;
    }
    else{
        cout << "\nNo orders present" << endl;
    }
}

vector<pizza> take_Order(vector<pizza> par, int index){
    
    cout << "\nEnter phone number: ";
    cin >> par[index].phoneNo; 
    cout << "Enter order details: ";
    cin >> par[index].order;
    // getline(cin, par[index].order);
    // scanf(" %[^\n]s", par[index].order);
    // cout<<par[index].order;
    cout << "Enter amount (cost) : ";
    cin >> par[index].amount;
    if(index > 0){
        par[index].orderNo = par[index - 1].orderNo + 1;
    }
    else{
        par[index].orderNo = 1;
    }
    return par;
}

vector<pizza> deliverOrder(vector<pizza> par, int rear){
    for(int i = 0; i < rear; i++){
        par[i] = par[i + 1];
    }
    return par;
}

int main(){
    int n;
    cout << "\nEnter max number of orders: ";
    cin >> n;
    vector<pizza> parlor(n);
    int opt, front = 0, back = -1;
    int totAmt = 0, totAmtdel = 0, totOrders = 0;

    while(true){
        cout << "\nEnter\n1) Take Order\n2) Deliver first order\n3) Show order queue\n4) Day Summary\n0) Exit\nChoice: ";
        cin >> opt;

        switch(opt) {
            case 1:
                back += 1;
                if(parlor.size() == back){
                    cout << "\nMaximum order capacity reached\n";
                    back--;
                    break;
                }
                parlor = take_Order(parlor, back);
                displayOrderQueue(back+1, parlor, front, n);
                totAmt += parlor[back].amount;
                totOrders+=1;
                break;
            
            case 2:
                if(back < front){
                    cout << "\nNo orders left\n";
                    break;
                }
                totAmtdel += parlor[front].amount;
                parlor = deliverOrder(parlor, back);              
                back--;
                displayOrderQueue(back+1, parlor, front, n);
                break;

            case 3:
                displayOrderQueue(back+1, parlor, front, n);
                break;
            
            case 4:
                cout << "\nTotal Orders: " << totOrders << endl << "Total Amount: " << totAmt << endl << "Total Delivered: " << totAmtdel << endl;
                break;
            
            case 0:
                cout << "\n\n\tThank you\t\n\n";
                exit(0);
                break;
            
            default:
                cout << "\nEnter Valid choice\n";
                break;
        }
    }
}