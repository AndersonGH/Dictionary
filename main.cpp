#include <iostream>
#include <map>
#include "dictionary.h"




int main(){
    Dictionary <int,int> *dic = new My_dictionary <int,int> ();
    dic->Set(25,0);
    dic->Set(10,0);
    dic->Set(35,0);
    dic->Set(5,0);
    dic->Set(12,0);
    dic->Set(4,0);

    return 0;
}
