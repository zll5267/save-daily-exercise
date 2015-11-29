static int CurTok;
static int getNextToken() {
	return CurTok = gettok();
}

std::unique_ptr<ExprAST> Error(const char* str) {
	fpritf(stderr, "Error: %s \n", str);
	return nullptr;
}
std::unique_ptr<PrototypeAST> ErrorP(const char* str) {
	Error(str);
	return nullptr;
}