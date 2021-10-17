#include "category.h"

namespace trade
{
   bool Defaulted::Check( const trade::ITrade& trade ) const
   {
      return false;
   }
   
   std::string Defaulted::GetName() const
   {
      return "DEFAULTED";
   }
}
