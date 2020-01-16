//
//  tree.cpp
//  tree
//
//  Created by Reham Islam on 11/28/17.
//  Copyright © 2017 Reham Islam. All rights reserved.
//

#include "tree.h"

tree::tree()
{
    root = NULL;
}

tree::~tree()
{
    makeEmpty(root);
    root = NULL;
}

void tree::input()
{   int data = 0;
    while (data !=  99999)
    {    cout << "Enter Data (Enter 99999 to finish): ";
         cin >> data;
	 if (data != 99999)  
         	insert(root,data);
    }
}

void tree::menu()
{   int option = 0;
    while(option != 5)
    {   cout << "Choose one from the following: \n 1. insert \t 2. Preorder \t 3. Postorder \t 4. Inorder \n 5. exit \n";
        cout << "Please Enter an Option: ";
	cin >> option;
        switch(option)
        {   case 1:
            {   input();
                break;
            }
            case 2:
            {   cout << "Preorder: ";
		preorder(root);
		cout << endl;
                break;
            }
            case 3:
            {   cout << "Postorder: ";
		postorder(root);
		cout << endl;
                break;
            }
            case 4:
            {   cout << "Inorder: ";
		inorder(root);
		cout << endl;
                break;
            }
            case 5:
            {   cout << "Thank you for stopping by." << endl;
                break;
            }
        }
    }
}

void tree::insert(node * &tree, int data)
{
    if(tree == NULL)
    {   node * temp;
	temp = new node;
        temp -> data = data;
        temp -> left = NULL;
        temp -> right = NULL;
	tree = temp;
    }
    else if(data > tree -> data)
    {   insert(tree -> right, data);
    }else if (data < tree -> data)
    {   insert(tree -> left, data);
    }else
	cout << "You can't enter samw number twice" << endl;	
        
}

void tree::makeEmpty(node *&tree)
{
    if(tree != NULL)
    {   makeEmpty(tree->right);
        makeEmpty(tree->left);
        delete tree;
    }
}

void tree::preorder(node *tree)
{   if(tree != NULL)
    {   cout << tree->data << "   ";
        preorder(tree -> left);
        preorder(tree -> right);
    }
}

void tree::postorder(node *tree)
{
    if(tree != NULL)
    {
        postorder(tree->left);
        postorder(tree -> right);
        cout << tree-> data << "   ";
    }
}

void tree::inorder(node *tree)
{
    if(tree != NULL)
    {   inorder(tree->left);
	cout << tree->data << "   ";
        inorder(tree-> right);
    }
}
