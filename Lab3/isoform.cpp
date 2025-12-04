#include "isoform.h"

// Constructor builds name/id and constructs RNA member automatically.
Isoform::Isoform(const string& i, const string& n, const string& data)
    : id(i), name(n), rna(data)  // Member initialization list
{
    cout << "[Isoform] Created: " << name << endl;
}

Isoform::~Isoform() {
    cout << "[Isoform] Destroyed: " << name << endl;
}

// Shows isoform info and delegates RNA printing to RNASequence.describe().
void Isoform::describe() const {
    cout << "  Isoform " << name << " (" << id << "):" << endl;
    rna.describe();
}
