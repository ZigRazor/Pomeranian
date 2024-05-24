#ifndef DOGBREEDS_POMERANIAN_ABSTRACTOBSERVER_H
#define DOGBREEDS_POMERANIAN_ABSTRACTOBSERVER_H

#include "AbstractSubscriber.h"
#include "Subscriber.hpp"
#include "UniqueId.h"
#include "UniqueIdGenerator.h"

namespace DogBreeds {
namespace Pomeranian {
class AbstractObserver {
 private:
  const Chihuahua::UniqueId m_id =
      Chihuahua::UniqueIdGenerator::getInstance().generateId();

 public:
  AbstractObserver();
  virtual ~AbstractObserver() = default;
  const Chihuahua::UniqueId& getUniqueId() const;
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_ABSTRACTOBSERVER_H