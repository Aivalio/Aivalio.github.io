#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ============================================================
// Global counters
// ============================================================
int protein_count = 0;
int gene_count = 0;

// ============================================================
// Class Protein
// ============================================================
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
        cout << "Protein created by default. Proteins: "
             << protein_count << endl;
    }

    Protein(const string& in_id, const string& in_name, const string& in_seq)
        : id(in_id), name(in_name), sequence(in_seq)
    {
        protein_count++;
        cout << "Protein created via args constructor "
             << name << " (" << id << "). Proteins: "
             << protein_count << endl;
    }

    // --- Copy Constructor ---
    Protein(const Protein& other)
        : id(other.id), name(other.name), sequence(other.sequence)
    {
        protein_count++;
        cout << "Protein copied: " << name << " (" << id << "). Proteins: "
             << protein_count << endl;
    }

    // --- Move Constructor ---
    Protein(Protein&& other) noexcept
        : id(move(other.id)), name(move(other.name)), sequence(move(other.sequence))
    {
        protein_count++;
        cout << "Protein moved: " << name << " (" << id << "). Proteins: "
             << protein_count << endl;
    }

    // --- Copy Assignment ---
    Protein& operator=(const Protein& other)
    {
        if (this != &other) {
            id = other.id;
            name = other.name;
            sequence = other.sequence;
        }
        return *this;
    }

    // --- Move Assignment ---
    Protein& operator=(Protein&& other) noexcept
    {
        if (this != &other) {
            id = move(other.id);
            name = move(other.name);
            sequence = move(other.sequence);
        }
        return *this;
    }

    // --- Destructor ---
    ~Protein() {
        protein_count--;
        cout << "Protein destroyed: "
             << name << " (" << id << "). Remaining: "
             << protein_count << endl;
    }

    // --- Setters / Getters ---
    void setID(const string& in_id) { id = in_id; }
    void setName(const string& in_name) { name = in_name; }
    void setSequence(const string& in_seq) { sequence = in_seq; }

    string getID() const { return id; }
    string getName() const { return name; }
    string getSequence() const { return sequence; }

    // --- Describe method ---
    void describe() const {
        cout << "Protein " << name << " (" << id << "): " << sequence << endl;
    }

    // --- Length method ---
    int length() const {
        return static_cast<int>(sequence.length());
    }
};

// ============================================================
// Class Gene
// ============================================================
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
        cout << "Gene created by default. Genes: "
             << gene_count << endl;
    }

    Gene(const string& in_id, const string& in_name, const string& in_chrom,
         int in_start, int in_end, char in_strand,
         const string& in_organism = "Homo sapiens")
        : organism(in_organism), id(in_id), name(in_name),
          chrom(in_chrom), start(in_start), end(in_end), strand(in_strand)
    {
        gene_count++;
        cout << "Gene created via args constructor: " << name
             << " (" << id << "). Genes: " << gene_count << endl;
    }

    // --- Copy Constructor ---
    Gene(const Gene& other)
        : organism(other.organism), id(other.id), name(other.name),
          chrom(other.chrom), start(other.start), end(other.end), strand(other.strand)
    {
        gene_count++;
        cout << "Gene copied: " << name << " (" << id << "). Genes: "
             << gene_count << endl;
    }

    // --- Move Constructor ---
    Gene(Gene&& other) noexcept
        : organism(other.organism), id(move(other.id)), name(move(other.name)),
          chrom(move(other.chrom)), start(other.start), end(other.end), strand(other.strand)
    {
        gene_count++;
        cout << "Gene moved: " << name << " (" << id << "). Genes: "
             << gene_count << endl;
    }

    // --- Copy Assignment ---
    Gene& operator=(const Gene& other)
    {
        if (this != &other) {
            id = other.id;
            name = other.name;
            chrom = other.chrom;
            start = other.start;
            end = other.end;
            strand = other.strand;
        }
        return *this;
    }

    // --- Move Assignment ---
    Gene& operator=(Gene&& other) noexcept
    {
        if (this != &other) {
            id = move(other.id);
            name = move(other.name);
            chrom = move(other.chrom);
            start = other.start;
            end = other.end;
            strand = other.strand;
        }
        return *this;
    }

    // --- Destructor ---
    ~Gene() {
        gene_count--;
        cout << "Gene destroyed: " << name
             << " (" << id << "). Remaining: " << gene_count << endl;
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

    // --- Describe method ---
    void describe() const {
        cout << "Gene " << name << " (" << id << "): "
             << "Organism: " << organism
             << ", Chromosome: " << chrom
             << ", Start: " << start
             << ", End: " << end
             << ", Strand: " << strand << endl;
    }
};

// ============================================================
// Function to create a temporary Protein
// ============================================================
Protein makeProtein(void) {
    Protein temp("P999", "TEMP_PROT", "MSSSSSSSS");
    return temp; // uses move constructor
}

// ============================================================
// main
// ============================================================
int main(void) {
    cout << "=== std::vector used to create a list of proteins ===" << endl;

    // Create a list of proteins via the std::vector
    vector<Protein> proteins;
    proteins.push_back(Protein("P001", "PTEN", "MTAIIKEIVSRNKRRYQEDGFDLDLTYIYPNIIAMGFPA"));
    proteins.push_back(Protein("P002", "BRCA1_Protein", "MSSSQDNRNLPQKAK"));
    proteins.push_back(Protein("P003", "MYC", "MTENEVHVEEQK"));

    cout << "Active proteins: " << protein_count << endl;

    // Print the list elements
    cout << "\n--- Proteins ---" << endl;
    for (const auto& p : proteins) {
        p.describe();
        cout << "Length: " << p.length() << endl;
    }

    // Create a list of genes via the std::vector
    vector<Gene> genes;
    genes.push_back(Gene("G001", "BRCA1", "chr17", 43044295, 43170245, '+'));
    genes.push_back(Gene("G002", "TP53", "chr17", 7668402, 7687550, '-'));

    cout << "Active genes: " << gene_count << endl;

    // Print the list elements
    cout << "\n--- List of genes ---" << endl;
    for (const auto& g : genes) {
        g.describe();
    }

    // Dynamically created protein
    cout << "\n=== Dynamically created protein ===" << endl;
    Protein* dynamicProt = new Protein("P010", "Dynamic_PROT", "MVVVVLLLQQ");
    dynamicProt->describe();

    delete dynamicProt;

    // Calling makeProtein function
    cout << "\n=== Calling makeProtein() ===" << endl;
    Protein temp = makeProtein();
    temp.describe();

    cout << "\n=== End of main() ===" << endl;
    return 0;
}
