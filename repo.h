#pragma once

#include "common.h"

namespace cpp20 
{
   //  template <typename... Ts>
   //  struct overload : Ts... {
   //      using Ts::operator()...;
   //  };



   struct Section1 // std::ranges
   {
      std::string label{"std::ranges"};
   };

   struct Section2 // std::format
   {
      std::string label{"std::format"};
   };

   using Section = std::variant<
      Section1, Section2
   >;

   struct Repository {

      void printContentList() const
      {
         for (auto&& area : m_area)
         {
            std::visit([](auto&& s){ print("{}\n", s.label); }, area);
         }
         
      }

   private:
      std::vector<Section> m_area{{
         Section1{}, Section2{}
      }};
   };
}
