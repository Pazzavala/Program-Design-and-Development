#ifndef I_SPIN_H_
#define I_SPIN_H_

#include "ICelebrationDecorator.h"

class SpinDecorator : public ICelebrationDecorator {
 public:
  /**
   * @brief Construct a new SpinDecorator.
   *
   * @param startegy is the strategy that is being decorated.
   */
  SpinDecorator(IStrategy* strategy);

  /**
   * @brief Deconstructor for SpinDecorator.
   */
  ~SpinDecorator();

  /**
   * @brief Celebrate implements the the spin celebration actions.
   *
   * @param entity is the object preforming the celebration actions.
   * @param dt Delta Time which is change in time.
   */
  void celebrate(IEntity* entity, double dt);
};
#endif
