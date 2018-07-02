#include <iostream>
#include <seqan/sequence.h>
#include <seqan/stream.h>

using namespace seqan;
using std::cout;
using std::endl;

template <typename TText1, typename TText2>
void printAlign(TText1 const & genomeFragment, TText2 const & read){
	cout << "Alignment " << endl;
	cout << " genome : " << genomeFragment << endl;
	cout << " read   : " << read << endl;
}

int main(){
	DnaString chr1 = "TATAATATTGCTATCGCGATATCGCTAGCTAGCTACGGATTATGCGCTCTGCGATATATCGCGCTAGATGTGCAGCTCGATCGAATGCACGTGTGTGCGATCGATTAGCGTCGATCATCGATCTATATTAGCGCGCGGTATCGGACGATCATATTAGCGGTCTAGCATTTAG";
	
	typedef String<DnaString> TDnaList;
    TDnaList readList;
    resize(readList, 4);
    readList[0] = "TTGCTATCGCGATATCGCTAGCTAGCTACGGATTATGCGCTCTGCGATATATCGCGCT";
    readList[1] = "TCGATTAGCGTCGATCATCGATCTATATTAGCGCGCGGTATCGGACGATCATATTAGCGGTCTAGCATT";
    readList[2] = "AGCCTGCGTACGTTGCAGTGCGTGCGTAGACTGTTGCAAGCCGGGGGTTCATGTGCGCTGAAGCACACATGCACA";
    readList[3] = "CGTGCACTGCTGACGTCGTGGTTGTCACATCGTCGTGCGTGCGTACTGCTGCTGACA";
	
	DnaString chr2 =  "AGCCTGCGTACGTTGCAGTGCGTGCGTAGACTGTTGCAAGCCGGGGGTTCATGTGCGCTGAAGCACACATGCACACGTCTCTGTGTTCCGACGTGTGTCACGTGCACTGCTGACGTCGTGGTTGTCACATCGTCGTGCGTGCGTACTGCTGCTGACACATGCTGCTG";
    append(chr1, chr2);

	cout << " \n Read list: " << endl;
	for (unsigned i=0; i<length(readList); ++i){
		cout << readList[i] << endl;
	}
	
	String<unsigned> alignPosList;
	resize(alignPosList, 4);
	alignPosList[0] = 7;
	alignPosList[1] = 100;
	alignPosList[2] = 172;
	alignPosList[3] = 272;

	DnaString bsChr1;
	assign(bsChr1, chr1);
	for (unsigned i=0; i<length(bsChr1); ++i){
		if (bsChr1[i] == 'C') bsChr1[i] = 'T';
	}
	cout << " \n Print alignment: " << endl;
	for (unsigned i=0; i<length(readList); ++i){
		unsigned beginPosition = alignPosList[i];
		DnaString genomeFragment;
		for (unsigned j=0; j<length(readList[i]); ++j)
			appendValue(genomeFragment, chr1[beginPosition+j]);
		printAlign(genomeFragment, readList[i]);
	}
	return 0;
}
