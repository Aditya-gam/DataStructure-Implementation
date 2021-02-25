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
                        cout << "Value inserted" << endl;
                        break;
                    }  

                }
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
};
 
int main() {
    int opt;
    while(true) {
        cout << "1.Insert Node\n2.Search Node\n3.Delete Node\n4.Print BST Values\n5.Clear Screen\n0.Exit\nEnter your choice: ";
        cin >> opt;

        switch(opt) {
            case 0:
                exit(0);
                break;
            
            case 1:
                cout << "Insert" << endl;
                break;

            case 2:
                cout << "Search" << endl;
                break;

            case 3:
                cout << "Delete" << endl;
                break;

            case 4:
                cout << "Print" << endl;
                break;

            case 5:
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