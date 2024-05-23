#include "UniqueIdGenerator.h"

#include <mutex>

namespace DogBreeds {
namespace Pomeranian {
UniqueIdGenerator &UniqueIdGenerator::getInstance() {
  static UniqueIdGenerator instance;
  return instance;
}

UniqueId UniqueIdGenerator::generateId() {
  std::lock_guard<std::mutex> lock(m_mutex);
  UniqueId uid(m_progressive);
  m_progressive++;
  return uid;
}

}  // namespace Pomeranian

}  // namespace DogBreeds