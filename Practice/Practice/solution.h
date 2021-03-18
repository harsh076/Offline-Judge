#pragma once

#include <string>

class Solution
{
private:
	std::string m_SourceFileName;

public:
	void Solve();

	Solution()
	{
		m_SourceFileName.assign("solution_output.txt");
	}

	std::string getSorceFileName()
	{
		return m_SourceFileName;
	}
};
