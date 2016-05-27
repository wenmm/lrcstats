#include <iostream>
#include <string>
#include "data.hpp"

int main()
{
	std::string referenceMaf = "-C-A--G-AC-G--T-TTT-TT-C-T-GCCCC-AGTGGGCTAA-TCCCCCCAACCAGGTATCCCGTCG-AACGCTGCGCG-ACCATCGGATCG-GCCA-TC-TC-AACTTT-CTTGGCACCC-AGCGCTTTTGCTACTT-TTTTAAGATCCAGTTGACCTGC---GACCGGCGTAACGGC-C-AC-GGCAAGGTGTTTCATATCACCGTTCACTGCCACCAGCAGCGTTTTGT-AG-ACCTGA-T-CCG-GATTCAAA-CC-TAATTTTTTGACGACTTCATCGCCAAAATTGGTTT-CAGC-CGGATCGTGCTCGTAGGTATGGATT-TGAAACGAAATCTTGTTTTTTTCGAGTAA-TTTAACTGCGGGTGTCATGGT--AATTTTCCTGCC-TTAAACAAAAAAACGAAGCAAGCATACGCCTGATGGCGGTCCAAAAAAAAGAGTCATCTTGCCTAAGAGTATTGGCAG-GATGGTGA-GATTGAGCGACAATCGAGTTACA-CCG-TC-GCTTAAAGTGA-CGGCATA-ATAATAAA-A--AAATGAA-ATT--C-CTCTTTGACGGGCC--AATAGCG-ATA-TTGGCCATTTTT-TT-AGCGCAACATTTGCGGCA-AATTCCCT-TCTCCATACAGGTGTAGTGCACCGACCGCGAC-CACA-TATCGCCCCGG-CG-GCATGGC-GCGTAATTT-ATCCCGCCAGGCGAG-ATTTCGCT-GATGCATCAGCACATCGTACAGCG-ACT-GACTGAACG-TA--TTGG-G-C-AGCGTTAT-ATC-ATTAT--TTTGCGGCGGTGCAT-TCAGCC-ACCAGCTC-ATCATTTG-TT-GCAGCAACCGTG-CGTTGGTA-TGCC-AGTGGGTCAGCGTATCGTC-CAGCAGCGCC-AGTC-CTT-TGT-C-AGGGAGCTGGAGCAACATGGCAAT-C-TG-G-TTTTCAGCCCCTTCCA-GTTCAA-TCACGGGTTTATGT--TGTTGCTTCGCCGCCTGCA-A-TAGCTGG-TAATCGATACCGTAT-T-CTGCCCGCAGCCCCAGTTTTTGTG-CCTGCGTCGCC-T-GAAGA-ACCATCGCGATTTGCCACAGCGGT-TGGGTAGAAAA---GAGTGAGGGAGAAAT-GCCCATCTCCTGGCTAATGTGCT-GCAGGTTTTGGAGTTGCTC-CTCGCT-AATG-CGCTCT-TCCAGCGCCTCGCA-GGCA-GGCAAATTAGCAAAAGGCGTATCGCTGGTGGAAACATCCGC-CTCG-ACGATCAGCGCATC--G-GCG-TTTTTGAGCTTTTTGAGC-AAACGGGTGGGCA-GGGGAGC-CATATCGTGGCTACCCATATGAATACTG-CCAATC-AGAT-G-AAAATGGCGATTGCCGGG-GAG-GGT-GATATCGATGGCAGGC-CAGGTGTAATGATT-ACCGCGCAGCGCGGCC-CAAA-GCGTTTTTACCCGGTACAACAGATCCATACGACCT-CCCTTT-GTGAAATATCATGCTAGCGCGCG--GTGAGGGATGGC-GCAAATGGAGTTGGAGACTTG-TT-T--AATGTGTTTGTATGATT-CAGTATGTT-C-TTGCATCG-CTATT-CACAAGGAAGCAACAGT-TA-AAAACCATG-AAACAG-GCAACAAG-AAA-ACCGACG-ACA-CCCGGAGATA-TTCTTCTCT-A-TGAATATC-TGGAACCG-CTCGATTTGAA-AATCAA---TGAGTTAGCAGAGTTGCTG-CATGTTCATCGTAATAGCGTCAGTGCAC-TGATCA-ATAACAATCGTAAACTCACTACTGAGATGGCATTTCG-TCTGGC-GAA-AGTTTT-TGATACCACAGTCGATTTTTGGCTAAAC-CTCCAGGC-GGCGGTTGATCT-TTGGGAAGTTG--AAAACAAC-ATGCGCA-CCCAGGAAGAATTGGGACGGATTGAAACAGTGGCTG-AATATTTGGCACGC-CGTGAAGA-GC-GTGCAAAAAAGGT-C-GCGTAAGGCCAAAACATCGCTTCATCTCGTAGGCCGGATAAGGCGTTCACGCCGCA-TCC-GG-CATC-CGAG--CACCATTGCCT-GATGCGACGCTTACCCGTCTT-A-TCAGGCCTA-C-AAACTTGTGCCTGA-A-CCGTAGGCCGGATAAGGCGTTTACGCCGCATCCGGCATCCG-AGCA--CCATTGC-CTGA--TG-CG-ACGCTTACGCGT-CTT-ATCAGGC-CT-ACAA-ACCTGTG-CCTGAACCGT-AGGCCGGATA--AGGCGTTTACG-CCGCATCCGGCAGTC-ATGCGT-CGATGCCAAATGCGCCACCC-TAAAG--CA-G-CGCATC-CGCAATGATGTACT-TA-TTCCTTCGGTTTAAACCGCAGCAACCGG-TTG-GCGTTACTCACTAC-GGTAATCGACG-AGAGCGC-CATTGCCGCTCCGGCAACTACCGGGTTAAGCAG--TGTTCCAGTGAAC-GGC-CACAAAATACCGGCGGCGACCGGAATAC-CGAT-ACTGT-TGTA-G-ATAAACGCACCG-AGCAGGTTCT-GCTTCATGTTGT-GCAGCGTTGCGCGGGAAATAGCGAGCGCAT-CCGCAACGCCCATCAGGCTATG-GCGCATCAGGGT-AAT-CGCCGCGGTTTCAAT-GGCAACAT-CACTGCCG-CCACC-CATCG-CAATGCCGACATCCG-C---------CT-G-A-GC-CA--GC-GC---";

	std::string uLongReadMaf = "CCAAGGGTACAGTTTTTTTTTTCCTTGG-CCCAA-TGGGCTAAGTCCCCCCAACCAGG-ATTCC-TCGGAAC-CT-CGCGA-CC-TCGGA-CGGGCCATTCTTCAAA-TTTCCTTGGCGCCCGAGCG-TTTTGCTACTTTTTTTAAGATCCAGTTGACCTGCGGAGA-CGGCGTAACGGCCCCACGGGCAAGGTGTTTCCTATCACCGTTCACTGCCACCAGCAGCGTTTTGTTAGAA-C-GAATCCCGGGATTCAAACCCCTA-TT-TTTGACGACTTCATCGCCAAAATTGG-TTCCAGCCCGGAACGTGCTCGT-GGTATGGATTTTGAAACGA-ATCT-GTTTTTTTCGAGTAACTT-ACCTGCGGGTGTCATGGTAAAATTTTTCTGC-TTTA-A-AAAA-AACG-AGCAAGCA-ACGGCTGATGGCGGTC-AAAAAAAAGAGTCATCTTG-CTAAGAGTATTGGC-GGGATGGTGAGGAT-GAG-GACAAT-GAGTTACAGCCGA-CGGCTTAAAGTGACCGGCATACATAATA-AA-AAAAATGAAAATTAGCGCTC-TTGACGGGCCTAAATAGCGAATAGTTGGCCATTTTTTTTAAGCGCAAC-TTTGCGG-AGAATTCCCTTTCTCCATA-AGGTGTAGTGCACCGACCTCGACGCACAGTATCGCCCCGGCCGGGCATGGCGGCG-AATTTAATCCCGCCAGGC-AGT-TTTCGC-GGATGCATCAGCACATCGTACGACGTACTTGACTGAACGTT-CTTTGGGGT-TAGCGTTATAATCA-TTATCATTGGCG-CGGTGCATTTCAGCCAACCAGCTCAATCATT-GATTTGC-GCAACCGTGTCGTTGGTAATGCCAAGTGGGTCAGCGTGTCG-CAC-GCAGCGCCAAGTCCCTTTTGTCCAAGGGAGCTGGA-CAACATGGCAATCCATGGGGTT-TCAGCCCCTT-CACGTTCAAATCACGGGTTTATGTGTTGTTGGTTCG-CGCCTGCAAAATAGCTGGTTAATCGATACCGTATTTTCTGCCCGCAGCCCCAGTT-TTGTGCCCTGCGTCGCCTTGG-AGACACCATCGCGATTTGCCACAGCGGTCTGGGTAGAAAAGGGGAGTGAGGGAGAACTGGCCCATCTCCT-GC-AATGTGCTGG-AGGTTTTGGACTTGCTCCCTCGCCAAATGCCGCTCTTTTGAGCGCCTCG-AGGGCAGGGCAA-TTAGCAAAAGG-GTATCGCTGGTGGAAACAT-C-CCCTC-GACGATCAGC-CAT-GTGTGCGTTTTTTG-CCTCTTTGGGCAAAACG-GTGGGC-AGGGGAGCCC-TATCGTGGC-ACCCATAGGAATACT-TCCGATCAAGATGAAAAAATGGCGATTGCCGGGAGATGGGTAGATATTGAT-GCAGGCGCA-GTGTAATGATTCACCGCGCAGC-CGGCCCCAAAGGCGTTT-TAGCCGGTACAACAGATCCATACG-CCTGCCCTTTG-TGAAATATCATGCTAGCGCGCGGGGTG-GGGATGGCGGCAAATGGAGTTGGAGACTTGTTTTTAAAATGTGTTTGT-TGATTCCAGT-TGTTACTTTG-AT-GCCTATTCCACAAGGAAGCAACAGTTTATAAAACCATGTAAA-AGGG-TACAAGAAAACACCGACGTACAGGCCGGAGA-ATTTCTTCTCTAAATGAA-ATCTTGG-ACCGCCTCGATTTGAAAAATCAATAT-GAGTTAGCAGAG-TGCTGGCATGTTCATCGTAA-AGCGTCAGTGCACGTGATC-TATAACAATCGTAAACTC-CTACTGAGATGGCATTTCGATCTGGCGGAAAAGTTTTGTGATACCACAGTCGATTTTTGGCTAAACCCTCCAGGCCGGCGGTTGATCTTTTGGGAAGTTGATACAACAACAATGCGCACCCCAGGAAGAA-TGGGACGGATTGAAACAGTGGCTGA-ATATTTGGCACGCCCGTGAA-AT-CGGTGCAAAA-AGGTCCGGCGTAAGGCCAAAACATCGCTTCATCT-GTAGGCCGGATAAGGCGTTCACGCCGCATTCCG-GCCA-CCCGAGGGCACCATTGCCTGGATGCGACGCTTACCCGTCTTA-TTCAGGCCTACCTAAACTTG-GCCT-AAAACCGTAGGCCGGAT-AG-CGTCTACGCCGCATCCGGCATCCGAAGCACATCATTGCCCTGACTTGAC-AACG-TTACGCGTCCTTAATCAGGCCCTAACAATACCTGTGCCCTGAACCGTAAG-CCGGATAAAAGGCGTTTACGCCCGCATCCGGCAGTCAATGCGTGCGATGCCAAATGCG-CACCCTTTAAGCC-AGGCCGCATCCCGCAATGAC-TACTTTAGT-CCTTCGGTTTAAACCGCAGCAACCGGTTTGGGCGTTACTCAC-ACCGGTAATCGACGCAGAGC-CACATTGCCGCTCCGGCAACTCCCGGGTTAAGCAGCATGTTCCAGT-AACTGGCCCACAAAATACCGGCGGCGACCGGAATACGCGATGACTGTTTGTAGGAATAAACGCAC-GAA-CAGGTTC-GGCTTCATGTTGTGGCAGCGTTGC-CGGGA-ATAGCGAGCGC-TAC-GCAACGCCCATCAGGCTATGGGCGCATCAGGGTTAATTCGCCG-GGTTTCA-TGGGCAACATACACTG-CGCGCACCCCATCGCCAATGCCGACATCGGCCCAAATCCCC-TGACATGCCC-GATGGGTTTT";

	std::string cLongRead = "ATCG";

	LongReadData data(referenceMaf, uLongReadMaf, cLongRead);

	std::cout << data.getRef() << "\n";
	std::cout << data.getRefMaf() << "\n";
	std::cout << data.getUlr() << "\n";
	std::cout << data.getUlrMaf() << "\n";
	std::cout << data.getClr() << "\n";

	return 0;
}
