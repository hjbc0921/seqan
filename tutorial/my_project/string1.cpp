#include <iostream>
#include <seqan/sequence.h>
#include <seqan/basic.h>
#include <seqan/stream.h>
#include <seqan/file.h>
#include <seqan/modifier.h>

using namespace seqan;

Dna getRevCompl(Dna const & nucleotide) {
	if (nucleotide == 'A') return 'T';
	if (nucleotide == 'T') return 'A';
	if (nucleotide == 'C') return 'G';
	return 'C';
}

int main(){
	DnaString genome = "TATATACGCGCGACTCGT";
	DnaString revComplGenome;
	resize(revComplGenome, length(genome));
	for (int i=0; i<length(genome); ++i){
		revComplGenome[length(genome)-1-i] = getRevCompl(genome[i]);
	}
	std::cout << genome << std::endl;
	std::cout << revComplGenome << std::endl;
	reverseComplement(genome);
	std::cout << genome << std::endl;
	return 0;
}
