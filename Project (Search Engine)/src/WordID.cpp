/**
 * ThuMinh Nguyen
 * CIS 22C
 * FileName
 */

#include "WordID.h"


WordID::WordID(string w, int i)
{
	word = w;
	id = i;
}

string WordID::getWord(){return word;};

int WordID::getId(){return id;};
