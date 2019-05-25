// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//


#include "Map.h"
#include"Coding.h"
#include "List.h"
#include <iostream>
#include <string>

int main()
{

	Map <char, string> chars_to_codes;
	string incoded_quote;
	string quote;
	string decoded_quote;
	getline(cin, quote);
	chars_to_codes = Codingiguess(Frequencies(quote));
	incoded_quote = incoding(chars_to_codes, quote);
	decoded_quote = decode(chars_to_codes, incoded_quote);
	cout << "coded line: " << incoded_quote << endl;
	cout << "decoded: " << decoded_quote << endl;
	system("pause");
}