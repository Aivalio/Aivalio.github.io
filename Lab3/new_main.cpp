// int main() {
//     cout << "=== LAB 03: ADVANCED COMPOSITION DEMO ===\n" << endl;

//     // ------------------------------------------------------------
//     // 1. Create several Gene objects
//     // ------------------------------------------------------------
//     Gene g1("G001", "BRCA1", "chr17", 43044295, 43170245, '+');
//     Gene g2("G002", "TP53",  "chr17", 7668402,  7687550,  '-');
//     Gene g3("G003", "EGFR",  "chr7",  55086714, 55270768, '+');

//     // Add isoforms to g1
//     Isoform iso1("ISO001", "BRCA1-201", "mRNA", "AUGGCCAUGGCGCCC");
//     Isoform iso2("ISO002", "BRCA1-202", "mRNA", "AUGGCUACUGAAGGG");
//     g1.addIsoform(iso1);
//     g1.addIsoform(iso2);

//     // Add isoforms to g2 using emplace
//     g2.emplaceIsoform("ISO010", "TP53-1", "mRNA", "AUGGAGGUUACGA");
//     g2.emplaceIsoform("ISO011", "TP53-2", "mRNA", "AUGGCCCCUUUAG");

//     // Add isoforms to g3
//     g3.emplaceIsoform("ISO020", "EGFR-1", "mRNA", "AUGUACAAGGGUUG");

//     // ------------------------------------------------------------
//     // 2. Store all genes in a vector (vector<Gene>)
//     // ------------------------------------------------------------
//     vector<Gene> genes;
//     genes.push_back(g1);
//     genes.push_back(g2);
//     genes.push_back(g3);

//     // Add a default-generated gene (demonstrates return-by-value)
//     genes.push_back(createDefaultGene());

//     // ------------------------------------------------------------
//     // 3. Use our new utility functions
//     // ------------------------------------------------------------

//     // --- Print all genes ---
//     printAllGenes(genes);

//     // --- Count all isoforms in the full collection ---
//     cout << "\nTotal isoforms in all genes: "
//          << countTotalIsoforms(genes) << endl;

//     // --- Filter genes by chromosome ---
//     cout << "\nFiltering genes on chromosome chr17..." << endl;
//     vector<Gene> chr17_genes = filterGenesByChromosome(genes, "chr17");

//     printAllGenes(chr17_genes);

//     // ------------------------------------------------------------
//     // 4. End main (destruction order will be shown automatically)
//     // ------------------------------------------------------------
//     cout << "\n=== End of main() ===" << endl;
//     return 0;
// }
