#include <iostream> 
using namespace std; 
  
// Maximum number of elements in matrix 
#define MAX 100 
  
// Array representation 
// of dat matrix 
//[][0] represents row 
//[][1] represents col 
//[][2] represents value 
int dat[MAX][3]; 
  
// total number of elements in matrix 
int len; 
  
// insert elements into dat matrix 
void insert(int r, int c, int val) 
{ 
    // insert row value 
    dat[len][0] = r; 
  
    // insert col value 
    dat[len][1] = c; 
  
    // insert element's value 
    dat[len][2] = val; 
  
    // increment number of dat in matrix 
    len++; 
} 
  
// printing Sparse Matrix 
void print() 
{ 
    cout << "\nDimension of Sparse Matrix: "
         << len << " x " << 3; 
    cout << "\nSparse Matrix: \nRow\tColumn\tValue\n"; 
  
    for (int i = 0; i < len; i++) { 
  
        cout << dat[i][0]<< "\t"
             << dat[i][1]<< "\t"
             << dat[i][2]<< "\n"; 
    } 
} 

void simple_transpose(int c) {
   int trans[10][10];
    
   int q = 0, i, j;
 
   // transpose of the matrix
   for(i = 0; i < c; i++) {
	   for(j = 0; j < len; j++) {
         if(dat[j][1] == i) {
            trans[q][0] = dat[j][1];
            trans[q][1] = dat[j][0];
            trans[q][2] = dat[j][2];
            q += 1;
         }
	   }
   }
   cout<<"\n\nThe simple transpose of the dat matrix :\n ";
   cout<<"\nRow\tColumn\tElement\n\n";
   //cout<<dat[0][1]<<"\t"<<dat[0][2]<<"\t"<<dat[0][3]<<"\n\n";
   for(int i = 0; i < len; i++) {
      cout<<trans[i][0]<<"\t"
          <<trans[i][1]<<"\t"
          <<trans[i][2]<<"\n";
   }
}

void fast_transpose(int col) {
         // to count number of elements in each column 
         int count[col + 1]; 
         int ftrans[10][10];
         
         // initialize all to 0 
         for (int i = 0; i < col; i++) {
            count[i] = 0; 
         }
  
         for (int i = 0; i < len; i++) {
            count[dat[i][1]]++;
         } 
  
         int index[col + 1]; 
  
         // to count number of elements having  
         // col smaller than particular i 
  
         // as there is no col with value < 0 
         index[0] = 0; 
  
         // initialize rest of the indices 
         for (int i = 1; i <= col; i++) {
            index[i] = index[i - 1] + count[i - 1];
         }

         int rpos;
         for (int i = 0; i < len; i++) { 
            // insert a data at rpos and  
            // increment its value 
            rpos = index[dat[i][1]]++; 
  
            // transpose row=col 
            ftrans[rpos][0] = dat[i][1]; 
  
            // transpose col=row 
            ftrans[rpos][1] = dat[i][0]; 
  
            // same value 
            ftrans[rpos][2] = dat[i][2]; 
         } 
         cout<<"\n\nThe simple transpose of the dat matrix :\n ";
         cout<<"\nRow\tColumn\tElement\n\n";
         //cout<<dat[0][1]<<"\t"<<dat[0][2]<<"\t"<<dat[0][3]<<"\n\n";
         for(int i = 0; i < len; i++) {
            cout  <<ftrans[i][0]<<"\t"
                  <<ftrans[i][1]<<"\t"
                  <<ftrans[i][2]<<"\n";
         }
         // the above method ensures 
         // sorting of transpose matrix 
         // according to row-col value 
        
}

  
// Driver code 
int main() 
{ 
   int i, j; 
   int row, col;
   char cont;
   cout << "Enter no. of rows and columns\n";
   cin >> row >> col; 
  
   // Get the matrix 
   int a[row][col]; 
  
   // print the matrix 
   cout << "\nEnter elements of matrix:\n"; 
   for (i = 0; i < row; i++) { 
      for (j = 0; j < col; j++) { 
         cin >> a[i][j];  
      }
   } 
   cout << "Entered matrix: \n";
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         cout << a[i][j] << " "; 
      }   
      cout << endl; 
   } 
  
   // iterate through the matrix and 
   // insert every non zero elements 
   // in the Sparse Matrix 
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         if (a[i][j] > 0) {
            insert(i, j, a[i][j]); 
         }
      }
   }  
   // Print the Sparse Matrix 
   print(); 

   int opt;
   do {
      cout << "Enter\n1.simple transpose\n2.fast transpose\n3.print a matrix\n";
      cin >> opt;             // choose option for simple or fast transpose.

      switch(opt) {
         case 1:             //Simple transpose   
               simple_transpose(col);
               break;
         case 2:
               fast_transpose(col);
               break;
         
         case 3:
               print();
               break;
         default:
               cout << "Enter a valid choice\n";
      }
      
      cout << "Enter Y to continue : ";
      cin >> cont;
   }
   while(cont == 'y' || cont == 'Y');
  return 0; 
} 






/*
0 1 0 0   0 1 1               
0 0 2 0   1 2 2
0 3 0 0   2 1 3
0 0 5 0   3 2 5
0 0 0 4   4 3 4
*/

/*
0 0 0 0 0   1 0 1
1 0 3 0 0   1 2 3
0 2 0 5 0   2 1 2
0 0 0 0 4   2 3 5
*/        //3 4 4