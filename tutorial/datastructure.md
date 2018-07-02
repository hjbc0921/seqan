### SeqAn class String
```c++
String<char> myText; 
myText = "Hello SeqAn!";
typedef String<DnaString> TDnaList; //String of DnaStrings
String<unsigned> alignPosList;

resize(myText, 10); //resize capacity
appendValue(myText, "!");
length(myText);
clear(myText);
reverseComplement(DnaString);
a > b; //lexicographically compare strings
Lexical<> comp(a, b);
if (isLess(comp)); //case for a < b
else if (isGreater(comp));

assign(char_target, dna_source); //by operator=, copy
move(dna_target, char_source); //can not use char_source

//iterator : standard 
Dna5String genome = "ANTC";
Iterator<Dna5String>::Type it = begin(genome);
Iterator<Dna5String>::Type itEnd = end(genome);
for (; it != itEnd; goNext(it)) if (*it=='N') *it = 'A';

//iterator : rooted
Iterator<Dna5String, Rooted>::Type it = begin(genome);
for (; !atEnd(it); goNext(it)) if (getValue(it) == 'N') value(it) = 'A';
```
* string allocation
  * exact 
``` resize(dnaseq, 4, Exact()); ```
  * generous : the number of capacity change is limited 
that resizing the sequence only takes amortized constant time
  * limit : values exceed the capacity are lost
  * insist : no capacity check is performed

*  string specializations
  * Alloc String : stored on the heap, changing capacity can be very costly(copy)
  * Array String : fixed
  * Block String : fast capacity change, sligtly slower random access
  * Packed String : store large strings in memory
  * External String : store very large strings
  * Journaled String : store similar strings
  * CStyle String : null terminated char arrays

### SeqAn class Segment
* prefix, infix, suffix
* not a copy
```c++
String<Dna> dnaSeq = "AGTTGGCATG"
Prefix<String<Dna> >::Type pre = prefix(dnaSeq, 4); //end index exclude
infix(dnaSeq, 4, 7); //start included end excluded
suffix(dnaSeq, 4); //start index
```

### String Sets
* supports concat

```c++
StringSet<DnaString> stringSet;
appendValue(stringSet, str0);

StringSet<DnaString, Owner<> > ownerSet1;
StringSet<DnaString, Owner<ConcatDirect> > ownerSet2; //sequences are actually stored others are virtual(no copy)
StringSet<DnaString, Owner<JournaledSet> > ownerSet3; 
StringSet<DnaString, Dependent<Generous> > dependSet; //sequence pointers are stored
```

### Alphabets
* SimpleType class : AminoAcid, Dna, Dna, DnaQ(phred), Dna5Q, Finite, Iupac, Rna, Rna5








