#ifndef DOGBREEDS_POMERANIAN_UNIQUEID_H
#define DOGBREEDS_POMERANIAN_UNIQUEID_H

#include <cstdint>
#include <string>

namespace DogBreeds {
namespace Pomeranian {

class UniqueIdGenerator;

class UniqueId {
  friend class UniqueIdGenerator;

 private:
  uint64_t m_id;
  std::string m_stringId;
  UniqueId(const uint64_t &id);

 public:
  virtual ~UniqueId() = default;

  const uint64_t &getId() const;
  const std::string &getStringId() const;
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_UNIQUEID_H