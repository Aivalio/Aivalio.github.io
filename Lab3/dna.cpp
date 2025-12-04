#include "dna.h"

// Constructor forwarding to base Sequence constructor with type="DNA".
DNASequence::DNASequence(const string& d) : Sequence("DNA", d) {
    cout << "[DNASequence] Constructed" << endl;
}

// Destructor prints message.
DNASequence::~DNASequence() {
    cout << "[DNASequence] Destroyed" << endl;
}

// Description specific to DNA, hiding the base method.
void DNASequence::describe() const {
    cout << "DNA sequence: " << data << " (length=" << length()
         << ", valid=" << (isValid() ? "true" : "false") << ")" << endl;
}

// DNA validity check: allows only A, C, G, T.
bool DNASequence::isValid() const {
    for (char c : data)
        if (c!='A' && c!='C' && c!='G' && c!='T')
            return false;
    return true;
}
