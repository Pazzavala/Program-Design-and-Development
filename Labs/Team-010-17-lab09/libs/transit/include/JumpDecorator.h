#ifndef I_JUMP_H_
#define I_JUMP_H_

#include "ICelebrationDecorator.h"

class JumpDecorator : public ICelebrationDecorator {
 private:
  float maxHeight;
  float minHeight;

 public:
  /**
   * @brief Construct a new JumpDecorator.
   *
   * @param startegy is the strategy that is being decorated.
   */
  JumpDecorator(IStrategy* strategy);

  /**
   * @brief Deconstructor for JumpDecorator.
   */
  ~JumpDecorator();

  /**
   * @brief Celebrate implements the the jump celebration actions.
   *
   * @param entity is the object preforming the celebration actions.
   * @param dt Delta Time which is change in time.
   */
  void celebrate(IEntity* entity, double dt);
};
#endif
