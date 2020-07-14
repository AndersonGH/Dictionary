#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include "avl.h"

template<class TKey, class TValue>
class Dictionary{
public:
    virtual ~Dictionary() = default;

    virtual const TValue& Get(const TKey& key) const = 0;
    virtual void Set(const TKey& key, const TValue& value) = 0;
    virtual bool IsSet(const TKey& key) const = 0;
};

template<class TKey>
class NotFoundException : public std::exception{
public:
    virtual const TKey& GetKey() const noexcept = 0;
};

template<class TKey, class TValue>
class My_dictionary:public Dictionary <TKey,TValue>{
public:
    My_dictionary();
    void Set(const TKey& key, const TValue& value);
    const TValue& Get(const TKey& key) const;
    bool IsSet(const TKey& key) const;
private:
    Avl <TKey,TValue> *data;

};

template<class TKey, class TValue>
My_dictionary<TKey,TValue>::My_dictionary(): data(new Avl <TKey,TValue>()){}

template<class TKey, class TValue>
void My_dictionary<TKey,TValue>::Set(const TKey& key, const TValue& value){
    this->data->insert(key, value);
}

template<class TKey, class TValue>
const TValue& My_dictionary<TKey,TValue>::Get(const TKey& key) const{}

template<class TKey, class TValue>
bool My_dictionary<TKey,TValue>::IsSet(const TKey& key) const{}




#endif // DICTIONARY_H
