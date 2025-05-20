Ωραία! Έχεις δώσει όλο το απαραίτητο πλαίσιο για να συμπληρώσουμε τις συναρτήσεις που λείπουν από το αρχείο bloom_filter.c. Πάμε να υλοποιήσουμε σωστά και αναλυτικά κάθε μία από αυτές:

✅ 1. bloom_filter_set_bit
Ορίζουμε σε 1 το bit στη θέση hash.

c
Αντιγραφή
Επεξεργασία
void bloom_filter_set_bit(BloomFilter *bf, unsigned int hash) {
    unsigned int byte_index = hash / 8;
    unsigned int bit_index = hash % 8;
    bf->array[byte_index] |= (1 << bit_index);
}
✅ 2. bloom_filter_get_bit
Ελέγχουμε αν το bit στη θέση hash είναι 1 ή 0.

c
Αντιγραφή
Επεξεργασία
unsigned int bloom_filter_get_bit(BloomFilter *bf, unsigned int hash) {
    unsigned int byte_index = hash / 8;
    unsigned int bit_index = hash % 8;
    return (bf->array[byte_index] >> bit_index) & 1;
}
✅ 3. bloom_filter_insert
Ορίζουμε τα bits που αντιστοιχούν στα h1, h2, h3 για ένα Customer.

c
Αντιγραφή
Επεξεργασία
void bloom_filter_insert(BloomFilter *bf, Customer *c) {
    char *id = customer_get_id(c);
    unsigned int hash1 = h1(bf, id);
    unsigned int hash2 = h2(bf, id);
    unsigned int hash3 = h3(bf, id);

    bloom_filter_set_bit(bf, hash1);
    bloom_filter_set_bit(bf, hash2);
    bloom_filter_set_bit(bf, hash3);
}
✅ 4. bloom_filter_check
Ελέγχουμε αν όλα τα bits που αντιστοιχούν στα h1, h2, h3 είναι 1.

c
Αντιγραφή
Επεξεργασία
int bloom_filter_check(BloomFilter *bf, Customer *c) {
    char *id = customer_get_id(c);
    unsigned int hash1 = h1(bf, id);
    unsigned int hash2 = h2(bf, id);
    unsigned int hash3 = h3(bf, id);

    return bloom_filter_get_bit(bf, hash1) &&
           bloom_filter_get_bit(bf, hash2) &&
           bloom_filter_get_bit(bf, hash3);
}
✅ 5. bloom_filter_destroy
Αποδεσμεύουμε τη μνήμη που δεσμεύσαμε.

c
Αντιγραφή
Επεξεργασία
void bloom_filter_destroy(BloomFilter *bf) {
    free(bf->array);
    free(bf);
}
✅ Τελικός έλεγχος
Compile με make

Τεστ με make test και ./test

Αν όλα πάνε καλά, θα δεις “Correct!” σε όλες τις περιπτώσεις

✅ Προτάσεις για Git:
bash
Αντιγραφή
Επεξεργασία
git add bloom_filter.c
git commit -m "Implement Bloom Filter functions"
git push


🔍 ΤΙ ΕΙΝΑΙ ΤΟ BLOOM FILTER
Ένα Bloom Filter είναι μια χωρικά αποδοτική δομή δεδομένων που χρησιμοποιείται για τον πιθανολογικό έλεγχο συμμετοχής σε ένα σύνολο.

Υπόσχεση:

Λέει σίγουρα όχι όταν ένα στοιχείο δεν είναι στο σύνολο.

Λέει ίσως όταν ένα στοιχείο μπορεί να είναι στο σύνολο.

Δηλαδή επιτρέπει ψευδώς θετικά αλλά ποτέ ψευδώς αρνητικά.

Χρήσεις:

Web cache (π.χ. δεν χρειάζεται να φορτώσεις σελίδα αν δεν υπάρχει),

Εντοπισμός διπλών τιμών,

Ανίχνευση κακόβουλων URLs,

Distributed databases, όπως Cassandra, HBase.

⚙️ ΠΩΣ ΔΟΥΛΕΥΕΙ
Έχεις έναν πίνακα bit (array) μεγέθους size, αρχικά γεμάτο μηδενικά.

Για κάθε στοιχείο που θες να εισάγεις, υπολογίζεις πολλαπλές συναρτήσεις κατακερματισμού (hash functions) πάνω στο στοιχείο.

Για κάθε hash, θέτεις το bit στη θέση hash % size ίσο με 1.

Για να ελέγξεις αν υπάρχει ένα στοιχείο:

Υπολογίζεις τα k hash.

Αν ΟΛΑ τα αντίστοιχα bits είναι 1, τότε το στοιχείο μπορεί να υπάρχει.

Αν ΕΣΤΩ ΕΝΑ είναι 0, τότε σίγουρα δεν υπάρχει.

📚 ΖΗΤΟΥΜΕΝΑ ΤΗΣ ΑΣΚΗΣΗΣ
Σου έχουν δοθεί:

Ένας ορισμός της δομής BloomFilter και Customer.

