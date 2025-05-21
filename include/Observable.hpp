#ifndef DOGBREEDS_POMERANIAN_OBSERVABLE_H
#define DOGBREEDS_POMERANIAN_OBSERVABLE_H

#include <memory>

#include "ObservableInterface.h"
#include "Observer.hpp"
#include "TopicManager.h"
#include "UniqueId.h"
#include "UniqueIdGenerator.h"

namespace DogBreeds {
namespace Pomeranian {
template <typename T>
class Observable : public ObservableInterface<T> {
 private:
  T m_value;
  const Chihuahua::UniqueId id =
      Chihuahua::UniqueIdGenerator::getInstance().generateId();

 public:
  Observable() {
    JackRussell::TopicManager::getInstance()
        .createTopic<std::pair<std::shared_ptr<T>, std::shared_ptr<T>>>(
            id.getStringId());
  }

  Observable(const T& value) : m_value(value) {
    JackRussell::TopicManager::getInstance()
        .createTopic<std::pair<std::shared_ptr<T>, std::shared_ptr<T>>>(
            id.getStringId());
  }

  virtual ~Observable() = default;

  void registerObserver(std::shared_ptr<AbstractObserver> observer) override {
    JackRussell::TopicManager::getInstance().subscribeToTopic(
        std::dynamic_pointer_cast<Observer<T>>(observer), id.getStringId());
  }

  void unregisterObserver(std::shared_ptr<AbstractObserver> observer) override {
    JackRussell::TopicManager::getInstance().unsubscribeFromTopic(
        std::dynamic_pointer_cast<Observer<T>>(observer), id.getStringId());
  }

  void set(const T& value) {
    JackRussell::TopicManager::getInstance().publishToTopic(
        id.getStringId(),
        std::make_shared<std::pair<std::shared_ptr<T>, std::shared_ptr<T>>>(
            std::make_shared<T>(m_value), std::make_shared<T>(value)));
    m_value = value;
  }
  const T& get() const { return m_value; }
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_OBSERVABLE_H