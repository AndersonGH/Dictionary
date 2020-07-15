#include <iostream>
#include <map>
#include "dictionary.h"




int main(){
    /*
    Dictionary <int,int> *dic = new My_dictionary <int,int> ();
    dic->Set(25,0);
    dic->Set(10,255);
    dic->Set(35,0);
    dic->Set(5,0);
    dic->Set(12,0);
    dic->Set(4,0);
    std::cout << dic->IsSet(100);
    */

    Avl <int,int> tree;
    tree.set(25,0);
    tree.set(10,255);
    tree.set(35,0);
    tree.set(5,0);
    tree.set(12,0);
    tree.set(4,0);
    Avl <int,int> tree1(tree);


    return 0;
}
