#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

class Judge
{
	std::string m_SourceFileName;
public:
	Judge()
	{
		m_SourceFileName.assign("result.txt");
	}

	void Verify(const std::string& f1, const std::string& f2);
};
