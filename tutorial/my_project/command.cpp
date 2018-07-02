#include <iostream>
#include <seqan/arg_parse.h>

using namespace seqan;
using std::cout;
using std::endl;

struct ModifyStringOptions {
	unsigned period;
	bool toUppercase;
	bool toLowercase;
	CharString inputFileName;
	unsigned rangeBegin, rangeEnd;	
	ModifyStringOptions() :
	period(1), rangeBegin(0), rangeEnd(0), toUppercase(false), toLowercase(false)
	{}
};

ArgumentParser::ParseResult
parseCommandLine(ModifyStringOptions & options, int argc, char const ** argv){
	ArgumentParser parser("modify_string");
	addOption(parser, ArgParseOption("I", "input-file", "text input file", ArgParseArgument::INPUT_FILE, "IN"));
	setValidValues(parser, "input-file", "txt");
	setRequired(parser, "input-file");

	addOption(parser, ArgParseOption("i", "period", "Period to use for the index.", ArgParseArgument::INTEGER, "INT"));
	setMinValue(parser, "period", "1");
	addOption(parser, ArgParseOption("U", "uppercase", "Select to-uppercase as operation."));
	addOption(parser, ArgParseOption("L", "lowercase", "Select to-lowercase as operation."));
	addOption(parser, ArgParseOption("r", "range", "The range to modify.", ArgParseArgument::INTEGER, "BEGIN END", false, 2));
	ArgumentParser::ParseResult res = parse(parser, argc, argv);
	if (res != ArgumentParser::PARSE_OK) 
		return res;

	getOptionValue(options.period, parser, "period");
	options.toUppercase = isSet(parser, "uppercase");
	options.toLowercase = isSet(parser, "lowercase");
	getOptionValue(options.inputFileName, parser, "input-file");
	getOptionValue(options.rangeBegin, parser, "range", 0);
	getOptionValue(options.rangeEnd, parser, "range", 1);
	
	if (options.toUppercase && options.toLowercase) {
		std::cerr << "ERROR : You can not specify both to-uppercase and to-lowercase!\n";
		return ArgumentParser::PARSE_ERROR;
	}

	return ArgumentParser::PARSE_OK;
}

CharString modifyString(CharString const & text, ModifyStringOptions const & options) {
    
	CharString result;

    if (options.toLowercase)
    {
        for (unsigned i = 0; i < length(text); ++i)
        {
            if (i % options.period == 0u)
                appendValue(result, tolower(text[i]));
            else
                appendValue(result, text[i]);
        }
    }
    else
    {
        for (unsigned i = 0; i < length(text); ++i)
        {
            if (i % options.period == 0u)
                appendValue(result, toupper(text[i]));
            else
                appendValue(result, text[i]);
        }
    }

    return result;
}

int main(int argc, char const ** argv){
	
	ModifyStringOptions options;
	ArgumentParser::ParseResult res = parseCommandLine(options, argc, argv);

	if (res != ArgumentParser::PARSE_OK) {
		return res == ArgumentParser::PARSE_ERROR;
	}
		
	std::fstream inFile(toCString(options.inputFileName), std::ios::binary | std::ios::in);
	if (!inFile.good()){
		std::cerr << "ERROR : Could not open input file " << options.inputFileName << '\n';
		return 1;
	}
	CharString text;
	while (inFile.good()){
		char c = inFile.get();
		if (inFile.good())	
			appendValue(text, c);
	}
	cout << modifyString(text, options);

	return 0;
}

