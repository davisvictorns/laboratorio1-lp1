#include "Date.h"

Date::Date(const int &d, const int &m, const int &y)
{
    day_ = d;
    month_ = m;
    year_ = y;
};

Date::Date()
{
    year_ = 0;
    month_ = 0;
    day_ = 0;
};

int Date::day() const { return day_; };
int Date::month() const { return month_; };
int Date::year() const { return year_; };

void Date::set_day(const int &day) { Date::day_ = day; };
void Date::set_month(const int &month) { Date::month_ = month; };
void Date::set_year(const int &year) { Date::year_ = year; };

bool Date::validate() const
{
    // This function will check the given date is valid or not.
    // If the date is not valid then it will return the value false.
    // Need some more checks on the year, though
    if (year_ < 0)
        return false;
    if (month_ > 12 || month_ < 1)
        return false;
    if (day_ > 31 || day_ < 1)
        return false;
    if ((day_ == 31 &&
         (month_ == 2 || month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)))
        return false;
    if (day_ == 30 && month_ == 2)
        return false;
    if (year_ < 2000)
    {
        if ((day_ == 29 && month_ == 2) && !((year_ - 1900) % 4 == 0))
            return false;
    };
    if (year_ > 2000)
    {
        if ((day_ == 29 && month_ == 2) && !((year_ - 2000) % 4 == 0))
            return false;
    };
    return true;
};

bool operator==(const Date &date1, const Date &date2)
{
    if (date1.day() == date2.day() && date1.month() == date2.month())
    {
        return true;
    }
    return false;
}

bool operator!=(const Date &date1, const Date &date2)
{
    return !(date1 == date2);
}

bool operator<(const Date &date1, const Date &date2)
{
    if (date1.year() < date2.year())
    {
        return true;
    }
    else if (date1.year() > date2.year())
    {
        return false;
    }
    else
    {
        if (date1.month() < date2.month())
        {
            return true;
        }
        else if (date1.month() > date2.month())
        {
            return false;
        }
        else
        {
            if (date1.day() < date2.day())
            {
                return true;
            }
            else if (date1.day() > date2.day())
            {
                return false;
            }
            else
            {
                return false;
            }
        }
    }

    return false;
}

bool operator>(const Date &date1, const Date &date2)
{
    if (date1 == date2)
    {
        return false;
    }
    else if (date1 < date2)
    {
        return false;
    }

    return true;
}

bool operator<=(const Date &date1, const Date &date2)
{
    if (date1 == date2)
    {
        return true;
    }

    return (date1 < date2);
}

bool operator>=(const Date &date1, const Date &date2)
{
    if (date1 == date2)
    {
        return true;
    }

    return (date1 > date2);
}

int date_days(const Date &d)
{
    if (d.validate())
    {
        return d.year()*365 + d.month()*30 + d.day();
    };
    return 0;
};

ostream &operator<<(ostream &os, const Date &d)
{
    if (d.validate())
    {
        os << d.day() << "/" << d.month() << "/" << d.year();
    }
    else
    {
        os << " invalid date ";
    };
    return os;
}

int operator-(const Date &date1, const Date &date2)
{
    if (date1 == date2)
    {
        return 0;
    }

    int days_d1 = date_days(date1);
    int days_d2 = date_days(date2);

    int date_diff = days_d1 - days_d2;

    return date_diff;
}


// Some credits to: http://finance.bi.no/~bernt/gcc_prog/empirical/doc_date.pdf