#include <chrono>
#include <random>

#include "timer.h"
#include "input.h"

#include "answer.h"
#include "solution.h"
#include "judge.h"

using namespace std;

int main()
{
	//Genrate Input
	DATA_TYPE dataType = DATA_TYPE::INTEGER;
	CONTAINER_TYPE containerType = CONTAINER_TYPE::VECTOR;
	
	Input input(dataType, containerType);

	int lowerBound = 30;
	int upperBound = 60;
	size_t count = 100;
	
	input.Genrate(lowerBound, upperBound, count);

	Solution s;
	{
		Timer timer("Solution");
		s.Solve();
	}

	Answer a;
	{
		Timer timer("Answer");
		a.Solve();
	}

	Judge j;
	j.Verify(s.getSorceFileName(), a.getSorceFileName());
}
