#include <iostream>
#include <map>
#include <avl.h>




int main(){
    Avl <int,int> tree;
    tree.insert(20,0);
    tree.insert(9,0);
    tree.insert(30,0);
    tree.insert(40,0);
    tree.insert(25,0);
    tree.insert(26,0);
    tree.insert(8,0);
    return 0;
}
