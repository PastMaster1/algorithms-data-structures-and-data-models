#include <UtilityFunctions.hpp>

bool CompareStrings(const char* s1, const char* s2)
{
	bool f = true;
	while (*s1 != '\0' && *s2 != '\0' && f)
	{
		f = (*s1 == *s2);
		s1++;
		s2++;
	}
	if (f)
	{
		f = (*s1 == *s2);
	}
	return f;
}