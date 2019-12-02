#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
 public:
  virtual void notify(GameContrller &whoFrom, ControllerInfo) = 0;
};
#endif
