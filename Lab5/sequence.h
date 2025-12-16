#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include <iostream>
#include <string>
using namespace std;

class Sequence {
protected:
    string data;
    string type;
    static int count;

public:
    Sequence(const string& t, const string& d);
    virtual ~Sequence();   // ΑΠΑΡΑΙΤΗΤΟ για polymorphism

    size_t length() const;
    static int getCount();

    // PURE VIRTUAL METHODS
    virtual void describe() const = 0;
    virtual bool isValid() const = 0;
};

#endif
