#include <seqan/stream.h>
#include <seqan/sequence.h>
#include <iostream>

using namespace seqan;

int main(){
	Dna5String genome = "ANTGGTTNCAACNGTAANTGCTGANNNACATGTNCGCGTGTA";
	Iterator<Dna5String>::Type it = begin(genome);
	Iterator<Dna5String>::Type itEnd = end(genome);

	for (; it != itEnd; goNext(it)){
		if (*it == 'N') *it = 'A';
	}
	std::cout << "Modified genome: " << genome << std::endl;
	return 0;
}
