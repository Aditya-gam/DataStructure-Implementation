#include<bits/stdc++.h>


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

vector<int> bubble_Sort(vector<int> a, bool pas){
    int pass = 0;
    if (pas == true){
        cout << "\n\nUnsorted Array: ";
        displayPass(a);
    }
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a.size()-i-1; j++){
            if (a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }
            if(pas == true){
                pass++;
                cout << "\nPass " << pass << ": ";
                displayPass(a);
            }
        }
    }
    return a;
}

void binary_Search(vector<int> a, int element){
    int first = 0, last = a.size() - 1, mid = (first + last)/2;
    a = bubble_Sort(a, false);
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

int partition(vector<int> a, int l, int h) {
   int pivot, index, i;
   index = l;
   pivot = h;
   for(i = l; i < h; i++) {
      if(a[i] < a[pivot]) {
         swap(&a[i], &a[index]);
         index++;
      }
   }
   swap(&a[pivot], &a[index]);
   displayPass(a);
   return index;
}

int randomPivot_Partition(vector<int> a, int l, int h) {
   int pvt, n, temp;
   n = rand();
   pvt = l + n%(h-l+1);
   swap(&a[h], &a[pvt]);
   displayPass(a);
   return partition(a, l, h);
}

int quick_Sort(vector<int> a, int l, int h) {
   int pindex;
   if(l < h) {
      pindex = randomPivot_Partition(a, l, h);
      quick_Sort(a, l, pindex-1);
      quick_Sort(a, pindex+1, h);
   }
   displayPass(a);
//    if(l > h){
//        return a;
//    }
   return 0;
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
        cout<<"\nEnter\n1. Sort using Bubble Sort\n2. Search using Binary search\n3. Sort using Quick Sort\n0. Exit\n Choice: ";
        cin >> opt;
        switch (opt){
        case 1:
            sorted = bubble_Sort(arr, true);
            cout << "\n\nSorted Array: ";
            displayPass(sorted);
            break;

        case 2:
            int elem;
            cout << "\nEnter element to searched: ";
            cin >> elem;
            binary_Search(arr, elem);
            break;
        
        case 3:
            quick_Sort(arr, 0, n -1);
            // displayPass(sorted);
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