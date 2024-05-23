#ifndef DOGBREEDS_POMERANIAN_UNIQUEIDGENERATOR_H
#define DOGBREEDS_POMERANIAN_UNIQUEIDGENERATOR_H

#include <sys/types.h>

#include <mutex>

#include "UniqueId.h"

namespace DogBreeds {
namespace Pomeranian {
class UniqueIdGenerator {
 private:
  std::mutex m_mutex;
  uint64_t m_progressive;
  UniqueIdGenerator() = default;

 public:
  virtual ~UniqueIdGenerator() = default;
  static UniqueIdGenerator &getInstance();

  UniqueIdGenerator(UniqueIdGenerator const &) = delete;
  void operator=(UniqueIdGenerator const &) = delete;

  UniqueId generateId();
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_UNIQUEIDGENERATOR_H