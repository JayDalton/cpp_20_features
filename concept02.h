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
      // { foo.func() } -> std::same_as<int>;
      { foo.func() } -> std::integral;
   };

   struct Foo {
      [[nodiscard]] auto func () const -> std::int16_t { return 42; }
   };

   struct Foo1 {
      [[nodiscard]] auto func () const -> std::int32_t { return 42; }
   };

   struct Foo2 {
      [[nodiscard]] auto func () const -> std::int64_t { return 42; }
   };

   static_assert(CFoo<Foo>);
   static_assert(CFoo<Foo1>);
   static_assert(CFoo<Foo2>);

   auto func(CFoo auto& foo2) -> void {}

   // template <CFoo TFoo>
   // class Bar {
   //    public: 
   //       constexpr Bar(TFoo input)
   //       : foo(input) {}
   //    private:
   //       TFoo foo{};
   // };

   template<typename T, typename... Ts>
   concept same_as_any = (... or std::same_as<T, Ts>);

   template <CFoo... TFoos>
   class Bar {
      public: 
         constexpr Bar(same_as_any<TFoos...> auto input)
         : foo(input) {}

         constexpr auto set_foo(same_as_any<TFoos...> auto input) -> void 
         {
            foo = input;
         }

      private:
         std::variant<TFoos...> foo{};
   };

   template<CFoo... TFoos>
   class Baz 
   {
   public:
      template<typename T>
      auto store(T value) -> void {
         return std::get<std::vector<T>>(data).push_back(value);
      }
   private:
      std::tuple<std::vector<TFoos>...> data{};
   };


   template<typename T>
   concept CDevice = requires(T device) {
      { T::find_in_env() } -> std::same_as<std::vector<T>>;
      { device.update() } -> std::same_as<void>;
   };

   struct Switch {
      [[nodiscard]] static auto find_in_env() -> std::vector<Switch>
      {
         return {{},{},{}};
      }
      auto update() -> void { }
   private:
      bool is_on{false};   
   };

   struct Dimmer {
      [[nodiscard]] static auto find_in_env() -> std::vector<Dimmer>
      {
         return {{}, {}};
      }
      auto update() -> void { }
   private:
      std::uint8_t brightness{0};   
   };

   template<CDevice... TDevices>
   struct DeviceManager
   {
      DeviceManager() : devices(get_devices()) {}

      auto update() -> void {
         std::apply(
            [this](auto &... device_list) {
               (update_device(device_list), ...);
            }, devices);
      }
   private:
      using ListType = std::tuple<std::vector<TDevices>...>;

      auto update_device(auto& device_list) -> void {
         for (auto& device : device_list) {
            device.update();
         }
      }

      [[nodiscard]] 
      static auto get_devices() -> ListType {
         return std::tuple{TDevices::find_in_env()...};
      }

      ListType devices{};
   };

   void call()
   {
      auto file = fopen("", OpenMode::normal);
      print("concept 02");

      Foo foo{};
      func(foo);

      Bar<Foo> bar_1{Foo{}};
      Bar<Foo1, Foo2> bar_2{Foo1{}};

      Baz<Foo1, Foo2> repo;
      repo.store(Foo2{});
      repo.store(Foo1{});

      DeviceManager<Switch, Dimmer> manager{};
      manager.update(); 
   }
}
