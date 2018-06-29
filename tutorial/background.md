from http://seqan.readthedocs.io/en/master/Tutorial/GettingStarted/BackgroundAndMotivation.html

### Memory Management
C++ allocate complex objects on the stack (in contrast to Java where objects are always constructed on the heap) so allocation happens on construction and deallocation happens when the current block is left. 

### Template Programming & Generic Programming (instead of OOP)
* used C++ templates to reduce memory usage or running time by taking advantage of the idea that DNA, IUPAC, amino acids only requires certain characters
* instead of char array, leave the type of the array elements open : Dna, Dna5 ...
* template subclassing : polymorphism at compile time - compiler can inline all functions calls
```c++
template <typename TTest, typename TPattern> // decided at compile time
```

### Global Function Interface
* use function(variable) instead of variable.function() because it is not a member function
* then we can extend the interface of a type outside of its definition
* no exceptions

### string.cpp
```c++
#include <seqan/sequence.h>
#include <seqan/score.h>
using namespace seqan;
String<char> text = "hello";
String<int> score;
resize(score,3);
infix(text,i,j); //text[i...j-1] generates a Infix using pointers

score(Blosun62(), amino, acid); // amino acid similarity

int computeLocalScore(TText const & subText, TPattern const & pattern) //function with template subclassing

//Tag-Based Dispatching
struct MaxOnly {};
void print(TText const & score, MaxOnly const & /*tag*/) 
print(score, MaxOnly())

//default tag
struct something {};
template <typename TText, typename TSpec>
void print(TText const & text, TSpec const & /*tag*/)
print(score, something()) 
```
* starts at position 0
* ++variable is slightly faster because it does not copy itself
* DnaString, CharString, 

### command.cpp
```
./my_project modify_string -h
```

