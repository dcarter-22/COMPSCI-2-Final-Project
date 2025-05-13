#ifndef BST_H
#define BST_H

#include <iostream>
#include <functional>

using namespace std;

template <typename T>
class BST
{
private:
    struct Node
    {
        T *data;
        Node *left;
        Node *right;

        Node(T *d)
        {
            data = d;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;

    void insert(Node *&node, T *data, function<bool(const T *, const T *)> comp)
    {
        if (node == nullptr)
        {
            node = new Node(data);
            return;
        }
        if (comp(data, node->data))
        {
            insert(node->left, data, comp);
        }
        else
        {
            insert(node->right, data, comp);
        }
    }

    T *search(Node *node, function<int(const T *)> keyFunc, int key)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        int nodeKey = keyFunc(node->data);
        if (key == nodeKey)
        {
            return node->data;
        }
        if (key < nodeKey)
        {
            return search(node->left, keyFunc, key);
        }
        return search(node->right, keyFunc, key);
    }

    void inorder(Node *node, function<void(T *)> visit)
    {
        if (node == nullptr) return;
        inorder(node->left, visit);
        visit(node->data);
        inorder(node->right, visit);
    }

    void clear(Node *node)
    {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node->data;
        delete node;
    }

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        clear(root);
    }

    void insert(T *data, function<bool(const T *, const T *)> comp)
    {
        insert(root, data, comp);
    }

    T *search(function<int(const T *)> keyFunc, int key)
    {
        return search(root, keyFunc, key);
    }

    void inorder(function<void(T *)> visit)
    {
        inorder(root, visit);
    }
};

#endif
