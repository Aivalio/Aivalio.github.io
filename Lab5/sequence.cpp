#include "sequence.h"

int Sequence::count = 0;

Sequence::Sequence(const string& t, const string& d) : data(d), type(t) {
    count++;
    cout << "[Sequence Base] Constructed (" << type << "). Alive=" << count << endl;
}

Sequence::~Sequence() {
    count--;
    cout << "[Sequence Base] Destroyed (" << type << "). Alive=" << count << endl;
}

size_t Sequence::length() const {
    return data.length();
}

int Sequence::getCount() {
    return count;
}
