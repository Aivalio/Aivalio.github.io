#include "rna.h"

// Constructor passes type="RNA" to the base class.
RNASequence::RNASequence(const string& d) : Sequence("RNA", d) {
    cout << "[RNASequence] Constructed" << endl;
}

// Destructor prints message.
RNASequence::~RNASequence() {
    cout << "[RNASequence] Destroyed" << endl;
}

// RNA description printing validity.
void RNASequence::describe() const {
    cout << "RNA sequence: " << data << " (length=" << length()
         << ", valid=" << (isValid() ? "true" : "false") << ")" << endl;
}

// RNA validity check: legal bases A, C, G, U (NO T allowed).
bool RNASequence::isValid() const {
    for (char c : data)
        if (c!='A' && c!='C' && c!='G' && c!='U')
            return false;
    return true;
}
