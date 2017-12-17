#ifndef CLIST_H
#define CLIST_H

#include <iostream>

template
<typename T>
class CList
{
public:
    CList();

    void pushBack(T const &val);

    void pushFront(T const &val);

    void insert(int index, T const &val);

    T popBack();

    T popFront();

    T pop(int index);

    int inline size() const;

    void show() const;

    void showReversed() const;

    T operator[](int index);

    ~CList();

private:
    struct Node
    {
        T val_;

        Node *next_, *prev_;
    };

    Node *head_, *tail_;

    int size_;
};

#endif // CLIST_H

template<typename T>
CList<T>::CList() : head_(nullptr), tail_(nullptr), size_(0)
{

}

template<typename T>
void CList<T>::pushBack(const T &val)
{
    Node* newElem = new Node;

    newElem->val_ = val;

    if (head_ == nullptr)
    {
        newElem->prev_ = nullptr;

        head_ = newElem;
    }

    else
    {
        newElem->prev_ = tail_;

        tail_->next_ = newElem;
    }

    tail_ = newElem;

    ++size_;
}

template<typename T>
void CList<T>::pushFront(T const &val)
{
    Node* newElem = new Node;

    newElem->val_ = val;

    if (head_ == nullptr)
    {
        head_ = newElem;
    }

    else
    {
        newElem->next_ = head_;

        head_->prev_ = newElem;

    }

    head_ = newElem;

    ++size_;
}

template<typename T>
void CList<T>::insert(int index, const T &val)
{
    if (index > size_ || index < 0)
    {
        throw std::runtime_error("Index out of range");
    }

    Node* temp = head_;

    Node* newElem = new Node;

    newElem->val_ = val;

    if (index == 0)
    {
        pushFront(val);
    }

    else if (index == size_)
    {
        pushBack(val);
    }

    else
    {
        for (int i=0; i<=index; ++i)
        {
            if (i == index)
            {
                newElem->next_ = temp;

                newElem->prev_ = temp->prev_;

                temp->prev_->next_ = newElem;

                temp->prev_ = newElem;

            }

            temp = temp->next_;
        }
    }
}

template<typename T>
T CList<T>::popBack()
{
    Node* temp = tail_;

    T tempVal = temp->val_;

    tail_ = temp->prev_;

    delete temp;

    --size_;

    return tempVal;
}

template<typename T>
T CList<T>::popFront()
{
    Node* temp = head_;

    T tempVal = temp->val_;

    head_ = temp->next_;

    delete temp;

    --size_;

    return tempVal;
}

template<typename T>
T CList<T>::pop(int index)
{
    if (index > size_ || index < 0)
    {
        throw std::runtime_error("Index out of range");
    }

    else if (index == 0)
    {
        popFront();
    }

    else if (index == size_)
    {
        popBack();
    }

    else
    {
        Node* temp = head_;

        for (int i=0; i<=index; ++i)
        {
            if (i == index)
            {
                T tempVal = temp->val_;

                temp->prev_->next_ = temp->next_;

                temp->next_->prev_ = temp->prev_;

                delete temp;

                return tempVal;
            }

            temp = temp->next_;
        }
    }

    return 0;
}

template<typename T>
int CList<T>::size() const
{
    return size_;
}

template<typename T>
void CList<T>::show() const
{
    if (head_ == nullptr)
    {
        throw std::runtime_error("No elements to show");
    }

    else
    {
        Node* temp = head_;

        while (temp != tail_->next_)
        {
            std::cout << temp->val_ << ' ';

            temp = temp->next_;
        }
    }
}

template<typename T>
void CList<T>::showReversed() const
{
    if (head_ == nullptr)
    {
        throw std::runtime_error("No elements to show");
    }

    else
    {
        Node* temp = tail_;

        while (temp != head_->prev_)
        {
            std::cout << temp->val_ << ' ';
            temp = temp->prev_;
        }
    }
}

template<typename T>
T CList<T>::operator[](int index)
{
    if (index >= size_ || index < 0)
    {
        throw std::runtime_error("Index out of range");
    }

    else
    {
        Node* temp = head_;

        for (int i=0; i<=index; ++i)
        {
            if (i == index)
            {
                return temp->val_;
            }

            temp = temp->next_;
        }
    }

    return 0;
}

template<typename T>
CList<T>::~CList()
{
    Node* temp;

    for (int i=0; i<size_; ++i)
    {
        temp = head_->next_;

        delete head_;

        head_ = temp;
    }
}
