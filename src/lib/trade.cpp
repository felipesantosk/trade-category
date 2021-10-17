#include "trade.h"

namespace trade
{
   
Trade::Trade(const double& value,
    const std::string& clientSector,
    const boost::posix_time::ptime& nextPaymentDate)
    : ITrade()
    , m_value(value)
    , m_clientSector(clientSector)
    , m_nextPaymentDate(nextPaymentDate)

{
}

double Trade::GetValue() const
{
    return m_value;
}

const std::string& Trade::GetClientSector() const
{
    return m_clientSector;
}

const boost::posix_time::ptime& Trade::GetNextPaymentDate() const
{
    return m_nextPaymentDate;
}

}
