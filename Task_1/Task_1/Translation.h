#include <string>
#include <list>
#include <vector>

using namespace std;

class Translation
{
public:
	Translation() {
		_alphabet.push_back("input");
		_alphabet.push_back("output");
		_alphabet.push_back("[");
		_alphabet.push_back("]");
		_alphabet.push_back("int");
		_alphabet.push_back("double");
		_alphabet.push_back("for");
		_alphabet.push_back("if");
		_alphabet.push_back("=");
		_alphabet.push_back("==");
		_alphabet.push_back(">");
		_alphabet.push_back(">=");
		_alphabet.push_back("=<");
		_alphabet.push_back("+");
		_alphabet.push_back("*");
		_alphabet.push_back("/");
		_alphabet.push_back("(");
		_alphabet.push_back(")");

		//int,double,for,if,=,==,>,>=,-,(,),var
	};
	~Translation() {};
	void FileReader(string fileName);
	void Start();
private:
	class Variable
	{
	public:
		Variable() {};
		~Variable() {};
		string name;
		string type;
		string value;
	};
	list<string> _alphabet;
	list<string> _file;
	vector<string> _line;
	list<Variable> _variable;
	void _LineReading();
	void _LineClean();
	void _Execution();
	bool _VarReVal(string name, string value);
	bool _AlphCheck(string check);
	string _VariableCheck(string check);
};

