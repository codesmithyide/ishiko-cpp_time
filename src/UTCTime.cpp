/*
    Copyright (c) 2022-2026 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/time/blob/main/LICENSE.txt
*/

#include "UTCTime.hpp"
#include "SystemTime.hpp"
#include <fmt/format.h>

using namespace std;

namespace Ishiko
{
    
UTCTime::UTCTime(const Date& date, const TimeOfDay& timeOfDay)
    : m_date(date), m_timeOfDay(timeOfDay)
{
}

UTCTime UTCTime::Now()
{
    return SystemTime::Now().toUTCTime();
}

string UTCTime::toRFC7231String() const
{
    return fmt::format("{:s}, {:#02d} {:s} {:#04d} {:#02d}:{:#02d}:{:#02d} GMT", m_date.dayOfWeek().toShortString(),
        m_date.day(), m_date.month().toShortString(), m_date.year(), m_timeOfDay.hours(), m_timeOfDay.minutes(),
        m_timeOfDay.seconds());
}

}
