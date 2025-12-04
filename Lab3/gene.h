#ifndef GENE_H
#define GENE_H

#include <vector>
#include "isoform.h"

// ======================================================================
// CLASS: Gene
// Composition: A Gene contains multiple Isoforms (owned in a vector).
// ======================================================================
class Gene {
private:
    string id;
    string name;
    vector<Isoform> isoforms;  // "Has-many" relationship.

public:
    Gene(const string& i, const string& n);
    ~Gene();

    void addIsoform(const Isoform& iso);                        // Copy version
    void emplaceIsoform(const string& i, const string& n, const string& seq); // In-place construction

    void describe() const;  // Print all isoforms belonging to this gene.
};

#endif // GENE_H
