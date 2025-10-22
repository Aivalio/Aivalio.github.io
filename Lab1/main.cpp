#include <iostream>
#include "gene.h"
#include "protein.h"
using namespace std;

int main(void) {
    
    Protein p1, p2;

    p1.setID("P001");
    p1.setName("PTEN");
    p1.setSequence("MTAIIKEIVSRNKRRYQEDGFDLDLTYIYPNIIAMGFPA");

    p2.setID("P002");
    p2.setName("BRCA1_Protein");
    p2.setSequence("MSSSQDNRNLPQKAK");

    cout << "=== Πρωτεΐνες ===" << endl;
    p1.describe();
    cout << "Μήκος αλληλουχίας: " << p1.length() << endl;
    p2.describe();
    cout << "Μήκος αλληλουχίας: " << p2.length() << endl;
    cout << endl;

    // Γονίδια
    Gene g1, g2;

    g1.setID("G001");
    g1.setName("BRCA1");
    g1.setChrom("chr17");
    g1.setStart(43044295);
    g1.setEnd(43170245);
    g1.setStrand('+');

    g2.setID("G002");
    g2.setName("TP53");
    g2.setChrom("chr17");
    g2.setStart(7668402);
    g2.setEnd(7687550);
    g2.setStrand('-');

    cout << "=== Γονίδια ===" << endl;
    g1.describe();
    g2.describe();

    return 0;
}
