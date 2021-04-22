import java.util.*;

class HeapMarks {
    int heapLen = 1000;
    int currIndex = 0;
    int []minHeap = new int [heapLen];
    int []maxHeap = new int [heapLen];

    // public void HeapMarks() {
    //     this.currIndex = 0;
    // }

    // public void HeapMarks(int hl) {
    //     this.heapLen = hl;
    //     this.minHeap = new int [heapLen];
    //     this.maxHeap = new int [heapLen];
    // }

    public void insertMin(int marks){
        int i = currIndex, myParent, temp;
        minHeap[currIndex] = marks;
        
        while( i != 0){
            myParent = (i - 1)/2;
            if(minHeap[i] < minHeap[myParent]){
                temp = minHeap[i];
                minHeap[i] = minHeap[myParent];
                minHeap[myParent] = temp;
                i = myParent;
            }

            else{
                break;
            }
        }
    }


    public void insertMax(int marks){
        int i = currIndex, myParent, temp;
        maxHeap[currIndex] = marks;
        
        while( i != 0){
            myParent = (i - 1)/2;
            if(maxHeap[i] > maxHeap[myParent]){
                temp = maxHeap[i];
                maxHeap[i] = maxHeap[myParent];
                maxHeap[myParent] = temp;
                i = myParent;
            }
            else{
                break;
            }
        }
    }


    public void insert(int marks){
        insertMin(marks);
        insertMax(marks);
        currIndex += 1;
    }


    public int log2(int n){
        int result = (int)(Math.log(n) / Math.log(2));
        return result;
    }
};

class Main2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        HeapMarks studentMarks = new HeapMarks();
        // System.out.print("Enter number of entries: ");
        // int hl = input.nextInt();
        // studentMarks.HeapMarks(hl);
        int marks = 10, i, choice;
        
        boolean loop = true;
        // studentMarks.insertMin(2);
        while(loop) {
            System.out.println("\nEnter");
            System.out.println("1) Insert Marks");
            System.out.println("2) Print Heaps");
            System.out.println("3) Print min and max marks");
            System.out.println("0) Exit");
            System.out.print("Enter your choice: ");
            choice = input.nextInt();
            System.out.println();

            switch(choice) {
                case 1:
                    System.out.print("\tEnter Marks: ");
                    marks = input.nextInt(); 
                    studentMarks.insert(marks);
                    break;

                case 2:
                    System.out.print("Min Heap Array: ");
                    for(i = 0; i < 16; i ++) {
                        if(studentMarks.minHeap[i] != 0) {
                            System.out.print(studentMarks.minHeap[i] + " ");
                        }
                    }

                    System.out.print("\nMax Heap Array: ");
                    for(i = 0; i < 16; i ++) {
                        if(studentMarks.maxHeap[i] != 0) {
                            System.out.print(studentMarks.maxHeap[i] + " ");
                        }
                    }

                    System.out.println();  
                    break;
                
                case 3:
                    System.out.println("\tMinimum Marks = " + studentMarks.minHeap[0]);
                    System.out.println("\tMaximum Marks = " + studentMarks.maxHeap[0]);
                    break;
                
                case 0:
                    System.out.println("\tThank You !!!\n\n");
                    loop = false;
                    break; 

                default:
                    System.out.println("\tInvalid Operation");
            }
        }
        input.close();
    }
}