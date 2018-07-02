#include <iostream>
#include <seqan/sequence.h>
#include <seqan/stream.h>

using namespace seqan;
using std::endl;
using std::cout;

template <typename TText1, typename TText2>
void printAlign(TText1 const & genomeFragment, TText2 const & read){
	cout << "Alignment " << endl;
	cout << " genome : " << genomeFragment << endl;
	cout << " read   : " << read << endl;
}
	
int main(){
	Dna5String genome = "ATGGTTTCAACGTAATGCTGAACATGTCGCGT";
	Dna5String read = "TGGTNTCA";

	unsigned beginPosition = 1;
	Infix<Dna5String>::Type genomeFragment = infix(genome, beginPosition, beginPosition + length(read));
	printAlign(genomeFragment, read);
	return 0;
}


