class ProteinSequence : public Sequence {
public:
    ProteinSequence(const string& d);
    ~ProteinSequence();

    void describe() const override;
    bool isValid() const override;
};

#include "dna.h"
#include "rna.h"
#include "protein.h"
#include "gene.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    cout << "\n===== POLYMORPHISM TEST =====\n";

    vector<Sequence*> sequences;

    sequences.push_back(new DNASequence("ACGTACGT"));
    sequences.push_back(new RNASequence("AUGGCUAG"));
    sequences.push_back(new ProteinSequence("MTAPQL"));

    for (Sequence* s : sequences) {
        s->describe();              // POLYMORPHIC CALL
        cout << "Length: " << s->length() << endl;
        cout << "Valid? " << s->isValid() << endl << endl;
    }

    cout << "Alive sequences: " << Sequence::getCount() << endl;

    // CLEANUP (virtual destructor in action)
    for (Sequence* s : sequences)
        delete s;

    sequences.clear();

    cout << "\n===== GENE WITH ISOFORMS =====\n";

    Gene g("G001", "BRCA1");
    g.emplaceIsoform("ISO1", "BRCA1-201", "AUGGCUACUGGU");
    g.emplaceIsoform("ISO2", "BRCA1-202", "AUGGCAUGGA");

    g.describe();

    cout << "\n===== END =====\n";
    return 0;
}

