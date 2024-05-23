#include "UniqueId.h"

#include <sys/types.h>

#include <string>

namespace DogBreeds {
namespace Pomeranian {
UniqueId::UniqueId(const u_int64_t &id) {
  m_id = id;
  m_stringId = std::to_string(m_id);
}

const uint64_t &UniqueId::getId() const { return m_id; }
const std::string &UniqueId::getStringId() const { return m_stringId; }

}  // namespace Pomeranian
}  // namespace DogBreeds