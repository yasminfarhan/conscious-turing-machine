//
// Module: MYSTM
// Description: Short Term Memory in CTM

#ifndef __MYSTM_H__
#define __MYSTM_H__

#include "systemc.h"
#include "ctm_datatypes.hpp"
//#include <ostream>

template <typename T>
SC_MODULE(myStm) {
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_in<chunk_t> chunk_in[NUM_LTMS];
  sc_out<chunk_t> chunk_out[NUM_LTMS];

  // Clocked Threads
  void beh();

  // Functions
  int upTree();
  void downTree(int idx);

  SC_CTOR(myStm) {
    SC_CTHREAD(beh, clk.pos());
    reset_signal_is(rst, false);
  }

private:
  chunk_t competing_chunks[NUM_LTMS];
};

#include "myStm.cpp"
#endif
