/****
 * Class Uptime implementation.
 *
 * See Uptime.h for global class details.
 *
 * File  : Uptime.cpp
 *
 * Author: Vincent Oostindie
 * Date  : 27-04-2000
 ****/

#include "windows.h" // for GetTickCount()
#include "Uptime.h"

// (Empty) constructor
Uptime::Uptime(ViewType view_type = VIEW_NORMAL) : 
	m_ViewType(view_type), m_Uptime(0) { }

// (Empty) destructor
Uptime::~Uptime() { }

// Divide the uptime by n, and replace uptime with uptime modulo n
inline int Uptime::Divide(int n)
{
	int i = m_Uptime / n;
	m_Uptime %= n;
	return i;
}

// Return the number of milliseconds the system is running
inline int Uptime::GetMilliseconds()
{
	return GetTickCount();
}

// Get the number of days and subtract them from the internal counter
inline int Uptime::GetDays()
{
	// reset the internal counter
	m_Uptime = GetMilliseconds();
	return Divide(86400000); // milliseconds per day
}

// Get the number of hours and subtract them from the internal counter
inline int Uptime::GetHours()
{
	return Divide(3600000); // milliseconds per hour
}

// Get the number of minutes and subtract them from the internal counter
inline int Uptime::GetMinutes()
{
	return Divide(60000); // milliseconds per minute
}

// Get the number of seconds and subtract them from the internal counter
inline int Uptime::GetSeconds()
{
	return Divide(1000); // milliseconds per second
}

// Stream a prefix, a number, a noun and a postfix. Noun is plural if i > 1
inline void Uptime::Stream(ostream &o, int i, char * noun, 
	char * pre = "", char * post = "") const
{
	if (i > 0) {
		o << pre << i << ' ' << noun;
		if (i > 1) o << 's';
		o << post;
	}
}

// END OF FILE