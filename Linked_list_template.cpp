#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }

    // insert node at front
    void addToFront(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // insert node at the end
    void addToBack(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert node
    void insertAtPosition(T value, int position)
    {
        Node<T> *newNode = new Node<T>(value);
        if (position <= 0)
        {
            addToFront(value);
        }
        else
        {
            Node<T> *current = head;
            for (int i = 1; i < position && current; ++i)
            {
                current = current->next;
            }
            if (current)
            {
                newNode->next = current->next;
                current->next = newNode;
                if (!newNode->next)
                {
                    tail = newNode;
                }
            }
            else
            {
                std::cerr << "Invalid position for insertion." << std::endl;
            }
        }
    }

    // Delete node
    void deleteAtPosition(int position)
    {
        if (!head)
        {
            std::cerr << "List is empty. Cannot delete." << std::endl;
            return;
        }

        if (position <= 0)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            if (!head)
            {
                tail = nullptr;
            }
        }
        else
        {
            Node<T> *current = head;
            Node<T> *previous = nullptr;

            for (int i = 0; i < position && current; ++i)
            {
                previous = current;
                current = current->next;
            }

            if (current)
            {
                previous->next = current->next;
                delete current;
                if (!previous->next)
                {
                    tail = previous;
                }
            }
            else
            {
                std::cerr << "Invalid position for deletion." << std::endl;
            }
        }
    }

    // Find node
    Node<T> *search(T value)
    {
        Node<T> *current = head;
        while (current)
        {
            if (current->data == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Display linked list
    void display()
    {
        Node<T> *current = head;
        while (current)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~LinkedList()
    {
        Node<T> *current = head;
        while (current)
        {
            Node<T> *temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }
};

int main()
{
    LinkedList<int> intList;

    intList.addToBack(1);
    intList.addToBack(2);
    intList.addToBack(3);
    intList.addToFront(0);

    std::cout << "Original Integer Linked List: ";
    intList.display();

    intList.insertAtPosition(4, 2);
    std::cout << "Integer Linked List After Insertion: ";
    intList.display();

    intList.deleteAtPosition(2);
    std::cout << "Integer Linked List After Deletion: ";
    intList.display();

    Node<int> *searchResult = intList.search(2);
    if (searchResult)
    {
        std::cout << "Found: " << searchResult->data << std::endl;
    }
    else
    {
        std::cout << "Not Found." << std::endl;
    }

    LinkedList<double> doubleList;

    doubleList.addToBack(1.5);
    doubleList.addToBack(2.5);
    doubleList.addToBack(3.5);
    doubleList.addToFront(0.5);

    std::cout << "Original Double Linked List: ";
    doubleList.display();

    doubleList.insertAtPosition(4.5, 2);
    std::cout << "Double Linked List After Insertion: ";
    doubleList.display();

    doubleList.deleteAtPosition(2);
    std::cout << "Double Linked List After Deletion: ";
    doubleList.display();

    Node<double> *searchResultDouble = doubleList.search(2.5);
    if (searchResultDouble)
    {
        std::cout << "Found: " << searchResultDouble->data << std::endl;
    }
    else
    {
        std::cout << "Not Found." << std::endl;
    }

    return 0;
}
