#include <iostream>
#include <vector>


using namespace std;

vector<int> acceptArray(vector<int> arr){
    for(int i = 0; i<arr.size();i++){
        cin>>arr[i];
    }
    return arr;
}

void swap(int *xp, int *yp){  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void displayPass(vector<int> s){
    for(int i = 0;i < s.size();i++){
        cout << s[i] << " ";
    }
    cout << endl;
}

vector<int> selection_Sort(vector<int> a, bool pas){
    int pass = 0, imin;
    if (pas == true){
        cout << "\n\nUnsorted Array: ";
        displayPass(a);
    }
    for(int i = 0;i < a.size() - 1;i++){
        imin = i;
        for(int j = i + 1;j < a.size(); j++){
            if (a[j] < a[imin]){
                imin = j;
            }
            if(pas == true){
                pass++;
                cout << "\nPass " << pass << ": ";
                displayPass(a);
                cout << "j = " << j << "\tMin = " << imin << endl;
            }
        }
        swap(a[i], a[imin]);
    }
    return a;
}

void binary_Search(vector<int> a, int element){
    int first = 0, last = a.size() - 1, mid = (first + last)/2;
    a = selection_Sort(a, false);
    while(first <= last){
        if(element > a[mid]){
            first = mid + 1;
            mid = (first + last)/2;
        }
        else if(element < a[mid]){
            last = mid - 1;
            mid = (first + last)/2;
        }
        else{
            cout << "\n\nElement found at: " << mid + 1;
            break;
        }
    }
    if(first > last){
        cout << "\n\nElement not found\n\n";
    }
}

int main(){
    vector<int> arr, sorted;
    int n, opt;
    cout << "\nEnter size of array\n";
    cin >> n;
    arr.resize(n);
    sorted.resize(n);
    cout << "\nEnter Elements of array\n";
    arr = acceptArray(arr);
    while(true){
        cout<<"\nEnter\n1. Sort using Selection sort\n2. Search using Binary search\n0. Exit\n Choice: ";
        cin >> opt;
        switch (opt){
        case 1:
            sorted = selection_Sort(arr, true);
            cout << "\n\nSorted Array: ";
            displayPass(sorted);
            break;

        case 2:
            int elem;
            cout << "\nEnter element to searched: ";
            cin >> elem;
            binary_Search(arr, elem);
            break;
        
        case 0:
            exit(0);
            break;
        default:
            cout<<"\nEnter a valid choice\n";
            break;
        }
    }
}