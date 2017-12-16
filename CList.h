#ifndef CLIST_H
#define CLIST_H

#include <iostream>

template
<typename T>
class CList
{
public:
    CList() : head_(nullptr), tail_(nullptr), size_(0)
    {

    }

    void pushBack(T val)
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

    void pushFront(T val)
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

    T popBack()
    {
        Node* temp = tail_;

        T tempVal = temp->val_;

        tail_ = temp->prev_;

        delete temp;

        --size_;

        return tempVal;
    }

    T popFront()
    {
        Node* temp = head_;

        T tempVal = temp->val_;

        head_ = temp->next_;

        delete temp;

        --size_;

        return tempVal;
    }

    int size()
    {
        return size_;
    }

    void show()
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

    void showReversed()
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

    T operator[](int index)
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
    }

    ~CList()
    {
        Node* temp;

        for (int i=0; i<size_; ++i)
        {
            temp = head_->next_;

            delete head_;

            head_ = temp;
        }
    }

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
