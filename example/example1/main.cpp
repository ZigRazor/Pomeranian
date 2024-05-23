#include <unistd.h>

#include <iostream>
#include <memory>

#include "Observable.hpp"
#include "Observer.hpp"

using namespace DogBreeds;
using namespace DogBreeds::Pomeranian;

class myIntObserver : public Observer<int> {
 public:
  myIntObserver() : Observer<int>(){};
  virtual ~myIntObserver() = default;

 protected:
  void onChange(std::shared_ptr<int> oldValue,
                std::shared_ptr<int> newValue) override {
    std::cout << "Old Value = " << *oldValue << " New Value = " << *newValue
              << std::endl;
  }
};

int main() {
  Observable<int> intObservable;
  intObservable.set(3);
  std::cout << intObservable.get() << std::endl;

  auto observer = std::make_shared<myIntObserver>();
  intObservable.registerObserver(observer);

  intObservable.set(4);
  std::cout << intObservable.get() << std::endl;

  sleep(10);
  return 0;
}
