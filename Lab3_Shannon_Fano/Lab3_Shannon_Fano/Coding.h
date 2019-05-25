#pragma once
#include"List.h"
#include"Map.h"
#include <string>
using namespace std;

struct symbol
{
	char s;
	int freq;
};
Map<char, int> Frequencies(string string)
{
	Map<char, int> Map;
	for (string::iterator it = string.begin(); it != string.end(); it++)
	{
		if (Map.find(*it) == nullptr)
		{
			Map.insert(*it, 1);
		}
		else
		{
			Map.find(*it)->data++;
		}

	}
	cout << "Table of Frequencies" << endl;
	cout << Map.get_keys() << endl;
	cout << Map.get_values() << endl;
	return Map;
};
//recursive deviding of the list o(n^2)?
void Recursive_dividing(const List<symbol> &list, Map<char, string>*map, int initial_sum)
{
	int left_sum = 0;
	int right_sum = 0;
	List<symbol> left_list;
	List<symbol> right_list = list;
	Node<symbol>* temp = right_list.head;
	while (left_sum < initial_sum / 2 && temp)
	{
		map->find(temp->data.s)->data.push_back('0');
		left_sum = left_sum + temp->data.freq;
		left_list.push_back(temp->data);
		temp = temp->next;
		right_list.pop_front();
	}
	temp = right_list.head;
	while (temp)
	{
		map->find(temp->data.s)->data.push_back('1');
		temp = temp->next;
	}
	right_sum = initial_sum - left_sum;
	if (left_list.get_size() >= 2)
		Recursive_dividing(left_list, map, left_sum);

	if (right_list.get_size() >= 2)
		Recursive_dividing(right_list, map, right_sum);
};

//Returns Map of codes
Map <char, string> Codingiguess(Map<char, int> HMap)
{
	List<symbol> List_of_frequencies;
	List<char>chars = HMap.get_keys();
	List<int> freq = HMap.get_values();
	Node<int>*temp2 = freq.head;
	int sum = 0;
	for (Node<char>* temp1 = chars.head; temp1; temp1 = temp1->next) //making a list (symbol-freq)
	{
		symbol symbol1;
		symbol1.s = temp1->data;
		symbol1.freq = temp2->data;
		sum = sum + temp2->data;
		List_of_frequencies.push_back(symbol1);
		temp2 = temp2->next;
	}

	//sorting
	int i = 0;
	while (i < List_of_frequencies.get_size())
	{
		for (Node <symbol>* Tempr = List_of_frequencies.head; Tempr->next; Tempr = Tempr->next)
		{
			if (Tempr->data.freq < Tempr->next->data.freq)
			{
				symbol temp = Tempr->data;
				Tempr->data = Tempr->next->data;
				Tempr->next->data = temp;
			}
		}
		i++;
	}

	Map<char, string> ShF;
	for (Node<symbol>* temp = List_of_frequencies.head; temp; temp = temp->next)
		ShF.insert(temp->data.s, "");

	Recursive_dividing(List_of_frequencies, &ShF, sum);


	cout << ShF.get_keys() << endl;
	cout << ShF.get_values() << endl;
	return ShF;
};

//reurns coded string O(n)
string incoding(Map<char, string> CodeMap, string Hstring)
{
	string Coded;
	int i = 0;
	for (string::iterator it = Hstring.begin(); it != Hstring.end(); it++)
	{
		Coded.insert(i, CodeMap.find(*it)->data);
		i += CodeMap.find(*it)->data.size();
	}
	return Coded;
};
//returns decoded string
string decode(Map <char, string> CodeMap, string Hstring)
{
	string decoded_str;
	string finder;
	Map<string, char>DecodeMap;
	List<char>chars = CodeMap.get_keys();
	List<string>codes = CodeMap.get_values();
	Node<char>*chartemp = chars.head;
	Node<string>*codetemp = codes.head;
	while (chartemp)//making a new tree which has codes as keyes
	{
		DecodeMap.insert(codetemp->data, chartemp->data);
		codetemp = codetemp->next;
		chartemp = chartemp->next;
	}
	std::string::iterator symb = Hstring.begin();
	for (symb ;symb != Hstring.end(); symb++)
	{
		finder.push_back(*symb);
		if (DecodeMap.find(finder))
		{
			decoded_str.push_back(DecodeMap.find(finder)->data);
			finder.resize(0);
		}
	}
	return decoded_str;
}