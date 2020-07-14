#ifndef AVL_H
#define AVL_H

#include "NotFoundException.h"
#include <cstddef>
#include <algorithm>

template<class TKey, class TValue>
struct Node{
    Node(const TKey& k, const TValue& v, Node *left = nullptr, Node *right = nullptr);
    TKey key;
    TValue val;
    Node *left;
    Node *right;
    size_t height;
};

template<class TKey, class TValue>
class Avl{
public:
    Avl();
    void set(const TKey& key, const TValue& value);
    const TKey& find(const TKey& key);
    bool IsSet(const TKey& key) const;
    ~Avl();

private:
    bool IsSet(const TKey& key, Node <TKey, TValue> *) const;
    Node <TKey, TValue> * find(const TKey& key, Node <TKey, TValue> *);
    int height(Node <TKey, TValue> *);
    void freeAvl(Node <TKey, TValue> *);
    void set(const TKey& key, const TValue& value, Node <TKey, TValue> *&);
    void balance(Node <TKey, TValue> *&);
    void leftRotation(Node <TKey, TValue> *&);
    void rightRotation(Node <TKey, TValue> *&);
    Node <TKey, TValue> *root = nullptr;

};

template<class TKey, class TValue>
Node<TKey,TValue>::Node(const TKey& k, const TValue& v, Node *l , Node *r):
    key(k),val(v), left(l),right(r), height(1){}

template<class TKey, class TValue>
void Avl<TKey,TValue>::freeAvl(Node <TKey, TValue> * node){
    if(node){
        freeAvl(node->left);
        freeAvl(node->right);
        delete node;
    }
}

template<class TKey, class TValue>
bool Avl<TKey,TValue>::IsSet(const TKey& key) const {
    return IsSet(key,root);
}


template<class TKey, class TValue>
bool Avl<TKey,TValue>::IsSet(const TKey& key,Node <TKey, TValue> * node) const {
    if(node == nullptr)
        return false;
    if(node->key == key){
        return true;
    }
    else if(node->key > key)
        IsSet(key, node->left);
    else
        IsSet(key, node->right);
}

template<class TKey, class TValue>
void Avl<TKey,TValue>::leftRotation(Node <TKey, TValue> *&node){
    Node <TKey, TValue> *copy = node->right;
    node->right = copy->left;
    copy->left = node;
    node = copy;
}

template<class TKey, class TValue>
const TKey& Avl<TKey,TValue>::find(const TKey& key){
    Node <TKey, TValue> * node = find(key, root);
    if(node)
        return node->val;
    else
        throw MyNotFoundException<TKey>(key);
}

template<class TKey, class TValue>
Node <TKey, TValue> * Avl<TKey,TValue>::find(const TKey& key, Node <TKey, TValue> * node){
    if(node == nullptr)
        return nullptr;
    if(node->key == key){
        return node;
    }
    else if(node->key > key)
        find(key, node->left);
    else
        find(key, node->right);
}


template<class TKey, class TValue>
int Avl<TKey,TValue>::height(Node <TKey, TValue> *node){
    if(node == nullptr )
        return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

template<class TKey, class TValue>
void Avl<TKey,TValue>::rightRotation(Node <TKey, TValue> *&node){
    Node <TKey, TValue> *copy = node->left;
    node->left = copy->right;
    copy->right = node;
    node = copy;
}


template<class TKey, class TValue>
Avl<TKey,TValue>::~Avl(){
    freeAvl(root);
}

template<class TKey, class TValue>
Avl<TKey,TValue>::Avl(){}

template<class TKey, class TValue>
void Avl<TKey,TValue>::set(const TKey& k, const TValue& v, Node <TKey, TValue> *& node){
    if(node == nullptr){
        node = new Node<TKey,TValue>(k,v);
        return;
    }
    if(node->key == k)
        node->val = v;
    else if(node->key > k)
        set(k, v, node->left);
    else
        set(k, v, node->right);
    node->height = height(node);
    balance(node);
}

template<class TKey, class TValue>
void Avl<TKey,TValue>::balance(Node <TKey, TValue> *& node){
    if( ( height(node->right) - height(node->left) ) == -2){
        if(node->height == 4 && (node->left->right->left || node->left->right->right))
            leftRotation(node->left);
        rightRotation(node);
    }
    if( ( height(node->right) - height(node->left) ) == 2){
        if(node->height == 4 && (node->right->left->left || node->right->left->right))
            rightRotation(node->right);
        leftRotation(node);
    }
}


template<class TKey, class TValue>
void Avl<TKey,TValue>::set(const TKey& key, const TValue& value){
    set(key, value,root);
}

#endif // AVL_H
