#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ============================================================
// Global counters for tracking object lifetimes
// These are purely for monitoring creation/destruction order.
// ============================================================
int sequence_count = 0;
int isoform_count  = 0;
int gene_count     = 0;

// ============================================================
// CLASS: Sequence
// Represents a biological DNA/RNA sequence.
// Demonstrates lifecycle events and simple utility methods.
// ============================================================
class Sequence {
private:
    string type;   // e.g. "DNA", "RNA", "mRNA"
    string data;   // actual sequence data (A, T, C, G, U)

public:
    // --- Default Constructor ---
    Sequence()
        : type("N/A"), data("")
    {
        sequence_count++;
        cout << "[Sequence] Default constructed. Count=" << sequence_count << endl;
    }

    // --- Parameterized Constructor ---
    Sequence(const string& t, const string& d)
        : type(t), data(d)
    {
        sequence_count++;
        cout << "[Sequence] Constructed (" << type
             << ", length=" << data.length() << "). Count=" << sequence_count << endl;
    }

    // --- Copy Constructor ---
    Sequence(const Sequence& other)
        : type(other.type), data(other.data)
    {
        sequence_count++;
        cout << "[Sequence] Copied. Count=" << sequence_count << endl;
    }

    // --- Move Constructor ---
    Sequence(Sequence&& other) noexcept
        : type(move(other.type)), data(move(other.data))
    {
        sequence_count++;
        cout << "[Sequence] Moved. Count=" << sequence_count << endl;
    }

    // --- Destructor ---
    ~Sequence() {
        sequence_count--;
        cout << "[Sequence] Destroyed. Remaining=" << sequence_count << endl;
    }

    // --- Describe the sequence ---
    void describe() const {
        cout << "      Type: " << type << endl;
        cout << "      Data: " << data << endl;
        cout << "      Length: " << data.length() << endl;
    }

    // --- Get sequence length ---
    size_t length() const {
        return data.length();
    }
};

// ============================================================
// CLASS: Isoform
// A gene isoform *contains* a Sequence object (composition).
// This demonstrates how inner objects are constructed first.
// ============================================================
class Isoform {
private:
    string id;
    string name;
    Sequence seq;    // Composition: Isoform "has-a" Sequence

public:
    // --- Default Constructor ---
    Isoform()
        : id("N/A"), name("Unnamed"), seq("DNA", "ATGC")
    {
        isoform_count++;
        cout << "[Isoform] Default constructed. Count=" << isoform_count << endl;
    }

    // --- Parameterized Constructor ---
    Isoform(const string& i, const string& n,
            const string& seq_type, const string& seq_data)
        : id(i), name(n), seq(seq_type, seq_data)
    {
        isoform_count++;
        cout << "[Isoform] Constructed (" << name << "). Count=" << isoform_count << endl;
    }

    // --- Copy Constructor ---
    Isoform(const Isoform& other)
        : id(other.id), name(other.name), seq(other.seq)
    {
        isoform_count++;
        cout << "[Isoform] Copied. Count=" << isoform_count << endl;
    }

    // --- Move Constructor ---
    Isoform(Isoform&& other) noexcept
        : id(move(other.id)), name(move(other.name)), seq(move(other.seq))
    {
        isoform_count++;
        cout << "[Isoform] Moved. Count=" << isoform_count << endl;
    }

    // --- Destructor ---
    ~Isoform() {
        isoform_count--;
        cout << "[Isoform] Destroyed. Remaining=" << isoform_count << endl;
    }

    // --- Describe Isoform (also calls Sequence::describe) ---
    void describe() const {
        cout << "    Isoform " << name << " (" << id << "):" << endl;
        seq.describe();
    }
};

// ============================================================
// CLASS: Gene
// A Gene *contains* multiple Isoform objects via vector<Isoform>.
// This is composition with dynamic container.
// ============================================================
class Gene {
private:
    string id;
    string name;
    string chrom;
    int start;
    int end;
    char strand;
    string organism;

