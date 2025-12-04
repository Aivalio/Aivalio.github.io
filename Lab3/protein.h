#ifndef PROTEIN_H
#define PROTEIN_H

#include "sequence.h"

// ======================================================================
// DERIVED CLASS: ProteinSequence
// Represents an amino-acid chain (20 legal letters).
// ======================================================================
class ProteinSequence : public Sequence {
public:
    ProteinSequence(const string& d);
    ~ProteinSequence();

    void describe() const;
    bool isValid() const;  // Validates 20 legal amino acid codes.
};

#endif // PROTEIN_H
