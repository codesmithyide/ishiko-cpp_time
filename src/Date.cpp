/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/time/blob/main/LICENSE.txt
*/

#include "Date.hpp"
#include <fmt/core.h>

namespace Ishiko
{
namespace Time
{

Date::Date(int year, Month month, unsigned char day)
    : m_date(year, month, day)
{
}

int Date::year() const
{
    return m_date.year();
}

Date::Month Date::month() const
{
    return (Month)(m_date.month().as_number());
}

unsigned char Date::day() const
{
    return static_cast<unsigned char>(m_date.day());
}

std::string Date::toISO8601String() const
{
    return fmt::format("{:#04d}-{:#02d}-{:#02d}", m_date.year(), m_date.month().as_number(), m_date.day());
}

}
}