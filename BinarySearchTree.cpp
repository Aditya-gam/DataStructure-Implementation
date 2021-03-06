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

class BST {
    public:
        TreeNode* root;

        BST() {
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
        
        void insertNode(TreeNode *new_node) {

            if(root == NULL) {
                root = new_node;
                cout << "Value Inserted as root node" << endl;
            }

            else {
                TreeNode *temp = root;

                while(temp != NULL) {

                    if(new_node->value == temp->value) {
                        cout << "Value already exists, Enter another value" << endl;
                        return;
                    }  
                    else if((new_node->value < temp->value) && (temp->left == NULL)) {
                        temp->left = new_node;
                        cout << "Value inserted to left" << endl;
                        break;
                    }  
                    else if(new_node->value < temp->value) {
                        temp = temp->left;
                    }
                    else if((new_node->value > temp->value) && (temp->right == NULL)) {
                        temp->right = new_node;
                        cout << "Value inserted to right" << endl;
                        break;
                    }  
                    else if(new_node->value > temp->value) {
                        temp = temp->right;
                    }


                }
            }
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
            return r;
        }
};

void printTree(BST obj) {
    int opt;
    cout << "\n1.Print 2D\n2.Print Preorder\n3.Print Inorder\n4.Print Postorder\n5.Print Level Order\nEnter your choice: " << endl;
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
    BST obj;
    int opt, val;
    while(true) {
        cout << "\n1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print BST Values\n5.Height Of Tree\n6.Clear Screen\n0.Exit\nEnter your choice: ";
        cin >> opt;
        TreeNode *new_node = new TreeNode();
        switch(opt) {
            case 0:
                exit(0);
                break;
            
            case 1:
                cout << "Insert" << endl;
                cout << "\nEnter value of tree node to insert in BST: ";
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