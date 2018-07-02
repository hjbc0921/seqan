#include <seqan/stream.h>
#include <seqan/sequence.h>
#include <seqan/file.h>

using namespace seqan;

int assign_3()
{
    String<Dna5> nucleotides = "AGTCGTGNNANCT";
	String<Dna5> lesser;
	String<Dna5> greater;

	for (unsigned i = 0; i < length(nucleotides); ++i) {
		Lexical<> comp(nucleotides[i], 'G');
		if (isLess(comp))
    		appendValue(lesser, nucleotides[i]);
		else if (isGreater(comp))
			appendValue(greater, nucleotides[i]);
    }
    std::cout << "Lesser nucleotides: " << lesser << std::endl;
	std::cout << "Greater nucleotides: " << greater << std::endl;
    return 0;
}

int main(){
	String<Dna5String> DnaList;
	resize(DnaList,3);
	DnaList[0] = "ATATANGCGT";
	DnaList[1] = "AAGCATGANT";
	DnaList[2] = "TGAAANTGAC";
	String<Dna5String> lesser;
	String<Dna5String> greater;
	
	for (unsigned i=0; i<length(DnaList); ++i){
		Lexical<> comp(DnaList[i],"GATGCATGAT");
		if (isLess(comp))
			appendValue(lesser, DnaList[i]);
		else if (isGreater(comp))
			appendValue(greater, DnaList[i]);
	}
	std::cout << "Lesser: " << lesser << std::endl; //separated by newline
	std::cout << "Greater: " << greater << std::endl;
	return 0;
}
