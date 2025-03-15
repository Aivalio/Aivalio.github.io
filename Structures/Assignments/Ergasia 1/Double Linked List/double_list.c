/*This is the client program for my module*/

#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
    // Δημιουργία λίστας
    DoublyLinkedList* list = Create();

    // Έλεγχος αν η λίστα είναι κενή
    printf("Η λίστα είναι %s\n", IsEmpty(list) ? "κενή" : "όχι κενή");

    // Προσθήκη στοιχείων στην αρχή και στο τέλος
    AddFirst(list, 10);
    AddLast(list, 20);
    AddFirst(list, 5);
    AddLast(list, 25);
    
    // Εκτύπωση λίστας
    printf("Λίστα μετά από εισαγωγές: ");
    Print(list);

    // Εμφάνιση πρώτου και τελευταίου στοιχείου
    printf("Πρώτο στοιχείο: %d\n", GetFirst(list));
    printf("Τελευταίο στοιχείο: %d\n", GetLast(list));

    // Εύρεση κόμβου
    Node* node = GetNode(list, 20);
    if (node != NULL) {
        printf("Βρέθηκε ο κόμβος με τιμή 20\n");
    }

    // Προσθήκη πριν και μετά από τον κόμβο με τιμή 20
    if (node != NULL) {
        AddBefore(list, node, 15);
        AddAfter(list, node, 22);
    }

    // Εκτύπωση λίστας μετά τις εισαγωγές
    printf("Λίστα μετά από προσθήκες πριν και μετά το 20: ");
    Print(list);

    // Αφαίρεση στοιχείων
    Remove(list, 10);
    printf("Λίστα μετά την αφαίρεση του 10: ");
    Print(list);

    Remove(list, 5);
    printf("Λίστα μετά την αφαίρεση του 5: ");
    Print(list);

    return 0;
}

