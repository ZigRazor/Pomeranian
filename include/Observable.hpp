#ifndef DOGBREEDS_POMERANIAN_OBSERVABLE_H
#define DOGBREEDS_POMERANIAN_OBSERVABLE_H

#include "ObservableInterface.h"

namespace DogBreeds {
namespace Pomeranian {
template <typename T>
class Observable : public ObservableInterface {
 private:
  T m_value;

 public:
  void registerObserver() override;
  void set(const T& value);
  void get(const T& value);
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_OBSERVABLE_H