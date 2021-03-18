#include "judge.h"

void Judge::Verify(const std::string& f1, const std::string& f2)
{
	unsigned line_number = 0;

	std::ifstream file1, file2;
	std::ofstream resultFile(m_SourceFileName, std::ios::app);

	if (file1.is_open())
		file1.close();

	if (file2.is_open())
		file2.close();

	file1.open(f1, std::ios::binary);
	file2.open(f2, std::ios::binary);
	//---------- compare number of lines in both files ------------------
	int c1, c2;
	c1 = 0; c2 = 0;
	std::string str;
	while (!file1.eof())
	{
		getline(file1, str);
		c1++;
	}
	file1.clear();   //  sets a new value for the error control state
	file1.seekg(0, std::ios::beg);
	while (!file2.eof())
	{
		getline(file2, str);
		c2++;
	}
	file2.clear();
	file2.seekg(0, std::ios::beg);

	if (c1 != c2)
	{
		resultFile << "Different number of lines in files!" << "\n";
		resultFile << "file1 has " << c1 << " lines and file2 has " << c2 << " lines" << "\n";
	}
	//---------- compare two files line by line ------------------
	char string1[256], string2[256];
	int j = 0;
	while (!file1.eof())
	{
		file1.getline(string1, 256);
		file2.getline(string2, 256);
		j++;
		if (strcmp(string1, string2) != 0)
		{
			resultFile << "Incorrect answer\n";
			resultFile << "diff at line :" << j << "\n";
			resultFile << "   " << string1 << "\n";
			resultFile << "   " << string2 << "\n";
			return;
		}
	}
	resultFile << "Correct answer\n";

	resultFile.close();
}