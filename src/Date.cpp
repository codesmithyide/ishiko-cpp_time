/*
    Copyright (c) 2021-2026 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/time/blob/main/LICENSE.txt
*/

#include "Date.hpp"
#include <fmt/format.h>

using namespace Ishiko;

Date::Date(unsigned short year, Month month, unsigned char day)
    : m_date{year, month.number(), day}
{
}

Date::Date(unsigned short year, unsigned char month, unsigned char day)
    : m_date{year, month, day}
{
}

Date::Date(boost::gregorian::date date)
    : m_date{date}
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

bool Date::operator==(Date other) const
{
    return (m_date == other.m_date);
}

bool Date::operator!=(Date other) const
{
    return (m_date != other.m_date);
}

bool Date::operator<(Date other) const
{
    return (m_date < other.m_date);
}

bool Date::operator<=(Date other) const
{
    return (m_date <= other.m_date);
}

bool Date::operator>(Date other) const
{
    return (m_date > other.m_date);
}

bool Date::operator>=(Date other) const
{
    return (m_date >= other.m_date);
}

std::string Date::toISO8601String() const
{
    return fmt::format("{:#04d}-{:#02d}-{:#02d}", (boost::gregorian::greg_year::value_type)m_date.year(),
        m_date.month().as_number(), (boost::gregorian::greg_day::value_type)m_date.day());
}

boost::gregorian::date Date::toBoostDate() const
{
    return m_date;
}

Date Date::yesterday() const
{
    boost::gregorian::date result{m_date};
    result -= boost::gregorian::days(1);
    return result;
}
