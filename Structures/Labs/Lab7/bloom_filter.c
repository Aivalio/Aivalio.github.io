#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "bloom_filter.h"
#include "./customer/customer.h"

/* -------- HASH FUNCTIONS --------*/

// DJB2 hash function
unsigned int h1(BloomFilter *bf, char *id) {
    unsigned int hash = 5381;
    unsigned int c;

    while ((c = *id++))
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c

    return hash % bf->size;
}

// SDBM hash function
unsigned int h2(BloomFilter *bf, char *id) {
    unsigned int hash = 0;
    unsigned int c;

    while ((c = *id++))
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash % bf->size;
}

// Απλή hash συνάρτηση
unsigned int h3(BloomFilter *bf, char *id) {
    unsigned int hash = 0;
    unsigned int c;

    while ((c = *id++))
        hash += c;

    return hash % bf->size;
}
/*---------------------------------*/


// Δημιουργεί έναν νέο Bloom Filter με δεδομένο μέγεθος
BloomFilter *bloom_filter_create(unsigned int size) {
    BloomFilter *bf = malloc(sizeof(BloomFilter));
    bf->array = malloc(size / 8 + 1);         // Χρειαζόμαστε size bits → size/8 bytes
    memset(bf->array, 0, size / 8 + 1);       // Αρχικοποιούμε τα bits σε 0
    bf->size = size;
    return bf;
}


// Θέτει ένα bit στη θέση hash σε 1
void bloom_filter_set_bit(BloomFilter *bf, unsigned int hash) {
    unsigned int byte_index = hash / 8;       // βρίσκουμε σε ποιο byte είναι
    unsigned int bit_index = hash % 8;        // και ποιο bit μέσα στο byte
    bf->array[byte_index] |= (1 << bit_index); // κάνουμε OR για να θέσουμε το bit
}


// Επιστρέφει το bit (0 ή 1) στη θέση hash
unsigned int bloom_filter_get_bit(BloomFilter *bf, unsigned int hash) {
    unsigned int byte_index = hash / 8;
    unsigned int bit_index = hash % 8;
    return (bf->array[byte_index] >> bit_index) & 1;
}


// Εισάγει έναν πελάτη στον Bloom Filter
void bloom_filter_insert(BloomFilter *bf, Customer *c) {
    unsigned int h1_val = h1(bf, c->id);
    unsigned int h2_val = h2(bf, c->id);
    unsigned int h3_val = h3(bf, c->id);

    bloom_filter_set_bit(bf, h1_val);
    bloom_filter_set_bit(bf, h2_val);
    bloom_filter_set_bit(bf, h3_val);
}


// Ελέγχει αν ο πελάτης *μπορεί* να είναι στον Bloom Filter (ή όχι)
int bloom_filter_check(BloomFilter *bf, Customer *c) {
    return bloom_filter_get_bit(bf, h1(bf, c->id)) &&
           bloom_filter_get_bit(bf, h2(bf, c->id)) &&
           bloom_filter_get_bit(bf, h3(bf, c->id));
}


// Καταστρέφει τον Bloom Filter και αποδεσμεύει τη μνήμη
void bloom_filter_destroy(BloomFilter *bf) {
    if (bf != NULL) {
        free(bf->array);  // Πίνακας bits
        free(bf);         // Η ίδια η δομή
    }
}
