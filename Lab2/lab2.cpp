#include <iostream>
#include <string>
#include <vector>
using namespace std;

int protein_count = 0;
int gene_count = 0;

class Protein {
    private:
        string id;
        string name;
        string sequence;
    public:
        // Constructors and Destructors
        Protein();
        Protein(const string&in_id, const string&in_name, const string&in_sequence);
        ~Protein();

        // Setters
        void set_id(const string&in_id);
        void set_name(const string&in_name);
        void set_sequence(const string&in_sequence);

        // Getters
        string get_id() const;
        string get_name() const;
        string get_sequence() const;

        // Describe
        void describe() const;

        // Length
        int length() const;
};

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
        // Constructors and Destructors
        Gene();
        Gene(const string& in_id, const string& in_name, const string& in_chrom,
         int in_start, int in_end, char in_strand,
         const string& in_organism = "Homo sapiens");
        ~Gene();

        // Setters
        void setID(const string& in_id) { id = in_id; }
        void setName(const string& in_name) { name = in_name; }
        void setChrom(const string& in_chrom) { chrom = in_chrom; }
        void setStart(int in_start) { start = in_start; }
        void setEnd(int in_end) { end = in_end; }
        void setStrand(char in_strand) { strand = in_strand; }

        // Getters
        string getID() const { return id; }
        string getName() const { return name; }
        string getChrom() const { return chrom; }
        int getStart() const { return start; }
        int getEnd() const { return end; }
        char getStrand() const { return strand; }
        string getOrganism() const { return organism;}

        // Describe
        void describe() const;
    };

Protein makeProtein() {
    Protein temp("P999", "TEMP_PROT", "MSSSSSSSS");
    cout << "Η συνάρτηση makeProtein() τελειώνει.\n";
    return temp;
}

int main(void) {
    
    cout << "=== Δημιουργία αυτόματων αντικειμένων ===" << endl;
    Protein p1("P001", "PTEN", "MTAIIKEIVSRNKRRYQEDGFDLDLTYIYPNIIAMGFPA");
    Protein p2("P002", "BRCA1_Protein", "MSSSQDNRNLPQKAK");

    cout << "\n=== Πληροφορίες Πρωτεϊνών ===" << endl;
    p1.describe();
    cout << "Length: " << p1.length() << endl;
    p2.describe();
    cout << "Length: " << p2.length() << endl;

    cout << "\n=== Δημιουργία Γονιδίων ===" << endl;
    Gene g1("G001", "BRCA1", "chr17", 43044295, 43170245, '+');
    Gene g2("G002", "TP53", "chr17", 7668402, 7687550, '-');
    g1.describe();
    g2.describe();

    cout << "\n=== Δυναμική δημιουργία ===" << endl;
    Protein* p3 = new Protein("P003", "MYC", "MTENEVHVEEQK");
    p3->describe();
    delete p3;  // Εδώ καλείται ο destructor

    cout << "\n=== Δοκιμή προσωρινού αντικειμένου από συνάρτηση ===" << endl;
    Protein temp = makeProtein();  // εδώ θα δεις constructors/destructors
    temp.describe();

    cout << "\n=== Τέλος main() ===" << endl;
    return 0;
}

// PROTEIN IMPLEMENTATION

Protein::Protein() 
    : id{"N/A"}, name{"Unnamed"}, sequence{""} {
        protein_count++;
        cout << "Protein created by default" << endl;
        cout << protein_count++;
}

Protein::Protein(const string&in_id, const string&in_name, const string&in_sequence) 
    : id{in_id}, name{in_name}, sequence{in_sequence} {
        protein_count++;
        cout << "Protein created with elements";
        cout << protein_count++;
}

Protein::~Protein() {
    protein_count--;
    cout << "Protein destroyed" << endl;
    cout << protein_count << endl;
}

void Protein::set_name(const string&in_name) {
    name = in_name;
}

void Protein::set_id(const string&in_id) {
    id = in_id;
}
void Protein::set_sequence(const string&in_sequence) {
    sequence = in_sequence;
}

string Protein::get_id() const {
    return id;
}

string Protein::get_name() const {
    return name;
}

string Protein::get_sequence() const {
    return sequence;
}

void Protein::describe() const {
    cout << "Protein " << name << " (" << id << "): " << sequence << endl;
}

int Protein::length() const {
    return sequence.length();
}
