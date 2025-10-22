#include <iostream>
#include <cstring>
#include "gene.h"
using namespace std;

void Gene::setID(const char* id) {
    strcpy(this->id, id);
}

void Gene::setName(const char* name) {
    strcpy(this->name, name);
}

void Gene::setChrom(const char* chrom) {
    strcpy(this->chrom, chrom);
}

void Gene::setStart(int start) {
    this->start = start;
}

void Gene::setEnd(int end) {
    this->end = end;
}

void Gene::setStrand(char strand) {
    this->strand = strand;
}

void Gene::describe() const {
    cout << "Gene " << name << " (" << chrom << ":" 
         << start << "-" << end << ", " << strand << " strand)" << endl;
}
