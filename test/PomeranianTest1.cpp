#include <gtest/gtest.h>

#include <memory>

#include "AbstractObserver.h"
#include "MockObserver.h"
#include "Observable.hpp"
#include "Observer.hpp"
#include "gmock/gmock.h"

using namespace DogBreeds::Pomeranian;

class PomeranianTest1 : public ::testing::Test {
 protected:
  std::shared_ptr<MockObserver<int>> intObserver;
  void SetUp() override { intObserver = std::make_shared<MockObserver<int>>(); }
};

TEST_F(PomeranianTest1, CreateEmptyObservable) {
  Observable<int> observable;
  EXPECT_TRUE(observable.get());
}

TEST_F(PomeranianTest1, CreateObservableValue) {
  Observable<int> observable(10);
  EXPECT_EQ(observable.get(), 10);
}

TEST_F(PomeranianTest1, ObservableValueSet) {
  Observable<int> observable(10);
  EXPECT_EQ(observable.get(), 10);
  observable.set(15);
  EXPECT_EQ(observable.get(), 15);
}

TEST_F(PomeranianTest1, ObserverOnChange) {
  Observable<int> observable(10);
  EXPECT_EQ(observable.get(), 10);
  observable.registerObserver(intObserver);
  EXPECT_CALL(*intObserver,
              onChange(std::make_shared<int>(10), std::make_shared<int>(15)))
      .Times(1);
  observable.set(15);
  EXPECT_EQ(observable.get(), 15);
}
