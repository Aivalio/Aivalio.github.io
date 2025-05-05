size_t hashtable_hash(Hashtable* h, char* id) {
    size_t hash = 0;
    for (size_t i = 0; i < strlen(id); i++) {
        hash += (unsigned char)id[i];  // χρήση unsigned για ασφάλεια
    }
    return hash % h->size;
}

Hashtable* hashtable_insert(Hashtable* h, Customer* c) {
    if (!h || !c || !c->id) return h;

    // Έλεγχος για επανεισαγωγή
    if (hashtable_get(h, c->id) != NULL) return h;

    // Έλεγχος load factor
    if (hashtable_get_load_factor(h) > MAX_LOAD_FACTOR) {
        h = hashtable_resize(h);
    }

    size_t index = hashtable_hash(h, c->id);
    h->table[index] = list_insert(h->table[index], c);
    return h;
}

Customer* hashtable_get(Hashtable* h, char* id) {
    if (!h || !id) return NULL;

    size_t index = hashtable_hash(h, id);
    return list_search(h->table[index], id);
}

STATUS hashtable_remove(Hashtable* h, char* id) {
    if (!h || !id) return FAILURE;

    size_t index = hashtable_hash(h, id);
    int result = list_remove(&(h->table[index]), id);
    return result == 1 ? SUCCESS : FAILURE;
}

Hashtable* hashtable_resize(Hashtable* h) {
    size_t new_size = next_prime(h->size * 2);
    Hashtable* new_h = hashtable_create(new_size);

    for (size_t i = 0; i < h->size; i++) {
        List* node = h->table[i];
        while (node) {
            new_h = hashtable_insert(new_h, node->customer);
            node = node->next;
        }
    }

    hashtable_destroy(h);
    return new_h;
}
