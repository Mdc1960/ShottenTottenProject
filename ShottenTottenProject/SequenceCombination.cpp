#include "SequenceCombination.h"

unsigned int SequenceCombination::playerCombination(std::initializer_list<std::string> list)
{
    return 0;
}

bool SequenceCombination::cardAreSequence(std::initializer_list<unsigned int> list)
{
	std::vector<unsigned int> vect = list;

	std::sort(vect.begin(), vect.end());

	size_t areSequence = 0;

	for (auto it = vect.begin(); it != vect.end() - 1; it++) {
		if (*it + 1 == *(it + 1)) {
			areSequence++;
		}
	}

	return areSequence == list.size() - 1;
}
