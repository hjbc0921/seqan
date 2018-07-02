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
```c++
./my_project -h or ./my_project "test" -i 1 -U ...

#include <seqan/arg_parse.h>
seqan::ArgumentParser parser("modify_string"); //ArgumentParser object
//arguments & options constructors
addArgument(parser, seqan::ArgParseArgument(seqan::ArgParseArgument::STRING, "TEXT"));
addOption(parser, seqan::ArgParseOption("i", "period", "Period to use for the index.", seqan::ArgParseArgument::INTEGER, "INT")); //can use isList parameter(true, 3) or tuples(false,2)
seqan::setMinValue(parser, "i", "10");
setRequired(parser, "i");
seqan::setValidValues(parser, "i", "1 2 3");

//input output file argument
seqan::addOption(parser, seqan::ArgParseOption("I", "input-file", "Path to the input file", seqan::ArgParseArgument::INPUT_FILE, "IN"));
seqan::addOption(parser, seqan::ArgParseOption("O", "output-file", "Path to the output file", seqan::ArgParseArgument::OUTPUT_FILE, "OUT"));
seqan::setValidValues(parser, "input-file", "txt");
seqan::getOptionValue(inputFileName, parser, "input-file");

//parse & get return value
seqan::ArgumentParser::ParseResult res = seqan::parse(parser, argc, argv); //seqan::Argument::PARSE_ERROR or PARSE_OK or --help 

//get values
getOptionValue(destination, parser, "period");
isSet(parser, "uppercase");
getArgumentValue(destination, parser, 0);

```
* better to use struct to save these options and arguments (with initialization)
* better to encapsulate argument parsing into its own function 
```c++
seqan::ArgumentParser::ParseResult
parseCommandLine(ModifyStringOptions & options, int argc, char const ** argv);
seqan::ArgumentParser::ParseResult res = parseCommandLine(options, argc, argv);
```
* documentation
```c++
seqan::setShortDescription(parser, "String Modifier");
seqan::setVersion(parser, "1.0");
seqan::setDate(parser, "July 2018");
seqan::addUsageLine(parser, "[\\fIOPTIONS\\fP] \"\\fITEXT\\fP\"");
seqan::addDescription(parser, "This program allows simple character modifications");
```




