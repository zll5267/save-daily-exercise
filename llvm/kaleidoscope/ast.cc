
class ExprAST {
public:
	virtual ~ExptAST() {} 	
};

class NumberExprAST
	: public ExprAST {
public:
	NumberExprAST(double val): Val(val) {}
private:
	double Val;
};
// VariableExprAST - Expression class for referencing a variable, like "a"
class VariableExprAST
	: public ExprAST {
public:
	VariableExprAST(const std::string &name) : Name(name) {}
private:
	std::string Name;
};
// BinaryExprAST - Expression class for a binary operator.
class BinaryExprAST
	: public ExprAST
{
public:
	BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS)
		: Op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
private:
	char Op;
	std::unique_ptr<ExprAST> LHS, RHS;
};
// CallExprAST - Expression class for function calls.
class CallExprAST
	: public ExprAST
{
public:
	CallExprAST(const std::string& callee, std::vector<std::unique_ptr<ExprAST> > args)
		: Callee(callee), Args(std::move(args)){}
private:
	std::strig Callee;
	std::std::vector<std::unique_ptr<ExprAST> > Args;
};

// PrototypeAST - This class represents the "prototype" for a function
// which captures its name, and its argument names (thus implicitly the 
// number of arguments the function takes).
class PrototypeAST {
public:
	PrototypeAST(const std::string& name, std::vector<std::string> args)
		: Name(name), Args(std::move(args)) {}
private:
	std::string Name;
	std::vector<std::string> Args;
};
// FunctionAST - This class represents a function definition itself.
class FunctionAST {
public:
	FunctionAST(std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprAST> body)
		: Proto(std::move(proto), Body(std::move(body))) {}
private:
	std::unique_ptr<PrototypeAST> Proto;
	std::unique_ptr<ExprAST> Body;
};