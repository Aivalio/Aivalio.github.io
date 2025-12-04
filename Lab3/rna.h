#ifndef RNA_H
#define RNA_H

#include "sequence.h"

// ======================================================================
// DERIVED CLASS: RNASequence
// Represents RNA (bases: A, C, G, U).
// ======================================================================
class RNASequence : public Sequence {
public:
    RNASequence(const string& d);
    ~RNASequence();

    void describe() const;  // Hides base describe(), not override.
    bool isValid() const;   // Validates U instead of T.
};

#endif // RNA_H
