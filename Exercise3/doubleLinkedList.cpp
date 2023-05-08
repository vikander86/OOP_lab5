// doublelinkedlist.cpp

#pragma once
#include <iostream>

template <typename T>
class Element
{
public:
    Element<T>(T data) : data(data), next(nullptr), prev(nullptr) {}
    ~Element()
    {
        prev = nullptr;
        next = nullptr;
    }

    Element *getNextElement()
    {
        return next;
    }
    Element *getPrevElement()
    {
        return prev;
    }
    T &getData()
    {
        return data;
    }
    Element *setNext(Element *nextElement)
    {
        next = nextElement;
        return next;
    }
    Element *setPrev(Element *prevElement)
    {
        prev = prevElement;
        return prev;
    }

private:
    Element *next;
    Element *prev;
    T data;
};

template <typename T>
class Container
{
public:
    Container() : head(nullptr), tail(nullptr), sizeOfContainer(0) {}

    ~Container()
    {
        clear();
    }

    // return pointer to the head of the container
    Element<T> *begin()
    {
        return head;
    }

    // return pointer to the tail of the container
    Element<T> *end()
    {
        return tail;
    }

    // push element to the front of the container
    Element<T> *pushFront(T data)
    {
        Element<T> *newElement = new Element<T>(data);
        Element<T> *currentHead = head;
        if (head != nullptr)
        {
            newElement->setNext(currentHead);
            currentHead->setPrev(newElement);
        }
        head = newElement;
        if (tail == nullptr)
        {
            tail = newElement;
        }
        sizeOfContainer++;
        return head;
    }

    // push element to the back of the container
    Element<T> *pushBack(T data)
    {
        Element<T> *newElement = new Element<T>(data);
        Element<T> *currentTail = tail;
        if (tail != nullptr)
        {
            newElement->setPrev(currentTail);
            currentTail->setNext(newElement);
        }
        tail = newElement;
        if (head == nullptr)
        {
            head = newElement;
        }
        sizeOfContainer++;
        return tail;
    }

    // insert
    Element<T> *insert(T data, int index)
    {
        if (empty())
        {
            std::cout << "Container is empty" << std::endl;
            return head;
        }
        if (index < 0 || index > sizeOfContainer - 1)
        {
            std::cout << "Out of scope" << std::endl;
            return head;
        }

        Element<T> *newElement = new Element<T>(data);
        Element<T> *currentHead = head;
        int pos = 0;
        while (currentHead != nullptr)
        {
            if (index == 0)
            {
                pushFront(data);
                return head;
            }
            else if (pos == index)
            {
                Element<T> *currentHeadNext = currentHead->getNextElement();
                Element<T> *currentHeadPrev = currentHead->getPrevElement();
                currentHeadPrev->setNext(newElement);
                newElement->setPrev(currentHeadPrev);
                newElement->setNext(currentHead);
                currentHead->setNext(currentHeadNext);
                currentHeadNext->setPrev(currentHead);
                sizeOfContainer++;
                return head;
            }
            currentHead = currentHead->getNextElement();
            pos++;
        }
        return head;
    }

    Element<T> *erase(int index)
    {
        if (empty())
        {
            std::cout << "Container is empty" << std::endl;
            return head;
        }
        if (index < 0 || index > sizeOfContainer - 1)
        {
            std::cout << "Out of scope" << std::endl;
            return head;
        }
        Element<T> *currentHead = head;
        int pos = 0;
        while (currentHead != nullptr)
        {
            if (index == 0)
            {
                popFront();
                return head;
            }
            else if (index == sizeOfContainer - 1)
            {
                popBack();
                return head;
            }
            else if (pos == index)
            {
                currentHead->getPrevElement()->setNext(currentHead->getNextElement());
                currentHead->getNextElement()->setPrev(currentHead->getPrevElement());
                std::cout << "Erasing: " << currentHead->getData() << std::endl;
                delete currentHead;
                sizeOfContainer--;
                return head;
            }
            pos++;
            currentHead = currentHead->getNextElement();
        }
        return head;
    }

    Element<T> *popFront()
    {
        if (empty())
        {
            std::cout << "Container empty" << std::endl;
            return head;
        }
        Element<T> *temp = head;
        std::cout << "Erasing: " << temp->getData() << std::endl;
        head = head->getNextElement();
        if (head != nullptr)
        {
            head->setPrev(nullptr);
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
        sizeOfContainer--;
        return head;
    }
    Element<T> *popBack()
    {
        if (empty())
        {
            std::cout << "Container empty" << std::endl;
            return tail;
        }
        Element<T> *temp = tail;
        std::cout << "Erasing: " << temp->getData() << std::endl;
        tail = tail->getPrevElement();
        if (tail != nullptr)
        {
            tail->setNext(nullptr);
        }
        else
        {
            head = nullptr;
        }
        delete temp;
        sizeOfContainer--;
        return tail;
    }
    // check if container is empty
    bool empty()
    {
        return sizeOfContainer == 0;
    }

    // clear container
    void clear()
    {
        while (head != nullptr)
        {
            Element<T> *temp = head;
            head = head->getNextElement();
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        sizeOfContainer = 0;
        std::cout << "Container is cleared" << std::endl;
    }

    // return size of container
    size_t size() const
    {
        return sizeOfContainer;
    }

    // print each of the element's data value
    void print() const
    {
        Element<T> *current = head;
        int index = 0;
        while (current != nullptr)
        {
            std::cout << "index: " << index << " " << current->getData() << std::endl;
            current = current->getNextElement();
            index++;
        }
    }

    void printFromTail() const
    {
        Element<T> *current = tail;
        int index = sizeOfContainer - 1;
        while (current != nullptr)
        {
            std::cout << "index: " << index << " " << current->getData() << std::endl;
            current = current->getPrevElement();
            index--;
        }
    }

private:
    Element<T> *head;
    Element<T> *tail;
    size_t sizeOfContainer;
};