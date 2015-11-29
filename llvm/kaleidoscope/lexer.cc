#include <iostream>
#include <string>

enum Token {
	tok_eof = -1,

	// commands
	tok_def = -2,
	tok_extern = -3,

	// primary
	tok_identifier = -4,
	tok_number = -5,
};

static std::string IdetifierStr; // Filled if tok_identifier
static double NumVal; // Filled if tok_number

/// gettok - Return the next token from standard input
static int gettok() {
	static int LastChar = ' ';
	// skip any whitespace
	while (isspace(LastChar))
		LastChar = getchar();
	
	if (isalpha(LastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
		IdetifierStr = LastChar;
		while (isalnum((LastChar = getchar())))
			IdetifierStr += LastChar;

		if (IdetifierStr == "def")
			return tok_def;
		else if (IdetifierStr == "extern")
			return tok_extern;
		return tok_identifier;
	}
	else if (isdigit(LastChar) || LastChar == '.') {
		// Number [0-9.]+
		std::string Numstr;
		do {
			Numstr += LastChar;
			LastChar = getchar();
		} while (isdigit(LastChar) || LastChar == '.')

		NumVal = strtod(Numstr.c_str(), 0);
		return tok_number;
	}
	else if (LastChar == '#') {
		// Comment until end of line
		do {
			LastChar = getchar();
		} while (LastChar != EOF && LastChar != '\n' && LastChar != '\r')

		if (LastChar != EOF)
			return gettok();
	}

	if (LastChar == EOF)
		return tok_eof;

	int ThisChar = LastChar;
	LastChar = getchar();
	return ThisChar;
}
