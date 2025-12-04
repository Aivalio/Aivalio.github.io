#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <string>
using namespace std;

// =====================================================================
//                       BASE CLASS: Sequence
//  Represents a generic biological sequence. It will be inherited by
//  DNASequence, RNASequence, and ProteinSequence.
// =====================================================================
class Sequence {
protected:
    // The actual sequence data (string of letters).
    // Protected: accessible in derived classes, but not by external code.
    string data;

    // Descriptive type label (e.g., "DNA", "RNA", "Protein").
    string type;

    // Static member shared among ALL sequence objects (base + derived).
    // It tracks how many sequence objects are alive at any moment.
    static int count;

public:
    // Constructors and destructor (implemented in sequence.cpp)
    Sequence();
    Sequence(const string& t, const string& d);
    virtual ~Sequence();  // Must be virtual to correctly destroy derived objects.

    // Basic functionality for all sequences:
    size_t length() const;  // Returns sequence length.
    static int getCount();  // Returns how many sequences currently exist.

    // Basic description (WILL BE HIDDEN by derived describe() methods,
    // because this method is NOT virtual on purpose).
    void describe() const;
};

#endif // SEQUENCE_H
