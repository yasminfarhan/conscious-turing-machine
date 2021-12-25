//
// Module: ctm_tb
// Description: Testbench

#ifndef __CTMTB_H__
#define __CTMTB_H__

#include "systemc.h"
#include <ctime>
#include <ostream>

SC_MODULE(ctm_tb) {
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_out<int> data_0;
  sc_in<int> result_0;
  sc_out<int> data_1;
  sc_in<int> result_1;
  sc_out<bool> dat_ready_o;

  void source();
  void sink();

  SC_CTOR(ctm_tb) {
    SC_METHOD(source);
    sensitive << clk.pos() << rst;
    SC_METHOD(sink);
    sensitive << clk.pos() << rst;
  }
};
#endif
