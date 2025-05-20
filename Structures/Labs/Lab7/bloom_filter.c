void bloom_filter_set_bit(BloomFilter *bf, unsigned int hash) {
    unsigned int byte_index = hash / 8;
    unsigned int bit_index = hash % 8;
    bf->array[byte_index] |= (1 << bit_index);
}

unsigned int bloom_filter_get_bit(BloomFilter *bf, unsigned int hash) {
    unsigned int byte_index = hash / 8;
    unsigned int bit_index = hash % 8;
    return (bf->array[byte_index] >> bit_index) & 1;
}

void bloom_filter_insert(BloomFilter *bf, Customer *c) {
    char *id = customer_get_id(c);
    unsigned int hash1 = h1(bf, id);
    unsigned int hash2 = h2(bf, id);
    unsigned int hash3 = h3(bf, id);

    bloom_filter_set_bit(bf, hash1);
    bloom_filter_set_bit(bf, hash2);
    bloom_filter_set_bit(bf, hash3);
}

int bloom_filter_check(BloomFilter *bf, Customer *c) {
    char *id = customer_get_id(c);
    unsigned int hash1 = h1(bf, id);
    unsigned int hash2 = h2(bf, id);
    unsigned int hash3 = h3(bf, id);

    return bloom_filter_get_bit(bf, hash1) &&
           bloom_filter_get_bit(bf, hash2) &&
           bloom_filter_get_bit(bf, hash3);
}

void bloom_filter_destroy(BloomFilter *bf) {
    free(bf->array);
    free(bf);
}

