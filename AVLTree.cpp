#include<bits/stdc++.h>

using namespace std;

#define SPACE 10

class TreeNode {
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode() {
            value = 0;
            left = NULL;
            right = NULL;
        }

        TreeNode(int v) {
            value = v;
            left = NULL;
            right = NULL;
        }
};

class AVL {
    public:
        TreeNode* root;

        AVL() {
            root = NULL;
        }

        bool isEmpty() {

            if(root == NULL) {
                return true;
            }
            else {
                return false;
            }
        }

        int height(TreeNode *r) {
            if(r == NULL) {
                return -1;
            }
            else {
                int lheight = height(r->left);
                int rheight = height(r->right);

                if(lheight > rheight) {
                    return (lheight + 1);
                }
                else {
                    return (rheight + 1);
                }
            }
        }

        int getBalanceFactor(TreeNode *n) {
            if(n == NULL) {
                return -1;
            }
            return (height(n->left) - height(n->right));
        }
        
        TreeNode* rightRotate(TreeNode *y) {
            TreeNode *x = y->left;
            TreeNode *T2 = x->right;

            x->right = y;
            y->left = T2;
            cout << "\nRotated Right!!" << endl;

            return x;
        }
        
        TreeNode* leftRotate(TreeNode *x) {
            TreeNode *y = x->right;
            TreeNode *T2 = y->left;

            y->left = x;
            x->right = T2;
            cout << "\nRotated Left!!" << endl;

            return y;
        }
        
