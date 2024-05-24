#include "AbstractObserver.h"

namespace DogBreeds {
namespace Pomeranian {
AbstractObserver::AbstractObserver() {}

const Chihuahua::UniqueId& AbstractObserver::getUniqueId() const {
  return m_id;
}

}  // namespace Pomeranian

}  // namespace DogBreeds