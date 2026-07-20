/*
    Copyright (c) 2022-2026 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/time/blob/main/LICENSE.txt
*/

#include "TimeOfDay.hpp"
#include <fmt/format.h>

using namespace boost::posix_time;

using namespace Ishiko;

TimeOfDay::TimeOfDay(unsigned char hours, unsigned char minutes, unsigned char seconds)
    : m_timeOfDay(hours, minutes, seconds)
{
}

TimeOfDay::TimeOfDay(time_duration timeOfDay)
    : m_timeOfDay(timeOfDay)
{
}

unsigned char TimeOfDay::hours() const
{
    return m_timeOfDay.hours();
}

unsigned char TimeOfDay::minutes() const
{
    return m_timeOfDay.minutes();
}

unsigned char TimeOfDay::seconds() const
{
    return m_timeOfDay.seconds();
}

bool TimeOfDay::operator==(const TimeOfDay& other) const
{
    return (m_timeOfDay == other.m_timeOfDay);
}

bool TimeOfDay::operator!=(const TimeOfDay& other) const
{
    return (m_timeOfDay != other.m_timeOfDay);
}

bool TimeOfDay::operator<(const TimeOfDay& other) const
{
    return (m_timeOfDay < other.m_timeOfDay);
}

std::string TimeOfDay::toISO8601String() const
{
    return fmt::format("{:#02d}:{:#02d}:{:#02d}", m_timeOfDay.hours(), m_timeOfDay.minutes(), m_timeOfDay.seconds());
}
