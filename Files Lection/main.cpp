#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;

//ofstream examples
//**************************
//Example #1 (simple writing with modes ios::out/ios::app to file)
void basic_writing_example();

//ifstream examples
//**************************
//Example #1 (read all data)
void reading_all_example(); 
//Example #2 (read by word (separator - whitespace character))
void reading_words_example();
//Example #3 (read by character)
void reading_char_example();

//ofstream + ifstream example of copying file
void copy_file_example();

//fstream examples
//**************************
//Example #1 (playing with stream position)
void streampos_writing_example();

int main()
{
	cout << "ofstream example\n*****************************\n";
	cout << "Example #1 (simple writing to file with modes ios::out/ios::app):\n";

	basic_writing_example();
	system("pause");

	cout << "ifstream examples\n*****************************\n";
	cout << "\n\nExample #1 (read all data):\n";

	reading_all_example();
	system("pause");

	cout << "\n\nExample #2 (read by whitespace):\n";

	reading_words_example();
	system("pause");

	cout << "\n\nExample #3 (read by char):\n";

	reading_char_example();
	system("pause");

	cout << "\n\nofstream + ifstream example of copying file\n*****************************\n";

	copy_file_example();
	system("pause");

	cout << "\n\nfstream example (playing with stream position)\n*****************************\n";

	streampos_writing_example();
	system("pause");
}

void copy_file_example()
{
	string file_path_orig, file_path_dest;

	cout << "Original file path: ";
	std::getline(cin, file_path_orig);
	cout << "Destination file path: ";
	std::getline(cin, file_path_dest);

	ifstream orig_fs(file_path_orig, ios::binary);
	ofstream dest_fs(file_path_dest, ios::binary);

	if (orig_fs.is_open())
	{
		if (dest_fs.is_open())
		{
			while (!orig_fs.eof())
				dest_fs.put(orig_fs.get());

			if (dest_fs.good())
				cout << "Data copied successfully!\n";
			else
				cerr << "Write error!\n";

			dest_fs.close();
			orig_fs.close();
		}
		else
		{
			orig_fs.close();
			cerr << "Destination file could not be opened!";
		}
	}
	else
		cerr << "Original file could not be opened!";
}

void reading_char_example()
{
	ifstream fs("myfile.txt");

	if (fs.is_open())
	{
		cout << "File opened successfully!\n";

		cout << "Reading by char:\n";
		while (!fs.eof())
		{
			char c = fs.get();
			cout << c;
		}

		fs.close();
	}
	else
		cerr << "File could not be opened!";
}

void reading_words_example()
{
	ifstream fs("myfile.txt");

	if (fs.is_open())
	{
		cout << "File opened successfully!\n";
		
		cout << "Reading by whitespace:\n";
		while (!fs.eof())
		{
			string word = "";
			fs >> word;
			cout << word << endl;
		}

		fs.close();
 	}
	else
		cerr << "File could not be opened!";
}

void reading_all_example()
{
	ifstream fs("myfile.txt");

	if (fs.is_open())
	{
		cout << "File opened successfully!\n";
		cout << "Reading all data:\n";

		//Calculating count of characters
		fs.seekg(0, ios::end);
		size_t size = fs.tellg();
		fs.seekg(0, ios::beg);

		//Creating a buffer
		char* c = new char[size + 1];

		//Reading
		fs.read(c, size);
		c[size] = '\0';

		cout << c << endl;

		delete[] c;
		fs.close();
	}
	else
		cerr << "File could not be opened!";
}

void streampos_writing_example()
{
	fstream fs("myfile.txt", ios::out | ios::in);
	string data = "{-><-}";

	if (fs.is_open())
	{
		cout << "File opened successfully!\n";
		//Calculating count of characters
		fs.seekp(0, ios::beg);
		auto pos = fs.tellp();
		fs.seekp(0, ios::end);
		auto length = fs.tellp() - pos;
		cout << "Count of characters in file: " << length << endl;

		fs.seekp(-length / 2, ios::end);
		fs << data;

		if (fs.good())
			cout << "Data is written to the middle of the file!\n";
		else
			cerr << "Write error!\n";
		fs.close();
	}
	else
		cerr << "File could not be opened!";
}

void basic_writing_example()
{
	//ofstream fs("myfile.txt", ios::app) - для додавання
	ofstream fs("myfile.txt");
	string data = "This is a test string";

	if (fs.is_open())
	{
		cout << "File opened successfully!\n";
		//fs.write(data.c_str(), data.size());
		fs << data;
		//fs.put('!');
		fs << "!";	
		if (fs.good())
			cout << "Data written successfully!\n";
		else
			cerr << "Write error!\n";
		fs.close();
	}
	else
		cerr << "File could not be opened!";
}