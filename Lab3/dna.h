#ifndef DNA_H
#define DNA_H

#include "sequence.h"

// ======================================================================
// DERIVED CLASS: DNASequence
// Inherits from Sequence representing DNA (bases: A, C, G, T).
// ======================================================================
class DNASequence : public Sequence {
public:
    // Constructor forwards "DNA" and sequence data to base constructor.
    DNASequence(const string& d);

    // Destructor prints message (not required for behavior, just visualization).
    ~DNASequence();

    // Hides Sequence::describe() (NOT overriding, because base is not virtual).
    void describe() const;

    // Validates that sequence contains ONLY legal DNA bases: A, C, G, T.
    bool isValid() const;
};

#endif // DNA_H
