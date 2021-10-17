#pragma once

#include <memory>

#include "trade.h"

namespace trade
{
class ICategory
{
public:
    virtual ~ICategory() = default;

    virtual bool Check(const boost::posix_time::ptime& referenceDate,
                       const trade::ITrade& trade) const = 0;

    virtual std::string GetName() const = 0;
};

class Defaulted : public ICategory
{
public:
    bool Check(const boost::posix_time::ptime& referenceDate,
               const trade::ITrade& trade) const override;
    std::string GetName() const override;
};

class HighRisk : public ICategory
{
public:
    bool Check(const boost::posix_time::ptime& referenceDate,
               const trade::ITrade& trade) const override;
    std::string GetName() const override;
};

class MediumRisk : public ICategory
{
public:
    bool Check(const boost::posix_time::ptime& referenceDate,
               const trade::ITrade& trade) const override;
    std::string GetName() const override;
};

std::shared_ptr<ICategory> findTradeCategory(const boost::posix_time::ptime& referenceDate,
                                             const trade::ITrade& trade);

}
