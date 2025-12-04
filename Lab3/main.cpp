#include "gene.h"
#include "dna.h"
#include "rna.h"
#include "protein.h"
#include <iostream>
using namespace std;

int main() {
    cout << "\n===== TEST DERIVED SEQUENCES =====" << endl;

    // Create independent sequences to test inheritance and validation.
    DNASequence d("ACGTAC");
    RNASequence r("ACGUAC");
    ProteinSequence p("MKWVTFISLL");

    // Each calls its own describe() (method hiding behavior).
    d.describe();
    r.describe();
    p.describe();

    // Shows how many Sequence objects are alive (static counter).
    cout << "\nAlive sequences: " << Sequence::getCount() << endl;

    cout << "\n===== TEST GENE WITH ISOFORMS =====" << endl;

    Gene g("G001", "BRCA1");  // Create a Gene

    Isoform iso1("ISO001", "BRCA1-201", "AUGGCUACUGGU");
    g.addIsoform(iso1);  // Added via copy

    g.emplaceIsoform("ISO002", "BRCA1-202", "AUGGCAUGGA"); // Constructed directly

    g.describe();  // Print full gene structure

    cout << "\nAlive sequences total: " << Sequence::getCount() << endl;
    cout << "\n===== END MAIN =====" << endl;
    return 0;
}
