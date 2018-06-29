#include <iostream>
#include <seqan/arg_parse.h>

using namespace seqan;
using std::cout;
using std::endl;

int main(int argc, char const ** argv){
	ArgumentParser parser("modify_string");
	addArgument(parser, ArgParseArgument(ArgParseArgument::STRING, "TEXT"));
	addOption(parser, ArgParseOption("i", "period", "Period to use for the index.", ArgParseArgument::INTEGER, "INT"));
	addOption(parser, ArgParseOption("U", "uppercase", "Select to-uppercase as operation."));

	ArgumentParser::ParseResult res = parse(parser, argc, argv);
	if (res != ArgumentParser::PARSE_OK) 
		return res == ArgumentParser::PARSE_ERROR;

	unsigned period = 0;
	getOptionValue(period, parser, "period");
	bool toUppercase = isSet(parser, "uppercase");
	CharString text;
	getArgumentValue(text, parser, 0);

	cout << "period	  \t" << period << "\n"
		 << "uppercase\t" << toUppercase << "\n"
		 << "text	  \t" << text << "\n";

	return 0;
}

