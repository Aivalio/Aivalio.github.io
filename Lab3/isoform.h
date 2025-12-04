#ifndef ISOFORM_H
#define ISOFORM_H

#include <string>
#include <iostream>
#include "rna.h"
using namespace std;

// ======================================================================
// CLASS: Isoform
// Composition: an Isoform "has-a" RNASequence (not inheritance).
// In biology, each isoform has its own unique RNA sequence.
// ======================================================================
class Isoform {
private:
    string id;
    string name;
    RNASequence rna;  // Composition: this object owns a RNASequence.

public:
    Isoform(const string& i, const string& n, const string& data);
    ~Isoform();

    void describe() const;  // Prints isoform data + its RNASequence.
};

#endif // ISOFORM_H
