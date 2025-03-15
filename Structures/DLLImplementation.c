#include "DoublyLinkedList.h"

// Δημιουργία κενής λίστας
DoublyLinkedList* Create() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (list == NULL) {
        printf("Σφάλμα: Αδυναμία κατανομής μνήμης!\n");
        exit(1);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Επιστροφή μεγέθους λίστας
int Size(DoublyLinkedList* list) {
    return list->size;
}

// Έλεγχος αν η λίστα είναι κενή
int IsEmpty(DoublyLinkedList* list) {
    return (list->size == 0);
}

// Επιστροφή του πρώτου στοιχείου
int GetFirst(DoublyLinkedList* list) {
    if (list == NULL || list->head == NULL) {
        printf("Σφάλμα: Η λίστα είναι κενή!\n");
        exit(1);
    }
    return list->head->data;
}

// Επιστροφή του τελευταίου στοιχείου
int GetLast(DoublyLinkedList* list) {
    if (list == NULL || list->tail == NULL) {
        printf("Σφάλμα: Η λίστα είναι κενή!\n");
        exit(1);
    }
    return list->tail->data;
}

// Επιστροφή δείκτη στον πρώτο κόμβο που περιέχει το i
Node* GetNode(DoublyLinkedList* list, int i) {
    if (list == NULL) return NULL;
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == i) return current;
        current = current->next;
    }
    return NULL;
}

// Επιστροφή προηγούμενου στοιχείου από έναν κόμβο
int GetPrev(Node* node) {
    if (node == NULL || node->prev == NULL) {
        printf("Σφάλμα: Δεν υπάρχει προηγούμενο στοιχείο!\n");
        exit(1);
    }
    return node->prev->data;
}

// Επιστροφή επόμενου στοιχείου από έναν κόμβο
int GetNext(Node* node) {
    if (node == NULL || node->next == NULL) {
        printf("Σφάλμα: Δεν υπάρχει επόμενο στοιχείο!\n");
        exit(1);
    }
    return node->next->data;
}

// Εισαγωγή κόμβου πριν από έναν συγκεκριμένο κόμβο
void AddBefore(DoublyLinkedList* list, Node* node, int i) {
    if (list == NULL || node == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = i;
    newNode->prev = node->prev;
    newNode->next = node;
    
    if (node->prev != NULL) node->prev->next = newNode;
    else list->head = newNode;
    
    node->prev = newNode;
    list->size++;
}

// Εισαγωγή κόμβου μετά από έναν συγκεκριμένο κόμβο
void AddAfter(DoublyLinkedList* list, Node* node, int i) {
    if (list == NULL || node == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = i;
    newNode->next = node->next;
    newNode->prev = node;
    
    if (node->next != NULL) node->next->prev = newNode;
    else list->tail = newNode;
    
    node->next = newNode;
    list->size++;
}

// Εισαγωγή στην αρχή της λίστας
void AddFirst(DoublyLinkedList* list, int i) {
    if (list == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = i;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head != NULL) list->head->prev = newNode;
    else list->tail = newNode;

    list->head = newNode;
    list->size++;
}

// Εισαγωγή στο τέλος της λίστας
void AddLast(DoublyLinkedList* list, int i) {
    if (list == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = i;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL) list->tail->next = newNode;
    else list->head = newNode;

    list->tail = newNode;
    list->size++;
}

// Αφαίρεση όλων των κόμβων με συγκεκριμένη τιμή
void Remove(DoublyLinkedList* list, int i) {
    if (list == NULL) return;
    Node* current = list->head;
    
    while (current != NULL) {
        if (current->data == i) {
            Node* toDelete = current;
            if (current->prev != NULL) current->prev->next = current->next;
            else list->head = current->next;

            if (current->next != NULL) current->next->prev = current->prev;
            else list->tail = current->prev;

            current = current->next;
            free(toDelete);
            list->size--;
        } else {
            current = current->next;
        }
    }
}

// Εκτύπωση της λίστας
void Print(DoublyLinkedList* list) {
    if (list == NULL) return;
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
