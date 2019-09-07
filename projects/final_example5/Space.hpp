// Class definition - ABSTRACT

#ifndef Space_H
#define Space_H

#include <string>
using std::string;

class Space
{
	protected:
		string	type;
		Space*	top;
		Space*	right;
		Space*	left;
		Space*	bottom;
		string	name;
		string	description;
		string	specialMessage;
		bool	upsideDown;
		bool	showDescription;
	public:
						Space();
				void	updateDescription(string);
				string	getType();
				string	getName();
				string	getDescription();
				void	setMessage(string);
				bool	hasMessage();
				string	getMessage();
				Space*	go(Space*, string);
				void	setNorth(Space*);
				void	setEast(Space*);
				void	setSouth(Space*);
				void	setWest(Space*);
				void	setUpsideDown(bool);
				bool	isUpsideDown();
				void	setShowDescription(bool);
				bool	doShowDescription();
		virtual	string	action(int);
		virtual	string	spacer(int, Space*);
		virtual	string	stringer(int, string);
		virtual			~Space();
};

#endif


