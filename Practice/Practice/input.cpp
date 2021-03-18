#include "input.h"

Input::Input(DATA_TYPE dt = DATA_TYPE::INTEGER, CONTAINER_TYPE ct = CONTAINER_TYPE::VECTOR)
{
	m_SourceFileName.assign("input.txt");
	m_DataType = dt;
	m_ContainerType = ct;
	m_Seed = m_RandomDevice() ^ (
		(std::mt19937::result_type)
		std::chrono::duration_cast<std::chrono::seconds> (std::chrono::system_clock::now().time_since_epoch()).count() + (std::mt19937::result_type)
		std::chrono::duration_cast<std::chrono::microseconds> (std::chrono::high_resolution_clock::now().time_since_epoch()).count()
		);
}

void Input::Genrate(int lower_bound, int upper_bound, size_t count)
{
	std::mt19937 gen(m_Seed);
	std::uniform_int_distribution<unsigned> distrib(lower_bound, upper_bound);

	std::ofstream inputFile(m_SourceFileName);

	for (size_t i = 0; i < count; ++i)
		inputFile << distrib(gen) << ' ';

	inputFile << '\n';
	inputFile.close();
}
