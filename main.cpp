#include <iostream>
#include <map>
#include "dictionary.h"




int main(){

    Dictionary <int,int> *dic = new My_dictionary <int,int> ();
    dic->Set(25,0);
    dic->Set(10,255);
    dic->Set(35,0);
    dic->Set(5,0);
    dic->Set(12,0);
    dic->Set(4,0);
    try {
    std::cout << dic->Get(100);
    } catch (NotFoundException <int> & e) {
        std::cout << e.GetKey();
    }

    return 0;
}
