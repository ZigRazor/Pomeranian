#ifndef TEST_MOCKSUBSCRIBER_H_
#define TEST_MOCKSUBSCRIBER_H_

#include <gmock/gmock.h>

#include "Observer.hpp"

namespace DogBreeds {
namespace Pomeranian {

template <typename T>
class MockObserver : public Observer<T> {
 public:
  MockObserver() : Observer<T>() {}
  MOCK_METHOD(void, onChange,
              (std::shared_ptr<T> oldValue, std::shared_ptr<T> newValue),
              (override));
};

}  // namespace Pomeranian
}  // namespace DogBreeds

#endif /* TEST_MOCKSUBSCRIBER_H_ */
