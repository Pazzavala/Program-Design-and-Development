#ifndef I_CELEBRATION_H_
#define I_CELEBRATION_H_

#include "IStrategy.h"

class ICelebrationDecorator : public IStrategy {
 public:
  IStrategy* strategy;
  int celebrationTime;  // maybe should be another type?

  /**
   * @brief Construct a new ICelebrationDecorator.
   *
   * @param startegy is the strategy that is being decorated.
   */
  ICelebrationDecorator(IStrategy* strategy);

  /**
   * @brief Move implements the type of celebration.
   *
   * @param entity Entity to move
   * @param dt Delta Time which is change in time.
   */
  void move(IEntity* entity, double dt);

  /**
   * @brief Check if the celebration is complete.
   *
   * @return True if complete, false if not complete.
   */
  bool isCompleted();

  /**
   * @brief Celebrate implements the the celebration actions.
   *
   * @param entity is the object preforming the celebration actions.
   * @param dt Delta Time which is change in time.
   */
  virtual void celebrate(IEntity* entity, double dt) = 0;
};
#endif
