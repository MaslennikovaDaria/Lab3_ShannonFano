#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Àíäðåé\Desktop\Lab3_Shannon_Fano\Lab3_Shannon_Fano\Coding.h"
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(FrequenciesMapSize)
		{
			string Test = "abbcdd";
			Frequencies(Test);
			Assert::AreEqual(4, Frequencies(Test).get_size());
		}

		TEST_METHOD(Codingiguess3symbolsSize)
		{
			string Test = "аббв";
			Frequencies(Test);
			Codingiguess(Frequencies(Test));
			Assert::AreEqual(3, Codingiguess(Frequencies(Test)).get_size());
		}
		TEST_METHOD(Incoding3symbols)
		{
			string Help = "1000011";
			string Test = "аббв";
			Frequencies(Test);
			Codingiguess(Frequencies(Test));
			Assert::AreEqual(Help, incoding(Codingiguess(Frequencies(Test)),Test));
		}
		TEST_METHOD(CodingiuessCode)
		{
			string Help = "0";
			string Test = "аббв";
			Frequencies(Test);
			Codingiguess(Frequencies(Test));
			string data = Codingiguess(Frequencies(Test)).find('á')->data;
			Assert::AreEqual(Help, data);
		}
		TEST_METHOD(Freq)
		{
			string Test = "аббв";
			Frequencies(Test);
			Assert::AreEqual(3, Frequencies(Test).find('б')->data);
		}
		TEST_METHOD(Decode)
		{
			Map <char, string> chars_to_codes;
			string incoded_quote;
			string quote="ехал грека";
			string decoded_quote;
			getline(cin, quote);
			chars_to_codes = Codingiguess(Frequencies(quote));
			incoded_quote = incoding(chars_to_codes, quote);
			decoded_quote = decode(chars_to_codes, incoded_quote);
			Assert::AreEqual(quote, decoded_quote);
		}
		
	};
}
