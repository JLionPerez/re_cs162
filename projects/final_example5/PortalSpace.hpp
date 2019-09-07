// Class declaration file

#ifndef PortalSpace_H
#define PortalSpace_H

#include "Space.hpp"

class PortalSpace : public Space
{
	private:
		bool	portalOpen;
		string	closedState, openState;
	public:
				PortalSpace(string, string);
		string	action(int);
		string	stringer(int, string);
		virtual	~PortalSpace();
};

#endif
