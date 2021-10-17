#pragma once

#include <string>

#include "trade.h"

namespace trade
{
   class ICategory
   {
   public:
      virtual ~ICategory() = default;
      
      virtual bool Check( const trade::ITrade& trade ) const = 0;
      
      virtual std::string GetName() const = 0;
   };
   
   class Defaulted : public ICategory
   {
   public:
      bool Check( const trade::ITrade& trade ) const override;
      std::string GetName() const override;
   };
   
   class HighRisk : public ICategory
   {
   public:
      bool Check( const trade::ITrade& trade ) const override;
      std::string GetName() const override;
   };
   
   class MediumRisk : public ICategory
   {
   public:
      bool Check( const trade::ITrade& trade ) const override;
      std::string GetName() const override;
   };
}
