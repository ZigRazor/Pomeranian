#ifndef DOGBREEDS_POMERANIAN_OBSERVABLEINTERFACE_H
#define DOGBREEDS_POMERANIAN_OBSERVABLEINTERFACE_H

namespace DogBreeds {
namespace Pomeranian {
class ObservableInterface {
 public:
  virtual void registerObserver() = 0;
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_OBSERVABLEINTERFACE_H