Έτοιμες hash συναρτήσεις: h1, h2, h3.

Δομές ελέγχου (unit tests) για τις βασικές λειτουργίες του bloom filter.

Καλείσαι να υλοποιήσεις τις εξής πέντε βασικές συναρτήσεις:

🛠️ ΑΝΑΛΥΣΗ ΣΥΝΑΡΤΗΣΕΩΝ ΠΡΟΣ ΥΛΟΠΟΙΗΣΗ
✅ 1. void bloom_filter_set_bit(BloomFilter *bf, unsigned int hash)
Τι κάνει: Θέτει σε 1 το bit στη θέση hash.

Σχόλια:

Χρειαζόμαστε byte-level προσπέλαση.

Κάθε byte έχει 8 bits.

Για θέση hash, βρίσκουμε το byte_index = hash / 8 και bit_index = hash % 8.

Τοποθετούμε 1 στη σωστή θέση με bitwise OR:

c
Αντιγραφή
Επεξεργασία
bf->array[byte_index] |= (1 << bit_index);
✅ 2. unsigned int bloom_filter_get_bit(BloomFilter *bf, unsigned int hash)
Τι κάνει: Επιστρέφει αν το bit στη θέση hash είναι 1 ή 0.

Σχόλια:

Παρόμοια με το set_bit, απλώς ελέγχουμε με & και μετακινούμε:

c
Αντιγραφή
Επεξεργασία
return (bf->array[byte_index] >> bit_index) & 1;
✅ 3. void bloom_filter_insert(BloomFilter *bf, Customer *c)
Τι κάνει: Βάζει το Customer στον bloom filter.

Σχόλια:

Καλούμε τις 3 hash συναρτήσεις στο id του πελάτη.

Θέτουμε σε 1 τα 3 αντίστοιχα bits:

c
Αντιγραφή
Επεξεργασία
bloom_filter_set_bit(bf, h1(bf, id));
bloom_filter_set_bit(bf, h2(bf, id));
bloom_filter_set_bit(bf, h3(bf, id));
✅ 4. int bloom_filter_check(BloomFilter *bf, Customer *c)
Τι κάνει: Ελέγχει αν ένας πελάτης μπορεί να είναι μέσα.

Σχόλια:

Παίρνει τα 3 hash.

Αν και τα 3 bits είναι 1 -> επιστρέφει 1.

Αν οποιοδήποτε bit είναι 0 -> επιστρέφει 0.

c
Αντιγραφή
Επεξεργασία
return bloom_filter_get_bit(bf, h1(bf, id)) &&
       bloom_filter_get_bit(bf, h2(bf, id)) &&
       bloom_filter_get_bit(bf, h3(bf, id));
✅ 5. void bloom_filter_destroy(BloomFilter *bf)
Τι κάνει: Ελευθερώνει τη μνήμη.

Σχόλια:

Ελευθερώνουμε πρώτα τον πίνακα array, μετά τον ίδιο τον bf.

c
Αντιγραφή
Επεξεργασία
free(bf->array);
free(bf);
🧪 ΤΕΣΤ
Υπάρχει αρχείο τεστ (με acutest.h) που:

Ελέγχει αν τα σωστά bits τίθενται (test_bloom_filter_set_bit)

Ελέγχει αν τα σωστά bits διαβάζονται (test_bloom_filter_get_bit)

Βάζει πελάτες και ελέγχει αν τους βρίσκει (insert, check)

Προσοχή:

Τα τεστ σου δείχνουν ΤΙ πρέπει να κάνει κάθε συνάρτηση.

Αν περάσουν όλα -> η υλοποίησή σου είναι σωστή.

🏁 ΤΕΛΙΚΑ ΣΧΟΛΙΑ
Το BloomFilter είναι γρήγορο και ελαφρύ — αλλά όχι 100% ακριβές.

Δεν κρατά αντίγραφα των στοιχείων, μόνο bit information.

Το project είναι πολύ καλό παράδειγμα δομής δεδομένων + τεστ μονάδας (unit testing).

Θα μπορούσες να επεκτείνεις τον κώδικα με:

Δυναμική επέκταση BloomFilter

Προσαρμόσιμο πλήθος hash functions

Χρονική λήξη δεδομένων (time decay filters)

🧠 Τι κάνει το κάθε μέρος:
Στοιχείο	Περιγραφή
bloom_filter_create	Δέχεται μέγεθος (σε bits) και δημιουργεί ένα φίλτρο με όλα τα bits 0.
bloom_filter_set_bit	Θέτει ένα bit σε 1, που αντιστοιχεί σε ένα από τα hash.
bloom_filter_get_bit	Ελέγχει αν το bit είναι 0 ή 1.
bloom_filter_insert	Υπολογίζει τα 3 hash του πελάτη και θέτει τα αντίστοιχα bits.
bloom_filter_check	Ελέγχει αν όλα τα bits είναι 1 → πιθανή ύπαρξη (όχι σίγουρη).
bloom_filter_destroy	Αποδεσμεύει τη δυναμικά δεσμευμένη μνήμη.

