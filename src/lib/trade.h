#pragma once

#include <string>

#include <boost/date_time/posix_time/posix_time.hpp>

namespace trade
{
class ITrade
{
public:
    virtual ~ITrade() = default;
    virtual double GetValue() const = 0;
    virtual const std::string& ClientSector() const = 0;
    virtual const boost::posix_time::ptime & GetNextPaymentDate() const = 0;
};

class Trade : public ITrade
{
public:
   Trade( const double& value,
          const std::string& clientSector,
          const boost::posix_time::ptime& nextPaymentDate );
   
    double GetValue() const override;
    const std::string& ClientSector() const override;
    const boost::posix_time::ptime& GetNextPaymentDate() const override;

private:
    double m_value;
    std::string m_clientSector;
    boost::posix_time::ptime m_nextPaymentDate;
};

} // namespace trade
