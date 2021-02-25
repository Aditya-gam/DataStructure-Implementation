import java.util.*;

class TreeNode {
    int value;
    TreeNode left;
    TreeNode right;

    public TreeNode() {
        value = 0;
        left = null;
        right = null;
    }

    public TreeNode(int v) {
        value = v;
        left = null;
        right = null;
    }
};

class BST {

    TreeNode root;

    public boolean isEmpty() {
        if(root == null) {
            return true;
        }
        else {
            return false;
        }
    }

    public static void main(String[] args) {
        int opt;
        boolean loop = true;
        Scanner cin = new Scanner(System.in);
        while(loop) {
            System.out.print("1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print BST Values\n0.Exit\nEnter your choice: ");
            opt = cin.nextInt();
    
            switch(opt) {
                case 0:
                    loop = false;
                    break;
                
                case 1:
                    System.out.println("Insert");
                    break;
    
                case 2:
                    System.out.println("Search");
                    break;
    
                case 3:
                    System.out.println("Delete");
                    break;
    
                case 4:
                    System.out.println("Print");
                    break;
    
                default:
                    System.out.println("Enter A Valid Option!!");
                    break;
            }
            
        }
        cin.close();
    }
}
 
