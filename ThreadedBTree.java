class TBTNode {
    int data;
    int leftBit; /* 0:inorder predecessor 1: left child */
    int rightBit; /* 0:inorder successor 1: right child */
    TBTNode left;
    TBTNode right;
 
    public TBTNode(int data) {
       this.data = data;
    }
 };

class ThreadedBT {
    public static TBTNode root;
    public static boolean Left;
    public static boolean Right;

    public ThreadedBT() {
        //create the dummy node
        root = new TBTNode(9999);
        root.leftBit = 0;
        root.rightBit = 1;
        root.left = root.right = root;
    }

    public void insert(int data) {
        TBTNode n = new TBTNode(data);
        //check if new node is going to be first actual node in the tree.
        if (root == root.left && root.right == root) {
            n.left = root;
            root.left = n;
            n.leftBit = root.leftBit;
            root.leftBit = 1;
            n.right = root;
        } 
        else {
            TBTNode current = root.left;
            while (true) {
                if (current.data > n.data) {
                    if (current.leftBit == 0) {
                        //node will be added as left child
                        Left = true;
                        Right = false;
                        break;
                    } 
                    else {
                        current = current.left;
                    }
                } 
                else {
                    if (current.rightBit == 0) {
                        //node will be added as right child
                        Left = false;
                        Right = true;
                        break;
                    } 
                    else {
                        current = current.right;
                    }
                }
            }
            if (Left) {
                //add the node as left child
                n.left = current.left;
                current.left = n;
                n.leftBit = current.leftBit;
                current.leftBit = 1;
                n.right = current;
            } 
            else if (Right) {
                //add the node as right child
                n.right = current.right;
                current.right = n;
                n.rightBit = current.rightBit;
                current.rightBit = 1;
                n.left = current;
            }
        }
    }

    public void inorder() {
        //start from the left child of the dummy node
        TBTNode current = root.left;
        //go to the left most node
        while (current.leftBit == 1) {
            current = current.left;
        }
        //now keep traversing the next inorder successor and print it
        while (current != root) {
            System.out.print("  " + current.data);
            current = findNextInorder(current);
        }
    }

    public TBTNode findNextInorder(TBTNode current) {
        //if rightBit of current node is 0 means current node does not
        //have right child so use the right pointer to move to its
        // inorder successor.
        if (current.rightBit == 0) {
            return current.right;
        }
        //if //if rightBit of current node is 0 means current node does
        //have right child so go to the left most node in right sub tree.
        current = current.right;
        while (current.leftBit != 0) {
            current = current.left;
        }
        return current;
    }
    public static void main(String args[]){
        ThreadedBT i = new ThreadedBT();
        i.insert(10);
        i.insert(12);
        i.insert(15);
        i.insert(2);
        i.insert(13);
        i.insert(1);
        i.insert(4);
        i.inorder();
    }
}
 