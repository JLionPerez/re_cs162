// Class declaration file

#ifndef LightSpace_H
#define LightSpace_H

#include "Space.hpp"

class LightSpace : public Space
{
	public:
				LightSpace(string, string);
		string	action(int);
};

#endif
