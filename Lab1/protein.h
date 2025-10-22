#ifndef _PROTEIN_H_
#define _PROTEIN_H_

class Protein {
private:
    char id[20];
    char name[50];
    char sequence[1000];

public:
    void setID(const char* id);
    void setName(const char* name);
    void setSequence(const char* sequence);

    const char* getID() const;
    const char* getName() const;
    const char* getSequence() const;

    void describe() const;
    int length() const;
};

#endif // _PROTEIN_H_