        TreeNode* insertRecursive(TreeNode* r, TreeNode* new_node) {
            if(r == NULL) {
                r = new_node;
                cout << "\nValue Inserted" << endl;
                return r;
            }

            if(new_node->value < r->value){
                r->left = insertRecursive(r->left, new_node);
            }
            else if(new_node->value > r->value) {
                r->right = insertRecursive(r->right, new_node);
            }
            else {
                cout << "\nNo Duplicates Allowed!!" << endl;
                return r;
            }

            int bf = getBalanceFactor(r);
            // Left Left Case
            if(bf > 1 && new_node->value < r->left->value) {
                return rightRotate(r);
            }
            // Right Right Case
            if(bf < -1 && new_node->value > r->right->value) {
            return leftRotate(r);
            }
            // Left Right Case
            if(bf > 1 && new_node->value > r->left->value) {
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            // Right Left Case
            if(bf < -1 && new_node->value < r->right->value) {
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }

            return r;
        }

        TreeNode* iterativeSearch(int val) {
            if(root == NULL) {
                return root;
            }
            else {
                TreeNode *temp = root;

                while(temp != NULL) {
                    if(val == temp->value) {
                        return temp;
                    }    
                    else if(val < temp->value) {
                        temp = temp->left;
                    }
                    else {
                        temp = temp->right;
                    }
                }

                return NULL;
            }
        }
        
        void print2D(TreeNode *r, int space) {
            if (r == NULL) {
                return ;
            }

            space += SPACE;
            print2D(r->right, space);
            cout << endl;
            for(int i = SPACE; i < space; i++) {
                cout << " ";
            }
            cout << r->value << "\n";
            print2D(r->left, space);
        }

        void printPreorder(TreeNode* r) {
            if(r == NULL) {
                return;
            }
            cout << r->value << " ";

            printPreorder(r->left);
            
            printPreorder(r->right);
        }

        void printInorder(TreeNode* r) {
            if(r == NULL) {
                return;
            }

            printInorder(r->left);

            cout << r->value << " ";
                
            printInorder(r->right);
        } 

        void printPostorder(TreeNode *r) {
            if(r == NULL) {
                return;
            }

            printPostorder(r->left);

            printPostorder(r->right);

            cout << r->value << " ";
        }

        void printGivenLevel(TreeNode *r, int level) {
            if(r == NULL) {
                return;
            }
            else if(level == 0) {
                cout << r->value << " ";
            }
            else {
                printGivenLevel(r->left, level);
                printGivenLevel(r->right, level);
            }
        }

        void printLevelorder(TreeNode* r) {
            int h = height(r);

            for(int i = 0; i <= h; i++) {
                printGivenLevel(r, i);
            }
        }

        TreeNode* minValueNode(TreeNode* node) {
            TreeNode* current = node;

            while (current->left != NULL) {
                current = current->left;
            }
            return current;
        }
        
        TreeNode* deleteNode(TreeNode* r, int v) {
            if(r == NULL) {
                return NULL;
            }
            else if(v < r->value) {
                r->left = deleteNode(r->left, v);
            }
            else if(v > r->value) {
                r->right = deleteNode(r->right, v);
            }
            else {
                if(r->left == NULL) {
                    TreeNode* temp = r->right;
                    delete r;
                    return temp;
                }
                else if(r->right == NULL) {
                    TreeNode* temp = r->left;
                    delete r;
                    return temp;
                }
                else {
                    TreeNode* temp = minValueNode(r->right);
                    r->value = temp->value;
                    r->right = deleteNode(r->right, temp->value);
                }
            }

            int bf = getBalanceFactor(r);
            if(bf == 2 && getBalanceFactor(r->left) >= 0) {
            return rightRotate(r);
            }
            else if(bf == 2 && getBalanceFactor(r->left) == -1) {
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            else if(bf == -2 && getBalanceFactor(r->right) <= 0) {
                return leftRotate(r);
            }
            else if(bf == -2 && getBalanceFactor(r->right) == 1) {
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }

            return r;
        }
};

void printTree(AVL obj) {
    int opt;
    cout << "\n1->Print 2D\n2->Print Preorder\n3->Print Inorder\n4->Print Postorder\n5->Print Level Order\nEnter your choice: " << endl;
    cin >> opt;

    switch(opt) {
        case 1:
            obj.print2D(obj.root, 5);
            break;
        
        case 2:
            obj.printPreorder(obj.root);
            break;
        
        case 3:
            obj.printInorder(obj.root);
            break;

        case 4:
            obj.printPostorder(obj.root);
            break;

        case 5:
            obj.printLevelorder(obj.root);
            break;
            
        default:
            cout << "Enter a valid option" << endl;
            break;
    }
}
 
int main() {
    AVL obj;
    int opt, val;
    while(true) {
        cout << "\n1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print AVL Values\n5.Height Of Tree\n6.Clear Screen\n0.Exit\nEnter your choice: ";
        cin >> opt;
        TreeNode *new_node = new TreeNode();
        switch(opt) {
            case 0:
                exit(0);
                break;
            
            case 1:
                cout << "Insert" << endl;
                cout << "\nEnter value of tree node to insert in AVL: ";
                cin >> val;                 
                new_node->value = val;
                obj.root = obj.insertRecursive(obj.root, new_node);
                cout << endl;
                break;

            case 2:
                cout << "Search" << endl;
                cout << "\nEnter value to be searched: ";
                cin >> val;
                new_node = obj.iterativeSearch(val);
                if(new_node != NULL) {
                    cout << "\nValue Found!!";
                }
                else {
                    cout << "\nValue Not Found!!";
                }
                break;

            case 3:
                cout << "Delete" << endl;
                cout << "\nEnter value of node to be deleted: ";
                cin >> val;
                new_node = obj.iterativeSearch(val);
                if(new_node != NULL) {
                    obj.deleteNode(obj.root, val);
                    cout << "\nValue Deleted!!";
                }
                else {
                    cout << "\nValue not found!!";
                }
                break;

            case 4:
                printTree(obj);
                break;

            case 5:
                cout << "Tree Height" << endl;
                cout << "Height: " << obj.height(obj.root) << endl;
                break;
                
            case 6:
                // cout << "Clear Screen" << endl;
                system("cls");
                break;

            default:
                cout << "Enter A Valid Option!!" << endl;
                break;
        }
        
    }

    return 0;
}