/****
 * Class Uptime.
 *
 * This class provides various way of streaming the system uptime:
 * - short: 
 *		288:12:30
 * - normal: 
 * 		12 days, 4 hours, 12 minutes, 30 seconds
 * - long:
 *		The system has been running for:
 *		- 12 days
 *      - 4 hours
 *      - 12 minutes
 *      - 30 seconds
 *
 * When instantiated with no parameters, the normal mode will be
 * assumed. Use SetViewType() to change this.
 *
 * An Uptime object has no public get-methods to access the time. Time
 * can only be accessed by streaming the object. At that moment, the
 * internal counter is reset, and the time is printed.
 * 
 * File  : Uptime.h
 *
 * Author: Vincent Oostindie
 * Date  : 27-04-2000
 ****/

#ifndef _Uptime_H
#define _Uptime_H

#include <iostream>
#include <iomanip>

class Uptime
{
public:
	friend ostream& operator<<(ostream &o, Uptime u);
	enum ViewType {VIEW_SHORT, VIEW_NORMAL, VIEW_LONG}; // viewmodes

private:
	int m_Uptime;        // internal counter
	ViewType m_ViewType; // viewmode: short, normal or long

	// Stream a number and a noun. Noun is plural if number > 1
	void Stream(ostream &o, int i, char * noun, 
		char * pre = "", char * post = "") const;

	// Divide internal counter by n, and replace it with modulus n
	int Divide(int n);
				
	// Get methods, all private. They update the internal counter.
	int GetMilliseconds();
	int GetDays();
	int GetHours();
	int GetMinutes();
	int GetSeconds();

public:
	Uptime(ViewType view_type = VIEW_NORMAL); // constructor
	virtual ~Uptime(); // destructor
	
	// Change the viewtype
	inline void SetViewType(const ViewType view_type) {m_ViewType = view_type;};
};

// operator<< for uptime object
inline ostream& operator<<(ostream& o, Uptime u)
{
	int hours;
	// Stream the right kind of information
	switch (u.m_ViewType) {
		case Uptime::VIEW_SHORT:
			hours = u.GetDays() * 24 + u.GetHours();
			o << setw(2) << setfill('0') << hours << ':';
			o << setw(2) << setfill('0') << u.GetMinutes() << ':';
			o << setw(2) << setfill('0') << u.GetSeconds();
			break;
		case Uptime::VIEW_NORMAL:
			u.Stream(o, u.GetDays(), "day", "", ", ");
			u.Stream(o, u.GetHours(), "hour", "", ", ");
			u.Stream(o, u.GetMinutes(), "minute", "", ", ");
			u.Stream(o, u.GetSeconds(), "second");
			break;
		case Uptime::VIEW_LONG:
			o << "The system has been running for:\n";
			u.Stream(o, u.GetDays(), "day", "- ", "\n");
			u.Stream(o, u.GetHours(), "hour", "- ", "\n");
			u.Stream(o, u.GetMinutes(), "minute", "- ", "\n");
			u.Stream(o, u.GetSeconds(), "second", "- ", "\n");
			break;
	}
	return o;
}

#endif // _Uptime_H

// END OF FILE