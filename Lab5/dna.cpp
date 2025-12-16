#include "dna.h"

DNASequence::DNASequence(const string& d) : Sequence("DNA", d) {
    cout << "[DNASequence] Constructed" << endl;
}

DNASequence::~DNASequence() {
    cout << "[DNASequence] Destroyed" << endl;
}

void DNASequence::describe() const {
    cout << "DNA sequence: " << data
         << " (length=" << length()
         << ", valid=" << (isValid() ? "true" : "false") << ")" << endl;
}

bool DNASequence::isValid() const {
    for (char c : data)
        if (c!='A' && c!='C' && c!='G' && c!='T')
            return false;
    return true;
}
