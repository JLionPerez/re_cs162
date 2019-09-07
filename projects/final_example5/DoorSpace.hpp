// Class declaration file

#ifndef DoorSpace_H
#define DoorSpace_H

#include "Space.hpp"

class DoorSpace : public Space
{
	private:
			bool	holdLock;
			Space*	lockEastLocation;
			Space*	lockWestLocation;
	public:
						DoorSpace(string, string);
		virtual	string	action(int);
		virtual	string	spacer(int, Space*);
};

#endif
