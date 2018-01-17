//============================================================================
// Name        : TestBb.cpp
// Author      : ThuMinh Nguyen
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
/*#include <cstdlib>
using namespace std;

struct NBA_Team
{
    string name;
    string conference;
    string division;
    unsigned short wins;
    unsigned short losses;
    float pct;
};

int main()
{
    const char filename[] = "C:/Users/MinhThu Nguyen/Desktop/bb.txt";
    char buffer[16], winner[32], loser[32];
    int winnerScore, loserScore;

    ifstream fin(filename);
    if (!fin)
    {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }

    while (!fin.eof())
    {
        // get winner
        fin >> winner;
        if (fin.eof()) break;

        // get next token.  Could be score or 2nd part of winner name
        fin >> buffer;

        // If buffer has a comma, then it's a score
        if (strchr(buffer,','))
        {
            winnerScore = atoi(strtok(buffer,","));
        }
        else
        {
            strcat(winner," ");
            strcat(winner,buffer);
            fin >> buffer;
            winnerScore = atoi(strtok(buffer,","));
        }

        // get loser
        fin >> loser;

        // get next token. Could be score or 2nd part of loser name
        fin >> buffer;

        // If first digit is numeric, then it's a score
        if (isdigit(buffer[0]))
        {
            loserScore = atoi(buffer);
        }
        else
        {
            strcat(loser," ");
            strcat(loser,buffer);
            fin >> buffer;
            loserScore = atoi(buffer);
        }
        cout << winner << " over " << loser << ' ' << winnerScore << " to " << loserScore << endl;
    }
}
*/
