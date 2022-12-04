#pragma once

#include "common.h"

namespace Concept02 {

   using FilePtr = std::unique_ptr<FILE, decltype([](FILE* f){ fclose(f); })>;

   enum class OpenMode { normal };

   [[nodiscard]] FilePtr fopen(std::string_view, OpenMode mode) 
   {
      return FilePtr{std::fopen("", "")};
   }


   // struct FooInterface 
   // {
   //    [[nodiscard]] virtual auto func() const -> int = 0;
   // };

   // struct Foo final : public FooInterface
   // {
   //    [[nodiscard]] auto func() const -> int override { return 42; }
   // };

   // ...

   template <typename T>
   concept CFoo = requires(T foo) {
      { foo.func() } -> std::same_as<int>;
   };

   struct Foo {
      [[nodiscard]] auto func () const -> int { return 42; }
   };

   static_assert(CFoo<Foo>);

   auto func(CFoo auto& foo2) {}

   template <CFoo TFoo>
   class Bar {
      public: 
         constexpr Bar(TFoo input)
         : foo(input) {}
      private:
         TFoo foo{};
   };




   void call()
   {
      auto file = fopen("", OpenMode::normal);
      print("concept 02");

      Foo foo{};
      func(foo);

   }
}
