#pragma once

#include <string>

class Answer
{
private:
	std::string m_SourceFileName;

public:
	void Solve();

	Answer()
	{
		m_SourceFileName.assign("answer_output.txt");
	}

	std::string getSorceFileName()
	{
		return m_SourceFileName;
	}
};
