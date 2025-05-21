#ifndef DOGBREEDS_POMERANIAN_SYNCOBSERVER_H
#define DOGBREEDS_POMERANIAN_SYNCOBSERVER_H

#include <memory>
#include <utility>

#include "AbstractObserver.h"
#include "Subscriber.hpp"

namespace DogBreeds {
namespace Pomeranian {
template <typename T>
class SyncObserver : public AbstractObserver,
                     public JackRussell::Subscriber<
                         std::pair<std::shared_ptr<T>, std::shared_ptr<T>>> {
 private:
 protected:
  virtual void onChange(std::shared_ptr<T> oldValue,
                        std::shared_ptr<T> newValue) = 0;

 public:
  SyncObserver()
      : AbstractObserver(),
        JackRussell::Subscriber<
            std::pair<std::shared_ptr<T>, std::shared_ptr<T>>>(
            this->getUniqueId().getStringId()) {}

  virtual ~SyncObserver() = default;

  void onMessage(
      std::shared_ptr<std::pair<std::shared_ptr<T>, std::shared_ptr<T>>>
          message) override {
    onChange(message->first, message->second);
  }
};
}  // namespace Pomeranian
}  // namespace DogBreeds

#endif  // DOGBREEDS_POMERANIAN_SYNCOBSERVER_H