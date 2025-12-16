#ifndef _DNA_H_
#define _DNA_H_

#include "sequence.h"

class DNASequence : public Sequence {
public:
    DNASequence(const string& d);
    ~DNASequence();

    void describe() const override;
    bool isValid() const override;
};

#endif
