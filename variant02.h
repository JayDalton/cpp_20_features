
#pragma once

#include "common.h"

namespace Variant02 
{
   struct BoolParameter
   {
      bool value{};
   };

   struct UIntParameter
   {
      std::uint32_t value{};
   };

   struct FloatParameter
   {
      float value{};
   };

   struct StringParameter
   {
      std::string value{};
   };

   using Parameter = std::variant<
      BoolParameter,
      UIntParameter,
      FloatParameter,
      StringParameter
   >;

   using BoolOpt = std::optional<bool>;
   using UIntOpt = std::optional<std::uint32_t>;
   using FloatOpt = std::optional<float>;
   using StringOpt = std::optional<std::string>;

   // // helper type for the visitor #4
   // template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
   // // explicit deduction guide (not needed as of C++20)
   // template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

   struct Manager
   {
      BoolOpt getBool(std::string ident) const 
      { 
         if (contains(ident) && std::holds_alternative<BoolParameter>(m_map.at(ident)))
         {
            return std::get<BoolParameter>(m_map.at(ident)).value;
         }
         return std::nullopt; 
      };

      StringOpt getString(std::string ident) const 
      { 
          if (contains(ident) && std::holds_alternative<StringParameter>(m_map.at(ident)))
          {
            return std::get<StringParameter>(m_map.at(ident)).value;
          }
          return std::nullopt; 
      };

      FloatOpt getFloat(std::string ident) const 
      { 
          if (contains(ident) && std::holds_alternative<FloatParameter>(m_map.at(ident)))
          {
            return std::get<FloatParameter>(m_map.at(ident)).value;
          }
          return std::nullopt; 
      };

      bool contains(std::string ident) const 
      {
         auto found = m_map.find(ident);
         return (found != m_map.end());
      }

   private:
      std::unordered_map<std::string, Parameter> m_map {{
         {"param1", BoolParameter{true}},
         {"param2", UIntParameter{3210}},
         {"param3", FloatParameter{1.23f}},
         {"param4", StringParameter{"value"}},
      }};
   };

   void call()
   {
      Manager manager{};

      if (auto var1 = manager.getBool("param1"))
      {
         print("Param1 is: {}\n", var1.value());
      } 
      else
      {
         print("No Param1\n");
      }
      
      if (auto var1 = manager.getString("param4"))
      {
         print("Param4 is: {}\n", var1.value());
      } 
      else
      {
         print("No Param4\n");
      }
      
      if (auto var1 = manager.getFloat("param3"))
      {
         print("Param3 is: {}\n", var1.value());
      } 
      else
      {
         print("No Param3\n");
      }
      
      if (auto var1 = manager.getString("paramX"))
      {
         print("ParamX is: {}\n", var1.value());
      } 
      else
      {
         print("No ParamX\n");
      }
      
   }
}
