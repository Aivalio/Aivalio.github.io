#include <iostream>
#include <cstring>
#include "protein.h"
using namespace std;

void Protein::setID(const char* id) {
    strcpy(this->id, id);
}

void Protein::setName(const char* name) {
    strcpy(this->name, name);
}

void Protein::setSequence(const char* sequence) {
    strcpy(this->sequence, sequence);
}

const char* Protein::getID() const {
    return id;
}

const char* Protein::getName() const {
    return name;
}

const char* Protein::getSequence() const {
    return sequence;
}

void Protein::describe() const {
    cout << "Protein " << name << " (" << id << "): " << sequence << endl;
}

int Protein::length() const {
    return strlen(sequence);
}
