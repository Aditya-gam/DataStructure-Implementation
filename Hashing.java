import java.util.*;

class HashTable {
    String data = null;
    HashTable next = null;

    public HashTable(String str) {
        data = str;
    }
}

class HashAssignment {
    int hashTableLen = 10;
    HashTable[] hashArr = new HashTable[hashTableLen];
    String[] initialDict = {"wing", "king", "sing", "see", "then", "hello", "pink", "sink", "sea", "tell", "tong", "belt", "tab", "thank", "bank", "sank"};

    public int hashFunction(String str) {
        // Logic for hashfunction and return int;
        int i, hashValue = 0;
        for(i = 0; i < str.length(); i++) {
            hashValue += (((int)str.charAt(i)) - 96) * Math.pow(7, i);
            // hashValue += (((int)str.charAt(i)) - 96) * Math.pow(7, str.length() - i - 1);
        }
        return hashValue % hashTableLen;
    }

    public void printHashTable() {
        int i;
        HashTable iterate;
        System.out.println("\tIndex\t\tValue");
        System.out.println("\t------------------------------------------------------------------");

        for(i = 0; i < hashTableLen; i++) {
            System.out.print("\t" + i + "\t\t");

            if(hashArr[i] != null) {
                System.out.print(hashArr[i].data);
                iterate = hashArr[i];

                while(iterate.next != null) {
                    System.out.print(" -> ");
                    iterate = iterate.next;
                    System.out.print(iterate.data);
                }
                System.out.println();
            }
            else {
                System.out.println("-");
            }
        }
        System.out.println("\t------------------------------------------------------------------");
    }


    public void addToTable(String str) {
        int hashValue;
        // System.out.println(str +  " " + hashFunction(str));
        hashValue = hashFunction(str);

        if(hashArr[hashValue] == null) {
            hashArr[hashValue] = new HashTable(str);
        }
        else {
            HashTable iterate = hashArr[hashValue];
            while (iterate.next != null) {
                iterate = iterate.next;
            }
            iterate.next = new HashTable(str);
        }
    }
    

    public String changeChar(String str, int index, char newChar) {
        String newStr = "";
        int i;
        for(i = 0; i < str.length(); i ++){
            if(i == index){
                newStr += newChar;
            }
            else{
                newStr += str.charAt(i);
            }
        }
        return newStr;
    }


    public boolean searchActual(String str) {
        int hashValue;
        
        hashValue = hashFunction(str);

        if(hashArr[hashValue] == null) {
            return false;
        }
        HashTable iterate = hashArr[hashValue];
        
        while(iterate != null){
            if(iterate.data.equals(str)) {
                return true;
            }
            iterate = iterate.next;
        }
        
        return false;
    }


    public String searchLogic(String str) {
        ArrayList<String> recommend = new ArrayList<String>();
        
        if(searchActual(str)) {
            return (str + " found int dictionary");
        }
        else {
            String newStr;
            int i, j;

            for(i = 0; i < str.length(); i ++ ) {
                for(j = 1; j < 26; j ++) {
                    newStr = changeChar(str, i, (char)((((int)(str.charAt(i) + j - 97)) % 26) + 97));

                    if(searchActual(newStr)) {
                        recommend.add(newStr);
                    }
                }
            }

        }

        if(recommend.size() == 0) {
            return (str + " not found.\n    No recommendations found.");
        }
        else {
            int i;
            String returnStr = str + " not found.\n    Found ";
            returnStr = returnStr + Integer.toString(recommend.size()) + " recommendations : ";
            for(i = 0; i < recommend.size(); i ++){
                returnStr += recommend.get(i);
                if(i != recommend.size() - 1){
                    returnStr += ", ";
                }
            }
            return returnStr;
        }
    }


    public void createInitialDict() {
        for(int i = 0; i < initialDict.length; i++){
            addToTable(initialDict[i]);
        }
    }
    

    public boolean isStringOnlyAlphabet(String str){
        return ((!str.equals("")) && (str != null) && (str.matches("^[a-zA-Z]*$")));
    }

    
}

class Main3 {
    public static void main(String[] args) {
        HashAssignment table = new HashAssignment();
        table.createInitialDict();
        Scanner input = new Scanner(System.in);
        int operation;
        String str;
        boolean loop = true;

        while(loop){
            System.out.println("\nEnter: ");
            System.out.println("1. Add new Word to Dict");
            System.out.println("2. Print Hash Table");
            System.out.println("3. Search a word");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            operation = input.nextInt();
            System.out.println();

            switch(operation) {
                case 1:
                    System.out.print("\tEnter the word to be added: ");
                    str = input.next();
                    str = str.toLowerCase();
                    if(!table.isStringOnlyAlphabet(str)) {
                        System.out.println("\tInvalid String !!!");
                        continue;
                    }
                    if(!table.searchActual(str)) {
                        table.addToTable(str);
                        System.out.println("\t" + str + " added to dictionary.");
                    }
                    else {
                        System.out.println("\t" + str + " is already present in dictionary.");
                    }        
                break;

                case 2:
                    System.out.println("\tHash Table .... \n");
                    table.printHashTable();    
                break;

                case 3:
                    System.out.print("\tEnter the word: ");
                    str = input.next();

                    if(!table.isStringOnlyAlphabet(str)) {
                        System.out.println("\tInvalid String !!!");
                        continue;
                    }

                    System.out.print("\t");
                    System.out.println(table.searchLogic(str.toLowerCase()));    
                break;

                case 0:
                    System.out.println("\tThank You !!!\n\n");  
                    loop = false; 
                break;

                default:
                    System.out.println("\tInvalid Operation");    
                break;
            }
        }

        input.close();
    }    
}

// Search ideas => ping, kink, ting, bell, tap, sank, sung