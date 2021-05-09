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

class AVL {

    TreeNode root;

    TreeNode insertRecursive(TreeNode r, TreeNode new_node) {
        if(r == null) {
            r = new_node;
            return r;
        }
    
        if(new_node.value < r.value) {
            r.left = insertRecursive(r.left, new_node);
        }
        else if(new_node.value > r.value) {
            r.right = insertRecursive(r.right, new_node);
        }
        else{
            System.out.println("No Duplicates allowed!!");
            return r;
        }

        int bf = getBalanceFactor(r);

        if(bf > 1 && new_node.value < r.left.value){
            return rightRotate(r);
        }
        if(bf < -1 && new_node.value > r.right.value) {
            return leftRotate(r);
        }
        if(bf > 1 && new_node.value > r.left.value) {
            r.left = leftRotate(r.left);
            return rightRotate(r);
        }
        if(bf < -1 && new_node.value < r.right.value) {
            r.right = rightRotate(r.right);
            return leftRotate(r);
        }

        return r;
    }

    int getBalanceFactor(TreeNode n) {
        if(n == null) {
            return -1;
        }
        else {
            return (height(n.left) - height(n.right));
        }
    }

    int height(TreeNode r) {
        int lheight;
        int rheight;
        if(r == null) {
            return -1;
        }
        else {
            lheight = height(r.left);
            rheight = height(r.right);

            if(lheight > rheight) {
                return (lheight + 1);
            }
            else {
                return (rheight + 1);
            }
        }
    }

    TreeNode rightRotate(TreeNode y) {
        TreeNode x = y.left;
        TreeNode T2 = x.right;

        x.right = y;
        y.left = T2;
        System.out.println("\nRotated Right!");

        return x;
    }

    TreeNode leftRotate(TreeNode x) {
        TreeNode y = x.right;
        TreeNode T2 = y.left;

        y.left = x;
        x.right = T2;
        System.out.println("\nRotated Left!");

        return y;
    }

    public TreeNode iterativeSearch(int val) {
        if(root == null) {
            return root;
        }
        else {
            TreeNode temp = root;

            while(temp != null) {
                if(val == temp.value) {
                    return temp;
                }    
                else if(val < temp.value) {
                    temp = temp.left;
                }
                else {
                    temp = temp.right;
                }
            }

            return null;
        }
    }

    public void printTree(AVL obj) {
        int opt;
        Scanner sc = new Scanner(System.in);
        System.out.println( "\n1.Print 2D\n2.Print Preorder\n3.Print Inorder\n4.Print Postorder\n5.Print Level Order\nEnter your choice: ");
        opt = sc.nextInt();

        switch(opt) {
            case 1:
                obj.print2D(obj.root, 5);
                break;
            
            case 2:
                obj.printPreorder(obj.root);
                System.out.println();
                break;
            
            case 3:
                obj.printInorder(obj.root);
                System.out.println();
                break;

            case 4:
                obj.printPostorder(obj.root);
                System.out.println();
                break;
            
            case 5:
                obj.printLevelorder(obj.root);
                System.out.println();
                break;

            default:
                System.out.println("Enter a valid option");
                break;
        }
        // sc.close();
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

    public void printPreorder(TreeNode r) {
        if(r == null) {
            return;
        }

        System.out.print(r.value + " ");

        printPreorder(r.left);

        printPreorder(r.right);
    }

    public void printInorder(TreeNode r) {
        if(r == null) {
            return;
        }

        printInorder(r.left);

        System.out.print(r.value + " ");

        printInorder(r.right);
    }

    public void printPostorder(TreeNode r) {
        if(r == null) {
            return;
        }

        printPostorder(r.left);

        printPostorder(r.right);

        System.out.print(r.value + " ");
    }

    public void printLevelorder(TreeNode r) {
        int h = height(r);
        
        for(int i = 0; i <= h; i++) {
            printGivenLevel(r, i);
        }
    }

    public void printGivenLevel(TreeNode r, int level) {
        if(r == null) {
            return;
        }
        else if(level == 0) {
            System.out.print(r.value + " ");
        }
        else {
            printGivenLevel(r.left, level - 1);
            printGivenLevel(r.right, level - 1);
        }
    }

    public TreeNode deleteNode(TreeNode r, int v) {
        TreeNode temp;
        if(r == null) {
            return r;
        }  
        else if(v < r.value) {
            r.left = deleteNode(r.left, v);
        }
        else if(v > r.value) {
            r.right = deleteNode(r.right, v);
        }
        else {
            if(r.left == null) {
                temp = r.right;
                return temp;
            }
            else if(r.right == null) {
                temp = r.left;
                return temp;
            }
            else {
                temp = minValueNode(r.right);
                r.value = temp.value;
                r.right = deleteNode(r.right, temp.value);
            }
        }

        int bf = getBalanceFactor(r);
        if(bf == 2 && getBalanceFactor(r.left) >= 0) {
            return rightRotate(r);
        }
        else if(bf == 2 && getBalanceFactor(r.left) == -1) {
            r.left = leftRotate(r.left);
            return rightRotate(r);
        }
        else if(bf == -2 && getBalanceFactor(r.right) <= 0) {
            return leftRotate(r);
        }
        else if(bf == -2 && getBalanceFactor(r.right) == 1) {
            r.right = rightRotate(r.right);
            return leftRotate(r);
        }

        return r;
    }

    TreeNode minValueNode(TreeNode node) {
        TreeNode current = node;;
        while(current.left != null) {
            current = current.left;
        }
        return current;
    }
}

class Main6 {
    public static void main(String[] args) {
        AVL obj = new AVL();
        int opt; 
        int val;
        boolean loop = true;
        Scanner cin = new Scanner(System.in);
        while(loop) {
            // cin.nextLine();
            System.out.print("1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print AVL Values\n5.Height of Tree\n0.Exit\nEnter your choice: ");
            TreeNode new_node = new TreeNode();
            opt = cin.nextInt();
            
            switch(opt) {
                case 0:
                    loop = false;
                    break;
                
                case 1:
                    System.out.println("Insert");
                    System.out.println("Enter value of tree node to insert in AVL: ");
                    val = cin.nextInt();
                    new_node = new TreeNode(val);
                    obj.root = obj.insertRecursive(obj.root, new_node);
                    System.out.println();
                    break;
    
                case 2:
                    System.out.println("Search");
                    System.out.println("Enter value to be searched: ");
                    val = cin.nextInt();
                    TreeNode new_nod = new TreeNode();
                    new_nod = obj.iterativeSearch(val);
                    if(new_nod != null) {
                        System.out.println("\nValue Found!!");
                    }
                    else {
                        System.out.println("\nValue Not Found!!");
                    }
                    break;
    
                case 3:
                    System.out.println("Delete");
                    System.out.println("Enter Value of node to be deleted: ");
                    val = cin.nextInt();
                    new_node = obj.iterativeSearch(val);
                    if(new_node != null) {
                        obj.deleteNode(obj.root, val);
                        System.out.println("Node deleted!!");
                    }
                    else {
                        System.out.println("Node not found!!");
                    }
                    break;
    
                case 4:
                    System.out.println("Print");
                    obj.printTree(obj);
                    break;
                
                case 5:
                    System.out.println("Height");
                    int h = obj.height(obj.root);
                    if(h == -1) {
                        System.out.println("Tree is empty!!");
                    }
                    else {
                        System.out.println("Height = " + h);
                    }
                    break;
                    
                default:
                    System.out.println("Enter A Valid Option!!");
                    break;
            }
            
        }
        cin.close();
    }
}