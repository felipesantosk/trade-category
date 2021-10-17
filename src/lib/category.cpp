#include "category.h"

#include <algorithm>
#include <vector>

namespace trade
{

bool Defaulted::Check(const boost::posix_time::ptime& referenceDate,
                      const trade::ITrade& trade) const
{
    boost::posix_time::time_duration dateDiff = trade.GetNextPaymentDate() - referenceDate;

    return (dateDiff < boost::posix_time::hours(-30 * 24));
}

std::string Defaulted::GetName() const
{
    return "DEFAULTED";
}

bool HighRisk::Check(const boost::posix_time::ptime& referenceDate,
                     const trade::ITrade& trade) const
{
    return (trade.GetValue() > 1000000.0) && (trade.GetClientSector() == "Private");
}

std::string HighRisk::GetName() const
{
    return "HIGHRISK";
}

bool MediumRisk::Check(const boost::posix_time::ptime& referenceDate,
                       const trade::ITrade& trade) const
{
    return (trade.GetValue() > 1000000.0) && (trade.GetClientSector() == "Public");
}

std::string MediumRisk::GetName() const
{
    return "MEDIUMRISK";
}

std::shared_ptr<ICategory> findTradeCategory(const boost::posix_time::ptime& referenceDate,
                                             const trade::ITrade& trade)
{
    static const std::vector<std::shared_ptr<ICategory>> categoryByPriority = {
        std::make_shared<Defaulted>(),
        std::make_shared<HighRisk>(),
        std::make_shared<MediumRisk>()
    };

    auto itr = std::find_if(std::cbegin(categoryByPriority),
                            std::end(categoryByPriority),
                            [&referenceDate, &trade](const auto& category) {
                                return category ? category->Check(referenceDate, trade) : false;
                            });

    return (itr != std::cend(categoryByPriority)) ? *itr : nullptr;
}

}
