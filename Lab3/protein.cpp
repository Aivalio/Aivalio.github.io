#include "protein.h"

// Constructor calls base with type="Protein"
ProteinSequence::ProteinSequence(const string& d) : Sequence("Protein", d) {
    cout << "[ProteinSequence] Constructed" << endl;
}

ProteinSequence::~ProteinSequence() {
    cout << "[ProteinSequence] Destroyed" << endl;
}

// Prints protein info and whether sequence is valid.
void ProteinSequence::describe() const {
    cout << "Protein sequence: " << data << " (length=" << length()
         << ", valid=" << (isValid() ? "true" : "false") << ")" << endl;
}

// Validates only the 20 protein single-letter amino acids.
bool ProteinSequence::isValid() const {
    string valid = "ACDEFGHIKLMNPQRSTVWY";
    for (char c : data)
        if (valid.find(c) == string::npos)
            return false;
    return true;
}
