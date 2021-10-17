#pragma once

#include <memory>

#include "trade.h"

namespace trade
{
//! \class ICategory
//! \brief Interface for category types
class ICategory
{
public:
    virtual ~ICategory() = default;

    //! \brief Check if the trade is from this category,
    //! \param referenceDate Reference date
    //! \param trade Trade for verification
    //! \return Returns true if is trade category otherwise false
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

//! \brief Find trade category
//! \param referenceDate Reference date
//! \param trade Trade for verification
//! \return If found a trade category it returns a ICategory pointer otherwise returns a nullptr
std::shared_ptr<ICategory> findTradeCategory(const boost::posix_time::ptime& referenceDate,
                                             const trade::ITrade& trade);

}
