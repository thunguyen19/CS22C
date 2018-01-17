/**
 * ThuMinh Nguyen
 * CIS 22C
 * FileName
 */
#ifndef HAIKU_H_
#define HAIKU_H_

#include <string>
using namespace std;

class Haiku {
private:
    string title;
    string author;
    string haiku;
    string country;
    int year;
public:

    /**Constructors*/
    Haiku();
    Haiku(string t, string a, string h, string c, int y);

    /**Access Functions*/
    string get_title();
    string get_author();
    string get_haiku();
    string get_country();
    int get_year();

    /**Manipulation Procedures*/
    void set_title(string t);
    void set_author(string a);
    void set_haiku(string h);
    void set_country(string c);
    void set_year(int y);

    /**Additional Functions*/
    bool operator==(Haiku& h);

};


#endif /* HAIKU_H_ */

