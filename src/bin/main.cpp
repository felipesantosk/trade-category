
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "category.h"

boost::posix_time::ptime str_to_ptime(const std::string& str);
trade::Trade readTrade();
std::pair<boost::posix_time::ptime, std::vector<trade::Trade>> readArgs();

int main()
{
    const auto [referenceDate, trades] = readArgs();

    for (const auto& trade : trades)
    {
        const auto tradeCategory = trade::findTradeCategory(referenceDate, trade);

        if (tradeCategory)
        {
            std::cout << tradeCategory->GetName() << std::endl;
        }
        else
        {
           std::cout << "UNKNOWN" << std::endl;
        }
    }

    return 0;
}

std::pair<boost::posix_time::ptime, std::vector<trade::Trade>> readArgs()
{
    std::string refDateStr;
    int tradesNum = 0;

    std::cin >> refDateStr;
    std::cin >> tradesNum;

    std::vector<trade::Trade> trades;

    for (int i = 0; i < tradesNum; ++i)
    {
        trades.push_back(readTrade());
    }

    return { str_to_ptime(refDateStr), trades };
}

boost::posix_time::ptime str_to_ptime(const std::string& str)
{
    static std::locale dateLocale(std::locale::classic(),
                                  new boost::posix_time::time_input_facet("%m/%d/%Y"));
    std::istringstream iss(str);
    iss.imbue(dateLocale);

    boost::posix_time::ptime ptime;
    iss >> ptime;

    return ptime;
}

trade::Trade readTrade()
{
    double value = 0.0;
    std::string clientSector;
    std::string dateStr;

    std::cin >> value;
    std::cin >> clientSector;
    std::cin >> dateStr;

    return { value, clientSector, str_to_ptime(dateStr) };
}
