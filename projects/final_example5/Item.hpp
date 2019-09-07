// Class definition

#ifndef Item_H
#define Item_H

#include "Space.hpp"

#include <string>
using std::string;

class Item
{
	private:
		string	name;
		string	word;
		Space*	location;
		Space*	portalLocation;
	public:
				Item(string, string);
		string	getName();
		string	getWord();
		void	setLocation(Space*);
		Space*	getLocation();
		void	setPortalLocation(Space*);
		Space*	getPortalLocation();
};

#endif


