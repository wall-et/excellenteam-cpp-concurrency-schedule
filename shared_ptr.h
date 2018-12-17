//
// Created by alian on 12/17/18.
//


#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHARED_POINTER_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHARED_POINTER_H

#include <iostream>

template<typename T>
class shared_ptr
{
public :

    explicit shared_ptr(T *ptr = NULL);
    ~shared_ptr();

    shared_ptr(const shared_ptr &ptr);
    shared_ptr& operator =(const shared_ptr &ptr);
    shared_ptr& operator =(T*);


    bool isvalid() const;
    int getCount() const;//for testing
    T* get() const;

    operator bool() const;
    bool operator!=(const shared_ptr& other) const;
    bool operator==(const shared_ptr& other) const;

    template <class U>
    shared_ptr(const shared_ptr<U>&pt);

    template <class U>
    friend class shared_ptr;

    T* operator ->() const;
    T& operator *() const;

private :
    size_t *refCount;
    T* m_ptr;

    void release();
    void swap(shared_ptr &other);

};

template<typename T>
shared_ptr<T>::shared_ptr(T *ptr)try :m_ptr(ptr)
{
    refCount = new size_t(1);
}
catch (std::bad_alloc& e)
{
    delete ptr;
    throw ;
}

template<typename T>
void shared_ptr<T>::release()
{
    if((*refCount) <= 0)
    {
        delete refCount;
        delete m_ptr;
    }

}
template<typename T>
shared_ptr<T>::~shared_ptr()
{
    if(isvalid())
    {
        --(*refCount);
        release();
        refCount = NULL;
        m_ptr = NULL;
    }
}

template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr &ptr) : refCount(ptr.refCount), m_ptr(ptr.m_ptr)
{
    if(isvalid())
        (*refCount)++;
}

template<typename T>
void shared_ptr<T>::swap(shared_ptr &other)
{
    std::swap(m_ptr,other.m_ptr);
    std::swap(refCount,other.refCount);
}

template<typename T>
shared_ptr<T>& shared_ptr<T>:: operator =(const shared_ptr &ptr)
{
    shared_ptr<T> temp(ptr);
    swap(temp);

    return *this;
}

template<typename T>
shared_ptr<T>& shared_ptr<T>:: operator =(T* other)
{   //TODO release()
    //TODO try & catch with other

    return *this;
}

template<typename T>
bool shared_ptr<T>::isvalid() const
{
    return (m_ptr != NULL && refCount != NULL);
}

template<typename T>
int shared_ptr<T>:: getCount() const
{
    if(refCount != NULL)
        return *refCount;
    else
        return 0;
}

template<typename T>
T* shared_ptr<T>::operator ->() const
{
    return m_ptr;
}

template<typename T>
T& shared_ptr<T>::operator *()const
{
    return *m_ptr;
}

template<typename T>
bool shared_ptr<T>::operator==(const shared_ptr& other) const
{
    return (m_ptr==other.m_ptr)&&(refCount==other.refCount);
}

template<typename T>
bool shared_ptr<T>:: operator!=(const shared_ptr& other) const
{
    return (m_ptr != other.m_ptr);
}

template<typename T>
T * shared_ptr<T>:: get() const
{
    return m_ptr;
}

template<typename T>
shared_ptr<T>::operator bool()const
{
    return dynamic_cast<T *>(get()) != NULL;
}

template<typename T>
template<typename U>
shared_ptr<T>::shared_ptr(const shared_ptr<U>& ptr)
        :refCount(ptr.refCount),
         m_ptr(ptr.m_ptr)
{
    if(isvalid())
        (*refCount)++;
}

#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHARED_POINTER_H

