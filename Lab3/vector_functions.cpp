// // ============================================================
// // FUNCTION: printAllGenes()
// // Prints a vector of Gene objects.
// // Demonstrates passing vectors by const reference.
// // ============================================================
// void printAllGenes(const vector<Gene>& genes) {
//     cout << "\n=== Printing all genes (vector<Gene>) ===" << endl;

//     for (size_t i = 0; i < genes.size(); ++i) {
//         cout << "\n[Gene #" << (i + 1) << "]" << endl;
//         genes[i].describe();
//     }
// }


// // ============================================================
// // FUNCTION: countTotalIsoforms()
// // Counts all isoforms inside all genes.
// // Demonstrates nested traversal of composed objects.
// // ============================================================
// size_t countTotalIsoforms(const vector<Gene>& genes) {
//     size_t total = 0;
//     for (const auto& g : genes) {
//         // Unfortunately Gene::isoforms is private.
//         // We would normally add a getter such as getIsoformCount().
//         // For this lab, we simply use describe() output.
//         // Instead, we extend the class with a public method:

//         // We assume you added: size_t isoformCount() const { return isoforms.size(); }
//         total += g.isoformCount();
//     }
//     return total;
// }


// // ============================================================
// // FUNCTION: createDefaultGene()
// // Returns a new Gene object with 2 automatically created Isoforms.
// // Demonstrates returning objects by value (using move semantics).
// // ============================================================
// Gene createDefaultGene() {
//     Gene g("G100", "DEFAULT_GENE", "chrX", 1000, 5000, '+');
//     g.emplaceIsoform("ISO100", "DEFAULT-1", "mRNA", "AUGAAAUGGCCC");
//     g.emplaceIsoform("ISO101", "DEFAULT-2", "mRNA", "AUGCCCCUGAAGG");
//     return g;  // NRVO or move constructor optimizes this
// }


// // ============================================================
// // FUNCTION: filterGenesByChromosome()
// // Returns only those Genes on a specific chromosome.
// // Demonstrates algorithmic vector processing.
// // ============================================================
// vector<Gene> filterGenesByChromosome(const vector<Gene>& genes,
//                                      const string& chromosome)
// {
//     vector<Gene> result;
//     for (const auto& g : genes) {
//         // We need a public getter in Gene for chromosome (getChrom())
//         if (g.getChrom() == chromosome) {
//             result.push_back(g);
//         }
//     }
//     return result;  // returned by value (move-optimized)
// }
