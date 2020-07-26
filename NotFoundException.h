#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H
#include <exception>


template<class TKey>
class NotFoundException : public std::exception{
public:
    virtual const TKey& GetKey() const noexcept = 0;
};

template<class TKey>
class MyNotFoundException: public NotFoundException <TKey>{
public:
    MyNotFoundException(const TKey&);
    const TKey& GetKey() const noexcept override;
private:
    TKey key;

};

template<class TKey>
MyNotFoundException<TKey>::MyNotFoundException(const TKey& key): key(key){}

template<class TKey>
const TKey& MyNotFoundException<TKey>::GetKey() const noexcept {
    return key;
}



#endif // NOTFOUNDEXCEPTION_H
