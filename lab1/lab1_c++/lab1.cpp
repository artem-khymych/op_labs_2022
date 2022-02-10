
#include <iostream>
#include <fstream>
#include<vector>
#include<string>
using namespace std;
void inputFile()
{
	string lines;
	fstream input;
	input.open("inputFile.txt");
	input.clear();
	cout << "enter the program\n";
	while (true)
	{
		getline(cin, lines);
		if (lines.length() == 0) //перевірка на порожній рядок
		{
			input << endl;
			continue;
		}
		if (int(lines[lines.length() - 1]) <= 31)// перевірка: чи являється останній символ рядка керуючим символом
		{

			lines.erase(lines.length() - 1);
			input << lines << endl;
			break;
		}
		input << lines << endl;
	}
	input.close();
}

string find_idents()
{
	string line;
	string identifiers;
	fstream in;
	in.open("inputFile.txt");
	while (!in.eof())
	{
		getline(in, line);
		if (line == "")
		{
			continue;
		}

		if (line.find("==") != -1 || line.find("!=") != -1)
		{
			continue;
		}

		if (line.find("+=") != -1 || line.find("-=") != -1)
		{
			continue;
		}

		if (line.find("/=") != -1 || line.find("*=") != -1)
		{
			continue;
		}
		
		if (line.find("=") != -1)
		{
			identifiers += line.erase(line.find("="), (line.size() - 1)) + "\n";
		}


	}
	in.close();
	return identifiers;
}

void output(string identifiers)
{
	fstream out;
	out.open("outputFile.txt");
	out.clear();
	out << identifiers;
	out.close();
	cout << "output file:"<< endl << identifiers;
}

int main()
{
	string idents;
	inputFile();
	idents=find_idents();
	output(idents);

}
