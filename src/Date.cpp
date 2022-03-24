/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/time/blob/main/LICENSE.txt
*/

#include "Date.hpp"
#include <fmt/core.h>

using namespace std;

namespace Ishiko
{

Date::Date(int year, Month month, unsigned char day)
    : m_date(year, month.number(), day)
{
}

Date::Date(int year, unsigned char month, unsigned char day)
    : m_date(year, month, day)
{
}

Date::Date(const boost::gregorian::date& date)
    : m_date(date)
{
}

int Date::year() const
{
    return m_date.year();
}

Month Date::month() const
{
    return Month(m_date.month());
}

unsigned char Date::day() const
{
    return static_cast<unsigned char>(m_date.day());
}

DayOfWeek Date::dayOfWeek() const
{
    return m_date.day_of_week();
}

string Date::toISO8601String() const
{
    return fmt::format("{:#04d}-{:#02d}-{:#02d}", m_date.year(), m_date.month().as_number(), m_date.day());
}

}
