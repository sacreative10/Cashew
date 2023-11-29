//
// Created by sohaibalam on 27/11/23.
//

#ifndef CASHEW_LAYER_H
#define CASHEW_LAYER_H

namespace Cashew {
  class Layer {
  public:

      virtual ~Layer() = default;

      virtual void onAttach() {}
      virtual void onDetach() {}

      virtual void onUpdate(float dt) {}
      virtual void onUIRender() {}
  };
};

#endif //CASHEW_LAYER_H
