#pragma once

#include "common.h"

namespace Variant03 
{
   struct Manager
   {
      bool exists(std::string ident) const
      {
         return m_map.find(ident) != m_map.end();
      }

      template <typename T>
      std::optional<T> getValue(std::string ident) const
      {
         if (!exists(ident))
         {
            return std::nullopt; 
         }

         const auto& variant{ m_map.at(ident) };

         if (!std::holds_alternative<T>(variant))
         {
            return std::nullopt; 
         }

         return std::get<T>(variant);
      }

      template <typename T>
      void store(std::string ident, T value)
      {
         m_map[ident] = value;
      }


   private:
      using Parameter = std::variant<bool, int, std::string>;
      std::unordered_map<std::string, Parameter> m_map {{
         {"param1", true},
         {"param2", 3210},
         {"param4", "value"},
      }};
   };


   void call()
   {
      Manager manager{};

      manager.store<int>("test1", 4711);
      manager.store<bool>("test2", true);
      manager.store<std::string>("test3", "hello");

      if (auto opt = manager.getValue<bool>("test1"))
      {
         print("Param1 is: {}\n", opt.value());
      } 
      
      if (auto opt = manager.getValue<int>("test2"))
      {
         print("Param2 is: {}\n", opt.value());
      } 
      
      if (auto opt = manager.getValue<std::string>("test3"))
      {
         print("Param3 is: {}\n", opt.value());
      } 
      
      // else
      // {
      //    print("No Param1\n");
      // }      
   }
}
