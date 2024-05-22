#ifndef DOGBREEDS_POMERANIAN_OBSERVABLE_H
#define DOGBREEDS_POMERANIAN_OBSERVABLE_H

#include "ObservableInterface.h"
#include "uuid.h"

namespace DogBreeds {
namespace Pomeranian {
template <typename T>
class Observable : public ObservableInterface {
 private:
  T m_value;
  uuid const id;
 public:
  Observable(){
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    std::mt19937 generator(seq);
    uuids::uuid_random_generator gen{generator};
    id = gen();
  }
  virtual ~Observable() = default;
  void registerObserver(std::shared_ptr<Observer> observer) override;
  void set(const T& value);
  void get(const T& value);
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_OBSERVABLE_H