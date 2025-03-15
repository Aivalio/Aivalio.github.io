#include <stdio.h>
#include <stdlib.h>

// Δομή κόμβου της λίστας
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Δομή της λίστας
typedef struct {
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList;

// Δημιουργία λίστας
DoublyLinkedList* Create();

// Πληροφορίες λίστας
int Size(DoublyLinkedList* list);
int IsEmpty(DoublyLinkedList* list);

// Πρόσβαση σε στοιχεία
int GetFirst(DoublyLinkedList* list);
int GetLast(DoublyLinkedList* list);
Node* GetNode(DoublyLinkedList* list, int i);
int GetPrev(Node* node);
int GetNext(Node* node);

// Προσθήκη κόμβων
void AddBefore(DoublyLinkedList* list, Node* node, int i);
void AddAfter(DoublyLinkedList* list, Node* node, int i);
void AddFirst(DoublyLinkedList* list, int i);
void AddLast(DoublyLinkedList* list, int i);

// Διαγραφή κόμβων
void Remove(DoublyLinkedList* list, int i);

// Εκτύπωση λίστας
void Print(DoublyLinkedList* list);
