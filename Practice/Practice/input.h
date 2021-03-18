#pragma once

#include <random>
#include <chrono>
#include <iostream>
#include <fstream>

enum class DATA_TYPE
{
	INTEGER,
	UNSIGNED,
	UNSIGNED_LONG_LONG,
	DOUBLE,
	STRING
};

enum class CONTAINER_TYPE
{
	VECTOR
};

class Input
{
private:

	DATA_TYPE m_DataType;
	CONTAINER_TYPE m_ContainerType;
	std::string m_SourceFileName;

	std::random_device m_RandomDevice;
	std::mt19937::result_type m_Seed;

public:

	Input(DATA_TYPE dt, CONTAINER_TYPE ct);
	void Genrate(int lower_bound, int upper_bound, size_t count);
};
