/*******************************************************************************
**	Program Name:	wcLibrary.hpp
**	Author:			Will Clayton
**	Date:			2017-12-05 - VERSION 1.07
**	Description:	Class declaration file
*******************************************************************************/

#ifndef wcLibrary_H
#define wcLibrary_H

#include <string>
using std::string;

// wcLibrary class declaration
class wcLibrary
{
	private:
		int		getValidInteger(int, int);
	public:
		int 	validInteger(int, int);
		float 	validFloat(float, float);

				wcLibrary();
		void	marquee(string);
		bool	doOrNot(string, string);
		int		getInteger(string, int, int);
		float	getFloat(string, float, float);
		int		randomInt(int, int, int);
		string	getString(string, int);
		string	getStringMinPrompt(string, int);
		int		getChar(string);
		int		newRandomInt(int, int);
		string	appendFileName(string, string);
		string	stringOrDefault(string, int, string);
		string	intAsString(int);
		void	pause(string);
};

#endif
