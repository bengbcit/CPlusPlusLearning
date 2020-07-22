//############################################################################
/* C++ Character Conversion Functions
 *
 * Category A: Character to Integer
 * Category B: Character to String
 * Category C: Character Array to String
 */
#include "UserInputCheck.h"

int main() {

	/*Instruction Code*/
	cout << "***************Instructions****************" << endl;
	cout << "*  Case 1: Char to Int                    *" << endl;
	cout << "*  Case 2: Char to String                 *" << endl;
	cout << "*  Case 3: Char Array to String           *" << endl;
	cout << "***************Instructions****************" << endl << endl;

	// initialization
	string s = "0";
	Options_Num = 3;

	// keep doing until return a number string (1 to 9)
	while (~isdigit_fn(User_input(s)));
	
	switch (case_num){
		case 1: 
			cout << "***************Char to Int*************** " << endl;
			cout << "1) By Casting" << endl;
			cout << "char a = '2';" << endl;
			cout << "int num = a-48;" << endl;
			cout << "Result is 2 becasue 48 is ASCII value of '0'" << endl<<endl;

			cout << "2) Using stringstream" << endl;
			cout << "#include <sstream> " << endl;
			cout << " " << endl;
			cout << "stringstream str; " << endl;
			cout << "str << \"5\"; int x; str >> x; " << endl;
			cout << "cout<<\"Converted value of character 5 :\"<<x; " << endl << endl;
			cout << "Result x is: 5 " << endl;
			cout << "***************Finish Here*************** " << endl;
			break;
		case 2:
			cout << "***************Char to String*************** " << endl;
			/*	Function Prototype: string s(int n, char x);
				Parameter(s):
					n=> Size of the string to be generated.
					x=> Character that is to be converted to a string.
				Return Value: string obtained by conversion of character.
				Description: The constructor of string class takes in the length of the string (n)
							 and a single character as parameters and then converts the character to string.
			*/
			cout << "1) Using A constructor Provided By String Class." << endl;
			cout << "string str(1,'A'); " << endl;
			cout << "cout<<\"The string obtained by converting single character : \"<<str; " << endl << endl;
			cout << "Result is: A " << endl << endl;

			/* We can use these overloaded operators to convert a single character to string.*/
			cout << "2) Using std::string Operator = And += " << endl;
			cout << "string str; " << endl;
			cout << "char c = 'B'; " << endl;
			cout << "str = 'C'; " << endl;
			cout << "str += c; " << endl << endl;
			cout << "cout<<\"The string obtained by converting single character : \"<<str;" << endl<<endl;
			cout << "Result is: CB " << endl<<endl;

			/*std:: string class supports various overloaded methods using which
					we can pass a character to string that ultimately converts character to string.*/
			cout << "3) Using Various Methods Of std:: string " << endl<<endl;

			/*	Function Prototype: void push_back (char c)
				Parameter(s): c=> Character to be assigned to string
				Return Value: returns void
				Description: This function is overloaded for characters and it assigns
							 a character to the end of the string.
			*/
			cout << "	3.1 .push_back " << endl;
			cout << "	string str; " << endl;
			cout << "	str.push_back('A'); " << endl;
			cout << "	cout<<\"push_back single character : \"<<str<<endl; " << endl;
			cout << "	Result is: A" << endl << endl;

			/*	Function Prototype: string& append (size_t n, char c)
				Parameter(s):
					n=> Number of times the character is to be appended.
					c=> Character that is to be appended to the string.
				Return Value: String obtained by conversion of character.
				Description:The first argument is the number of times the character is to be copied to the string.
							The second argument is the actual character to be copied.
			*/
			cout << "	3.2 .append " << endl;
			cout << "	str=\"\";" << endl;
			cout << "	str.append(1,'C');" << endl;
			cout << "	cout<<\"append single character : \"<<str<<endl;" << endl;
			cout << "	Result is: C" << endl << endl;

			/*	Function Prototype: string& assign (size_t n, char c);
				Parameter(s):
					n=> Number of copies of the character.
					c=> Character that is to be copied to string.
				Return Value: String obtained by conversion of character.
				Description: Assign function replaces the current string contents with n (first argument)
							 copies of the character (second argument).
			*/
			cout << "	3.3 .assign " << endl;
			cout << "	str=\"\";" << endl;
			cout << "	str.assign(1,'D');" << endl;
			cout << "	cout<<\"assign single character : \"<<str<<endl;" << endl;
			cout << "	Result is: D" << endl << endl;

			/*	Function Prototype: string& insert (size_t pos, size_t n, char c);
				Parameter(s):
					pos=> Position at the beginning of which characters are to be inserted.
					n=> Number of copies of the character.
					c=> Character that is to be inserted into the string.
				Return Value: String obtained by conversion of character.
				Description: This function inserts n(second argument) copies of character (third argument)
							 at the beginning position of the string specified by pos(first argument).
			*/
			cout << "	3.4 .insert " << endl;
			cout << "	str.insert(0,1,'B');" << endl;
			cout << "	cout<<\"insert single character : \"<<str<<endl;" << endl;
			cout << "	Result is: BD" << endl << endl;

			cout << "4) Using std::stringstream " << endl;
			cout << "#include <string> "<<endl<<"#include <sstream>" << endl;
			cout << "string str; " << endl;
			cout << "stringstream mystr; " << endl<<endl;
			cout << "mystr<<'A'; mystr>>str; " << endl;
			cout << "cout<<\"The string obtained by converting single character : \"<<str;" <<endl<< endl;
			cout << "Result is: The string... : A" << endl;
			cout << "***************Finish Here*************** " << endl;
			break;
		case 3:
			/*	The class std:: string has many methods that can come handy while dealing with character arrays.
				Hence it is advisable to convert character arrays to string objects and then
				use them so that we can write efficient programs.*/
			cout << "**********Char Array to String********** " << endl;
			cout << "1) Using String Constructor" << endl;
			/*	Function Prototype: string (const char* s);
				Parameter(s):
					s=> null-terminated character array to be converted to string				
				Return Value: string=> converted string
				Description: This overloaded constructor of std::string class takes the character array 
							 or C-string as an argument and returns the string.
			*/
			cout << "char myarray[] = {\"Software Testing Help\"}; " << endl;
			cout << "string mystr(myarray); " << endl << endl;
			cout << "cout<<\"Converted string : \"<<mystr; " << endl;
			cout << "Result is: Software Testing Help" << endl<<endl;

			cout << "2) Using = Overloaded Operator" << endl;
			/*	Another approach to convert character array to string object is to use an overloaded operator =. 
				In this we can directly assign the character array to string object using = operator 
				and the contents will be passed to string.*/
			cout << "char myarray[] = {\"Software Testing Help\"}; " << endl;
			cout << "string mystr; " << endl << endl;
			cout << "mystr = myarray;" << endl;
			cout << "cout<<\"Converted string : \"<<mystr; " << endl;
			cout << "Result is: Software Testing Help" << endl;
			cout << "***************Finish Here*************** " << endl;
			break;
		default:
			cout << "No more cases!" << endl;
			break;
	}



	return 0;
}