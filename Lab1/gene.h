#ifndef _GENE_H_
#define _GENE_H_

class Gene {
private:
    char id[20];
    char name[50];
    char chrom[20];
    int start;
    int end;
    char strand; 

public:
    void setID(const char* id);
    void setName(const char* name);
    void setChrom(const char* chrom);
    void setStart(int start);
    void setEnd(int end);
    void setStrand(char strand);

    void describe() const;
};

#endif // _GENE_H_
