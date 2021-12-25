//
// Module: MYLTM
// Description: Long Term Memory in CTM

#ifndef __MYLTM_H__
#define __MYLTM_H__

#include "systemc.h"
#include "ctm_datatypes.hpp"

//#include <ostream>

template <typename T>
SC_MODULE(myLtm) {
  sc_in<bool> clk;
  sc_in<bool> rst;

  sc_in<bool> got_data;

  sc_in<chunk_t> chunk_in;
  sc_out<chunk_t> chunk_out;

  sc_in<T> ext_data_in;
  sc_out<T> ext_data_out;

  void beh();
  void gen_chunks();
  void process_chunks();

  SC_CTOR(myLtm) {
    SC_CTHREAD(beh, clk.pos());
    reset_signal_is(rst, false);
    sensitive << clk.pos() << rst << chunk_in << chunk_out << ext_data_in << ext_data_out;

    SC_CTHREAD(gen_chunks, clk.pos());
    reset_signal_is(rst, false);

    SC_CTHREAD(process_chunks, clk.pos());
    reset_signal_is(rst, false);
  }

  public:
     int which_ltm;
};
#include "myLtm.cpp"
#endif
