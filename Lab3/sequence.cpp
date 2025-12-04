#include "sequence.h"

// =====================================================================
// Definition of the static member. It MUST exist exactly once in a .cpp file.
// =====================================================================
int Sequence::count = 0;

// Default constructor: creates an empty sequence.
Sequence::Sequence() : data(""), type("N/A") {
    count++;
    cout << "[Sequence Base] Default constructed. Alive=" << count << endl;
}

// Parameterized constructor: called by derived classes to set type & data.
// NOTE: Order in initializer list matches the declaration order in sequence.h
Sequence::Sequence(const string& t, const string& d) : data(d), type(t) {
    count++;
    cout << "[Sequence Base] Constructed (" << type << "). Alive=" << count << endl;
}

// Virtual destructor: ensures derived destructors are called correctly.
Sequence::~Sequence() {
    count--;
    cout << "[Sequence Base] Destroyed (" << type << "). Alive=" << count << endl;
}

// Returns number of characters in the sequence.
size_t Sequence::length() const { return data.length(); }

// Returns current number of living Sequence objects.
int Sequence::getCount() { return count; }

// Description of sequence (this will be HIDDEN in derived classes, not overridden).
void Sequence::describe() const {
    cout << "Sequence [" << type << "], data=" << data
         << ", length=" << data.length() << endl;
}
