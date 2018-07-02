#include <seqan/sequence.h>
#include <seqan/stream.h>

using namespace seqan;

int main(){
	StringSet<DnaString> stringSet;
	DnaString str0 = "TATA";
	DnaString str1 = "CGCG";
	appendValue(stringSet, str0);
	appendValue(stringSet, str1);
}


