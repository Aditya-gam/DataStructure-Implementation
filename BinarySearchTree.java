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

    public void insertNode(TreeNode new_node) {

        if(root == null) {
            root = new_node;
            System.out.println("Value Inserted as root node");
        }

        else {
            TreeNode temp = root;

            while(temp != null) {

                if(new_node.value == temp.value) {
                    System.out.println("Value already exists, Enter another value");
                    return;
                }  
                else if((new_node.value < temp.value) && (temp.left == null)) {
                    temp.left = new_node;
                    System.out.println("Value inserted to left");
                    break;
                }  
                else if(new_node.value < temp.value) {
                    temp = temp.left;
                }
                else if((new_node.value > temp.value) && (temp.right == null)) {
                    temp.right = new_node;
                    System.out.println("Value inserted to right");
                    break;
                }  
                else if(new_node.value > temp.value) {
                    temp = temp.right;
                }


            }
        }
    }

    public void print2D(TreeNode r, int space) {
        if (r == null) {
            return ;
        }

        space += 10;
        print2D(r.right, space);
        System.out.println();
        for(int i = 10; i < space; i++) {
            System.out.print(" ");
        }
        System.out.println(r.value);
        print2D(r.left, space);
    }

    
};

class Main {
    public static void main(String[] args) {
        BST obj = new BST();
        int opt; 
        int val;
        boolean loop = true;
        Scanner cin = new Scanner(System.in);
        while(loop) {
            System.out.print("1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print BST Values\n0.Exit\nEnter your choice: ");
            opt = cin.nextInt();
            TreeNode new_node = new TreeNode();

            switch(opt) {
                case 0:
                    loop = false;
                    break;
                
                case 1:
                    System.out.println("Insert");
                    System.out.println("Enter value of tree node to insert in BST: ");
                    val = cin.nextInt();
                    new_node.value = val;
                    obj.insertNode(new_node);
                    System.out.println();
                    break;
    
                case 2:
                    System.out.println("Search");
                    break;
    
                case 3:
                    System.out.println("Delete");
                    break;
    
                case 4:
                    System.out.println("Print");
                    obj.print2D(obj.root, 5);
                    break;
    
                default:
                    System.out.println("Enter A Valid Option!!");
                    break;
            }
            
        }
        cin.close();
    }
};
 
