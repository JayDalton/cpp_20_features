#pragma once

#include "common.h"

namespace Concept01 {

   // Polymorphism

   //##################### dynamoc polymophism

   // base class conatains a virtual function
   struct dyn_base {
       virtual void do_work() = 0;
   };

   // which we override, to provide a concrete implementation 
   struct dyn_derived : public dyn_base {
       void do_work() override {
           // let's do some work here ... 
           print("dyn_derived: {}\n", "hello");
       }
   };

   //##################### dynamic polymophism

   // now we have a templated base class
   template<typename T> 
   struct sta_base {
       // no virtual function here
       void do_work () {
           // and we cast this to the template type, where the actual implementation lives
           static_cast<T*>(this)->do_work_impl();
       } 
   };

   // our class derived inherits from base and passes itself as template parameter
   class sta_derived : public sta_base<sta_derived> {
       // declare base as friend so do_work_impl can be called
       // because we still want to call the base class function
       friend class sta_base<sta_derived>;
       void do_work_impl() {
           print("sta_derived: {}\n", "hello");
           // let's do some work here ... 
       }
   };

   //##################### concept polymophism

   // we create a concept can_work to check if do_work is implemented
   // this will describe our interface
   template <typename T>
   concept can_work = requires(T t) {
       t.do_work();
   };

   // now we apply this concept to an empty type which represents a worker (or our base class)
   template<can_work T>
   struct worker : public T {};

   // now create a concrete worker (corresponding derived) where we implement do_work
   struct concrete_worker {
       void do_work() {
           print("con_derived: {}\n", "hello");
       }
   };

   // nice to have: an alias for our concrete worker
   using my_worker = worker<concrete_worker>;

   //...
   // which we can use now

   struct worker2 {
       void do_work() {
           print("var_derived: {}\n", "hello");
       }
   };

   //##################### variant polymophism

   using MyVariant = std::variant<worker2>;

   void call()
   {
      dyn_derived dd;
      dd.do_work();

      sta_derived sd;
      sd.do_work();

      my_worker w;
      w.do_work();

      static_assert(can_work<worker2>);

      MyVariant var;

      std::visit([](auto w){ w.do_work(); }, var);

   }
}

// ############################################################

namespace TypeErasure 
{
   struct animal_view
   {
      template <typename Speakable>
      explicit animal_view(const Speakable& speakable) 
         : object{&speakable}
         , speak_impl([](const void* obj){ return static_cast<const Speakable*>(obj)->speak(); })
      {

      }

      void speak() const { speak_impl(object); }

   private:
      const void* object;
      void (*speak_impl)(const void*);
   };

   void do_animal_thing(animal_view animal) { animal.speak(); }

   void call()
   {
      struct Cow {
         void speak() const { print("Mooo\n"); }
      };

      struct Sheep {
         void speak() const { print("Baaa\n"); }
      };

      do_animal_thing(animal_view{Cow{}});
      do_animal_thing(animal_view{Sheep{}});
   }
}