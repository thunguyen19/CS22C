
#include "Haiku.h"
#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;


/**Default Constructor*/
Haiku::Haiku(): title(""), author(""), haiku(""), country(""), year(0){};

/**Constructor*/
Haiku::Haiku(string t, string a, string h, string c, int y){
	title = t;
	author = a;
	haiku = h;
	country = c;
	year = y;
}

/**Access Functions*/
string Haiku::get_title()
{
	return title;
}

string Haiku::get_author()
{
	return author;
}

string Haiku::get_haiku()
{
	return haiku;
}

string Haiku::get_country()
{
	return country;
}

int Haiku::get_year()
{
	return year;
}

/**Manipulation Procedures*/
void Haiku::set_title(string t)
{
	title = t;
}

void Haiku::set_author(string a)
{
	author = a;
}

void Haiku::set_haiku(string h)
{
	haiku = h;
}

void Haiku::set_country(string c)
{
	country = c;
}

void Haiku::set_year(int y)
{
	//simple input validation
	if (y < 0)
	{
		year = abs(y);
	}
	else if (y > 2017)
	{
		year = 0;
	}
	else
		year = y;
}

bool Haiku::operator==(Haiku& h) {
    return (title == h.title && author==h.author && haiku == h.haiku && country == h.country && year == h.year);
}
