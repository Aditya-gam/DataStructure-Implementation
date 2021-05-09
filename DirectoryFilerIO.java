import java.io.*;
import java.util.*;

class StudentRecords {

    public boolean rollNumberExists(int rollNumber){
        String str;
        String [] nameRollNo;
        try{
            BufferedReader reader = new BufferedReader(new FileReader("StudentData.txt"));
            str = reader.readLine();
            while(str != null){
                nameRollNo = str.split(" ");
                if(nameRollNo.length == 2){
                    if(Integer.parseInt(nameRollNo[1]) == rollNumber){
                        reader.close();
                        return true;
                    }
                }
                str = reader.readLine();
            }

            reader.close();
        }
        catch (Exception e) {
        }

        return false;
    }


    public void addRecord(String name, int rollNo){
        try {
            // boolean rollNoExists = rollNumberExists(rollNo);

            if(rollNumberExists(rollNo)){
                System.out.println("\n        Roll number already exists.");
            }
            else{
                PrintWriter writer  = new PrintWriter(new FileOutputStream("StudentData.txt", true));
                writer.println(name + " " + rollNo);
                System.out.println("\n\t\tRecord '" + name + " " + rollNo + "' added successfully");
                writer.close();
            }
        } 
        catch (Exception e) {
            System.out.println("\tCouldnt add record. " + e.getMessage());
        }
    }


    public void deleteRecord(int rollNo){
        try {
            String str, finalStr = "";
            String [] nameRollNo;
            boolean found = false;

            BufferedReader reader = new BufferedReader(new FileReader("StudentData.txt"));
            str = reader.readLine();
            while(str != null){
                nameRollNo = str.split(" ");
                if(nameRollNo.length == 2){
                    if(Integer.parseInt(nameRollNo[1]) != rollNo){
                        finalStr += str;
                        finalStr += "\n";
                    }
                    else{
                        found = true;
                    }
                }
                str = reader.readLine();
            }
            reader.close();

            PrintWriter writer  = new PrintWriter(new FileOutputStream("StudentData.txt"));
            writer.println(finalStr);
            writer.close();

            if(found){
                System.out.println("\n\t\tRoll Number '" + rollNo + "' deleted successfully");
            }
            else{
                System.out.println("\n\t\tRoll number doesn't exist.");
            }

        }
        catch (Exception e) {
            System.out.println("\tCouldnt delete record. " +  e.getMessage());
        }
        
    }


    public void searchRecord(String name, int rollNo){
        try{
            String str;
            String [] nameRollNo;
            boolean found = false;

            BufferedReader reader = new BufferedReader(new FileReader("StudentData.txt"));
            str = reader.readLine();
            
            while(str != null){
                nameRollNo = str.split(" ");
                if(nameRollNo.length == 2){
                    if(Integer.parseInt(nameRollNo[1]) == rollNo || nameRollNo[0] == name){
                        System.out.println("\tRecord found : " + nameRollNo[0] + " " + nameRollNo[1]);
                        found = true;
                    }
                }
                str = reader.readLine();
            }
            reader.close();


            if(!found){
                System.out.println("    No record found.");
            }

        }
        catch (Exception e) {
            System.out.println("    No record found.");
        }
    }


    public void showAllRecords(){
        try{
            String str;
            String [] nameRollNo;
            boolean found = false;

            BufferedReader reader = new BufferedReader(new FileReader("StudentData.txt"));
            str = reader.readLine();
            
            while(str != null){
                nameRollNo = str.split(" ");
                if(nameRollNo.length == 2){
                    System.out.println("\t" + nameRollNo[0] + "\t\t" + nameRollNo[1]);
                    found = true;
                }
                str = reader.readLine();
            }
            reader.close();

            if(!found){
                System.out.println("    No record found.");
            }

        }
        catch (Exception e) {
            System.out.println("    Couldnt search record. " +  e.getMessage());
        }
    }


    // public static void main(String[] args) {
    //     int operation;
    //     Scanner sc = new Scanner(System.in);

    //     while(true){
    //         System.out.println("\n\nEnter: ");
    //         System.out.println("1) Add Record");
    //         System.out.println("2) Delete Record");
    //         System.out.println("3) Search by roll Number");
    //         System.out.println("4) Show all records");
    //         System.out.println("0) Exit");
    //         System.out.print("Enter your choice : ");

            
    //         // sc.next();
    //         operation = sc.nextInt();

    //         String name;
    //         int rollNo;

    //         if (operation == 0){
    //             System.out.println("\n\t\tThank You !!!");
    //             break;
    //         }

    //         switch (operation) {
    //             case 1:
    //                 System.out.print("\tEnter the name: ");
    //                 name = sc.nextLine();
    //                 name = sc.nextLine();
    //                 System.out.print("\tEnter the roll number: ");
    //                 rollNo = sc.nextInt();

    //                 if(rollNo <=0 ){
    //                     System.out.print("\t\tInvalid roll number.");
    //                     break;
    //                 }

    //                 addRecord(name, rollNo);
    //                 break;
            
    //             case 2:
    //                 System.out.print("\tEnter the roll number to delete : ");
    //                 rollNo = sc.nextInt();
    //                 deleteRecord(rollNo);
    //                 break;

    //             case 3:
    //                 System.out.print("\tEnter the roll number : ");
    //                 rollNo = sc.nextInt();
    //                 searchRecord("-", rollNo);
    //                 break;

    //             case 4:
    //                 showAllRecords();
    //                 break;

    //             default:
    //                 System.out.println("Invalid Operation");
    //                 break;
    //         }

    //     }

    //     sc.close();
    // }
}

class Main1 {
    public static void main(String[] args) {
        int operation;
        Scanner sc = new Scanner(System.in);
        StudentRecords data = new StudentRecords();

        while(true){
            System.out.println("\n\nEnter: ");
            System.out.println("1) Add Record");
            System.out.println("2) Delete Record");
            System.out.println("3) Search by roll Number");
            System.out.println("4) Show all records");
            System.out.println("0) Exit");
            System.out.print("Enter your choice : ");

            
            // sc.next();
            operation = sc.nextInt();

            String name;
            int rollNo;

            if (operation == 0){
                System.out.println("\n\t\tThank You !!!");
                break;
            }

            switch (operation) {
                case 1:
                    System.out.print("\tEnter the name: ");
                    name = sc.nextLine();
                    name = sc.nextLine();
                    System.out.print("\tEnter the roll number: ");
                    rollNo = sc.nextInt();

                    if(rollNo <=0 ){
                        System.out.print("\t\tInvalid roll number.");
                        break;
                    }

                    data.addRecord(name, rollNo);
                    break;
            
                case 2:
                    System.out.print("\tEnter the roll number to delete : ");
                    rollNo = sc.nextInt();
                    data.deleteRecord(rollNo);
                    break;

                case 3:
                    System.out.print("\tEnter the roll number : ");
                    rollNo = sc.nextInt();
                    data.searchRecord("-", rollNo);
                    break;

                case 4:
                    data.showAllRecords();
                    break;

                default:
                    System.out.println("Invalid Operation");
                    break;
            }

        }

        sc.close();
    }
}