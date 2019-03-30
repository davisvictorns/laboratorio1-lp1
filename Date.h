#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
using namespace std;

class Date{
    protected:
        int day_;
        int month_;
        int year_;
    public:
        Date();
        Date(const int& d, const int& m, const int& y);

        bool validate(void) const;

        int day() const;
        int month() const;
        int year() const;

        void set_day(const int& day);
        void set_month(const int& month);
        void set_year(const int& year);
};

bool operator == (const Date&, const Date&);
bool operator != (const Date&, const Date&);
bool operator < (const Date&, const Date&);
bool operator > (const Date&, const Date&);
bool operator <= (const Date&, const Date&);
bool operator >= (const Date&, const Date&);
int operator - (const Date&, const Date&);

ostream& operator << (ostream& os, const Date& d);

#endif
