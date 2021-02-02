#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack <int> bookshelf;
    int q,n,query;
    cin>>q;
    while(q-->0){
        cin>>query;
        if(query == 1){
            cin>>n;
            bookshelf.push(n);
        }
        else if(query == -1){
            if(bookshelf.empty()){
                cout << "kuchbhi?" << endl;
            }
            else{
                int x = bookshelf.top();
                cout << x << endl;
                bookshelf.pop();
            }
        }
    }
    return 0;
}