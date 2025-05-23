#ifndef DOGBREEDS_POMERANIAN_OBSERVABLEINTERFACE_H
#define DOGBREEDS_POMERANIAN_OBSERVABLEINTERFACE_H

#include <memory>

#include "Observer.hpp"
namespace DogBreeds {
namespace Pomeranian {
template <typename T>
class ObservableInterface {
 public:
  virtual void registerObserver(std::shared_ptr<AbstractObserver> observer) = 0;
  virtual void unregisterObserver(
      std::shared_ptr<AbstractObserver> observer) = 0;
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_OBSERVABLEINTERFACE_H