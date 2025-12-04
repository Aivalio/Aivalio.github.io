#include "gene.h"
#include <iostream>
using namespace std;

// Constructs a Gene object (just stores name and prints a message).
Gene::Gene(const string& i, const string& n) : id(i), name(n) {
    cout << "[Gene] Created: " << name << endl;
}

Gene::~Gene() {
    cout << "[Gene] Destroyed: " << name << endl;
}

// Adds an Isoform by copying it into the vector.
void Gene::addIsoform(const Isoform& iso) {
    cout << "[Gene] Adding isoform (copy)" << endl;
    isoforms.push_back(iso);
}

// Constructs an Isoform directly inside the vector (no temporary object).
void Gene::emplaceIsoform(const string& i, const string& n, const string& seq) {
    cout << "[Gene] Adding isoform (emplace)" << endl;
    isoforms.emplace_back(i, n, seq);
}

// Prints all isoforms owned by this Gene.
void Gene::describe() const {
    cout << "\n=== Gene " << name << " (" << id << ") ===" << endl;
    cout << " Isoform count: " << isoforms.size() << endl;

    for (size_t k=0; k<isoforms.size(); k++)
        isoforms[k].describe();
}
