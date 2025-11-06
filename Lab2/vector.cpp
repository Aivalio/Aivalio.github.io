#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// Καθολικοί μετρητές ενεργών αντικειμένων
// ------------------------------------------------------------
int protein_count = 0;
int gene_count = 0;

// ------------------------------------------------------------
// Κλάση Protein
// ------------------------------------------------------------
class Protein {
private:
    string id;
    string name;
    string sequence;

public:
    // --- Constructors ---
    Protein()
        : id("N/A"), name("Unnamed"), sequence("")
    {
        protein_count++;
        cout << "[Protein] Δημιουργήθηκε αντικείμενο (default). Σύνολο: "
             << protein_count << endl;
    }

    Protein(const string& in_id, const string& in_name, const string& in_seq)
        : id(in_id), name(in_name), sequence(in_seq)
    {
        protein_count++;
        cout << "[Protein] Δημιουργήθηκε αντικείμενο με δεδομένα: "
             << name << " (" << id << "). Σύνολο: " << protein_count << endl;
    }

    // --- Destructor ---
    ~Protein() {
        protein_count--;
        cout << "[Protein] Καταστράφηκε αντικείμενο: "
             << name << " (" << id << "). Εναπομείναντα: "
             << protein_count << endl;
    }

    // --- Setters / Getters ---
    void setID(const string& in_id) { id = in_id; }
    void setName(const string& in_name) { name = in_name; }
    void setSequence(const string& in_seq) { sequence = in_seq; }

    string getID() const { return id; }
    string getName() const { return name; }
    string getSequence() const { return sequence; }

    // --- Άλλες μέθοδοι ---
    void describe() const {
        cout << "Protein " << name << " (" << id << "): " << sequence << endl;
    }

    int length() const {
        return sequence.length();
    }
};

// ------------------------------------------------------------
// Κλάση Gene
// ------------------------------------------------------------
class Gene {
private:
    const string organism;
    string id;
    string name;
    string chrom;
    int start;
    int end;
    char strand;

public:
    // --- Constructors ---
    Gene()
        : organism("Homo sapiens"), id("N/A"), name("Unnamed"),
          chrom("chr?"), start(0), end(0), strand('+')
    {
        gene_count++;
        cout << "[Gene] Δημιουργήθηκε αντικείμενο (default). Σύνολο: "
             << gene_count << endl;
    }

    Gene(const string& in_id, const string& in_name, const string& in_chrom,
         int in_start, int in_end, char in_strand,
         const string& in_organism = "Homo sapiens")
        : organism(in_organism), id(in_id), name(in_name),
          chrom(in_chrom), start(in_start), end(in_end), strand(in_strand)
    {
        gene_count++;
        cout << "[Gene] Δημιουργήθηκε αντικείμενο: " << name
             << " (" << id << "). Σύνολο: " << gene_count << endl;
    }

    // --- Destructor ---
    ~Gene() {
        gene_count--;
        cout << "[Gene] Καταστράφηκε αντικείμενο: " << name
             << " (" << id << "). Εναπομείναντα: " << gene_count << endl;
    }

    // --- Setters / Getters ---
    void setID(const string& in_id) { id = in_id; }
    void setName(const string& in_name) { name = in_name; }
    void setChrom(const string& in_chrom) { chrom = in_chrom; }
    void setStart(int in_start) { start = in_start; }
    void setEnd(int in_end) { end = in_end; }
    void setStrand(char in_strand) { strand = in_strand; }

    string getID() const { return id; }
    string getName() const { return name; }
    string getChrom() const { return chrom; }
    int getStart() const { return start; }
    int getEnd() const { return end; }
    char getStrand() const { return strand; }
    string getOrganism() const { return organism; }

    // --- Άλλες μέθοδοι ---
    void describe() const {
        cout << "Gene " << name << " (" << id << "): "
             << "Organism: " << organism
             << ", Chromosome: " << chrom
             << ", Start: " << start
             << ", End: " << end
             << ", Strand: " << strand << endl;
    }
};

// ------------------------------------------------------------
// Συνάρτηση για δημιουργία προσωρινού Protein
// ------------------------------------------------------------
Protein makeProtein() {
    Protein temp("P999", "TEMP_PROT", "MSSSSSSSS");
    cout << "Η συνάρτηση makeProtein() τελειώνει.\n";
    return temp;
}

// ------------------------------------------------------------
// main
// ------------------------------------------------------------
int main() {
    cout << "=== Δημιουργία λιστών με std::vector ===" << endl;

    // --- Δημιουργία vector πρωτεϊνών ---
    vector<Protein> proteins;
    proteins.push_back(Protein("P001", "PTEN", "MTAIIKEIVSRNKRRYQEDGFDLDLTYIYPNIIAMGFPA"));
    proteins.push_back(Protein("P002", "BRCA1_Protein", "MSSSQDNRNLPQKAK"));
    proteins.emplace_back("P003", "MYC", "MTENEVHVEEQK"); // emplace_back: κατασκευή επί τόπου

    cout << "\n--- Λίστα πρωτεϊνών ---" << endl;
    for (const auto& p : proteins) {
        p.describe();
        cout << "Length: " << p.length() << endl;
    }

    // --- Διαγραφή τελευταίας πρωτεΐνης ---
    cout << "\nΔιαγραφή τελευταίας πρωτεΐνης..." << endl;
    proteins.pop_back();

    // --- Δημιουργία vector γονιδίων ---
    vector<Gene> genes;
    genes.emplace_back("G001", "BRCA1", "chr17", 43044295, 43170245, '+');
    genes.emplace_back("G002", "TP53", "chr17", 7668402, 7687550, '-');

    cout << "\n--- Λίστα γονιδίων ---" << endl;
    for (const Gene& g : genes) {
        g.describe();
    }

    cout << "\nΠλήθος ενεργών πρωτεϊνών: " << protein_count << endl;
    cout << "Πλήθος ενεργών γονιδίων: " << gene_count << endl;

    cout << "\n=== Δυναμικό αντικείμενο ===" << endl;
    Protein* dynamicProt = new Protein("P010", "Dynamic_PROT", "MVVVVLLLQQ");
    dynamicProt->describe();
    delete dynamicProt;  // destructor καλείται τώρα

    cout << "\n=== Συνάρτηση makeProtein() ===" << endl;
    Protein temp = makeProtein();
    temp.describe();

    cout << "\n=== Τέλος main() ===" << endl;
    return 0;
}
