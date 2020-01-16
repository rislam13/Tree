//
//  tree.h
//
//  Created by Reham Islam on 11/28/17.
//  Copyright © 2017 Reham Islam. All rights reserved.
//

#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

struct node
{   struct node * left;
    int data;
    struct node * right;
};

class tree
{
public:
    tree();
    
    ~tree();
    void makeEmpty(node *& root);
    void insert(node *& root, int data);
    void input();
    void menu();
    
    void inorder(node * root);
    void postorder(node * root);
    void preorder(node * root);
    
    
private:
    node * root;
    
};


#endif /* tree_h */