    // Composition: Gene "has" many Isoforms
    vector<Isoform> isoforms;

public:
    // --- Default Constructor ---
    Gene()
        : id("N/A"), name("Unnamed"), chrom("chr?"),
          start(0), end(0), strand('+'), organism("Homo sapiens")
    {
        gene_count++;
        cout << "[Gene] Default constructed. Count=" << gene_count << endl;
    }

    // --- Parameterized Constructor ---
    Gene(const string& i, const string& n, const string& c,
         int s, int e, char st, const string& org = "Homo sapiens")
        : id(i), name(n), chrom(c), start(s), end(e),
          strand(st), organism(org)
    {
        gene_count++;
        cout << "[Gene] Constructed (" << name << "). Count=" << gene_count << endl;
    }

    // --- Copy Constructor ---
    Gene(const Gene& other)
        : id(other.id), name(other.name), chrom(other.chrom),
          start(other.start), end(other.end), strand(other.strand),
          organism(other.organism), isoforms(other.isoforms)
    {
        gene_count++;
        cout << "[Gene] Copied (" << name << "). Count=" << gene_count << endl;
    }

    // --- Move Constructor ---
    Gene(Gene&& other) noexcept
        : id(move(other.id)), name(move(other.name)),
          chrom(move(other.chrom)), start(other.start), end(other.end),
          strand(other.strand), organism(move(other.organism)),
          isoforms(move(other.isoforms))
    {
        gene_count++;
        cout << "[Gene] Moved (" << name << "). Count=" << gene_count << endl;
    }

    // --- Destructor ---
    ~Gene() {
        gene_count--;
        cout << "[Gene] Destroyed (" << name << "). Remaining=" << gene_count << endl;
    }

    // --- Add Isoform via copy ---
    void addIsoform(const Isoform& iso) {
        cout << "[Gene] Adding isoform (copy): " << endl;
        isoforms.push_back(iso);
    }

    // --- Add Isoform via in-place construction ---
    void emplaceIsoform(const string& iso_id, const string& iso_name,
                        const string& seq_type, const string& seq_data)
    {
        cout << "[Gene] Emplacing isoform (in-place construction)" << endl;
        isoforms.emplace_back(iso_id, iso_name, seq_type, seq_data);
    }

    // --- Describe Gene and all its Isoforms ---
    void describe() const {
        cout << "\n=== Gene " << name << " (" << id << ") ===" << endl;
        cout << " Organism: " << organism << endl;
        cout << " Chromosome: " << chrom << endl;
        cout << " Coordinates: " << start << " - " << end << endl;
        cout << " Strand: " << strand << endl;
        cout << " Isoform count: " << isoforms.size() << endl;

        for (size_t i = 0; i < isoforms.size(); ++i) {
            cout << "  [" << (i+1) << "] ";
            isoforms[i].describe();
        }
    }
};

// ============================================================
// MAIN
// Demonstrates:
// - Composition
// - Construction order
// - Lifetime tracing
// - Adding Isoforms to a Gene
// ============================================================
int main() {
    cout << "=== LAB 03: CLASS COMPOSITION DEMO ===\n" << endl;

    // 1. Create Gene
    Gene gene("G001", "BRCA1", "chr17", 43044295, 43170245, '+');

    // 2. Create Isoforms
    Isoform iso1("ISO001", "BRCA1-201", "mRNA", "AUGGCCAUGGCGCCC");
    Isoform iso2("ISO002", "BRCA1-202", "mRNA", "AUGGCUACUGAAGGG");

    // 3. Add Isoforms to Gene
    gene.addIsoform(iso1);
    gene.addIsoform(iso2);

    // 4. Emplace Isoform directly inside Gene
    gene.emplaceIsoform("ISO003", "BRCA1-203", "mRNA", "AUGCCCUUGGA");

    // 5. Describe full Gene structure
    gene.describe();

    cout << "\n=== End of main() ===" << endl;
    return 0;
}
