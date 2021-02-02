// package trees;
import java.util.*;

class BTNode {
    BTNode left;
    BTNode right;
    int data;

    // Default Constructor
    public BTNode() {
        left = null;
        right = null;
        data = 0;
    }    

    //Counstructor
    public BTNode(int n) {
        left = null;
        right = null;
        data = n;
    }

    // Function to set left node
    public void setLeft(BTNode n) {
        left = n;
    }

    // Function to set right node
    public void setRight(BTNode n) {
        right = n;
    }

}

class BST {
    BTNode root;

    // Counstructor
    public BST() {
        root = null;
    }

    public void insert(int key) {
        root = insertRec(root, key);
    }

    BTNode insertRec(BTNode root, int key) { 
  
        //  If the tree is empty, return a new node 
        if (root == null) { 
            root = new BTNode(key); 
            return root; 
        } 
  
        //  Otherwise, recur down the tree 
        if (key < root.data) {
            root.left = insertRec(root.left, key);
        } 
        else if (key > root.data) {
            root.right = insertRec(root.right, key);
        } 
  
        // return the (unchanged) node pointer
        return root; 
    } 

    public BTNode findInorderSuccessor(BTNode root) {
        
        while(root.left != null) {
           root = root.left;
        }
        return root;
    }

    public BTNode findInorderPred(BTNode root) { 
        while(root.right != null) {
            root = root.right;
        }
        return root;
    }

    public void del(int key) {
        root = delete(root, key);
    }
    
    public BTNode delete(BTNode root, int data) {
        BTNode temp;
        if(root == null) {
            System.out.println("Element not in tree");
        }
        else if(data < root.data) {
            root.setLeft(delete(root.left, data));
        }
        else if(data > root.data) {
            root.setRight(delete(root.right, data));
        }
        else {
            //element found
            if(root.left == null) { 
                return root.right;
            }
            else if(root.right == null) {
                return root.left;
            }
            
            // temp = findInorderSuccessor(root.getRight());
            // root.setData(temp.getData());
            // root.setRight(delete(root.getRight(), root.getData()));

            temp = findInorderPred(root.left);
            root.data = temp.data;
            root.setLeft(delete(root.left, root.data));
        }
        
        return root;
    }

    // Recursive Inorder Method
    public void inorder() {
        inorderRec(root);
    }

    public void inorderRec(BTNode root) {
        if (root != null) { 
            inorderRec(root.left); 
            System.out.print(root.data + " "); 
            inorderRec(root.right); 
        } 
    }

    public static void main(String[] args) {
        BST tree = new BST();
        int key;
        int leaf;
        int opt;
        boolean loop = true;
        Scanner cin = new Scanner(System.in) ;

        while(loop) {
            System.out.println("Enter:\n1.Add data\n2.Delete data\n3.Display\n0.Exit");
            opt = cin.nextInt();

            switch(opt) {
                case 1:
                    System.out.println("Enter number of Leaves");

                    leaf = cin.nextInt();

                    System.out.println("Enter data for tree: ");
                    for(int i = 0; i < leaf; i++) {
                        key = cin.nextInt();
                        tree.insert(key);
                    }
                    break;
                
                case 2:
                    System.out.println("Enter data to be deleted");
                    key = cin.nextInt();
                    tree.del(key);
                    break;

                case 3:
                    tree.inorder();
                    System.out.println();
                    break;
                    
                case 0:
                    loop = false;
                    break;

                default:
                    System.out.println("Enter A valid option");
                    break;
            }
        }

        cin.close();
    }
}