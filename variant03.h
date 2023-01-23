#pragma once

#include "common.h"

namespace Variant03 
{
   struct KeyValueStore
   {
      bool exists(std::string ident) const
      {
         return m_map.find(ident) != m_map.end();
      }

      template <typename T>
      auto getValue(std::string ident) const -> std::optional<T>
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
      KeyValueStore store{};

      store.store<int>("test1", 4711);
      store.store<bool>("test2", true);
      store.store<std::string>("test3", "hello");

      if (auto opt = store.getValue<bool>("test1"))
      {
         print("Param1 is: {}\n", opt.value());
      } 
      
      if (auto opt = store.getValue<int>("test2"))
      {
         print("Param2 is: {}\n", opt.value());
      } 
      
      if (auto opt = store.getValue<std::string>("test3"))
      {
         print("Param3 is: {}\n", opt.value());
      } 
   }
}
