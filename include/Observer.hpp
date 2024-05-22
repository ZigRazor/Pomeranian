#ifndef DOGBREEDS_POMERANIAN_OBSERVER_H
#define DOGBREEDS_POMERANIAN_OBSERVER_H

#include "Subscriber.hpp"

namespace DogBreeds {
namespace Pomeranian {
template <typename T>
class Observer : public Subscriber<T> {
 private:
 public:
  void registerObserver(std::shared_ptr<Observer> observer) override;
  void set(const T& value);
  void get(const T& value);
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_OBSERVER_H