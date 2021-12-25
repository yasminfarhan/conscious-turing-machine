//
// Module: ctm
// Description: Conscious Turing Machine

#ifndef __CTM_H__
#define __CTM_H__

#include "systemc.h"
#include "myLtm.h"
#include "myStm.h"
#include "ctm_datatypes.hpp"
#include <ostream>

SC_MODULE(ctm) {
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_in<int> in_data[NUM_LTMS];
  sc_out<int> out_data[NUM_LTMS];
  sc_in<bool> dat_ready_i;
  sc_out<bool> ltm_a_ready_o;
  sc_out<bool> ltm_b_ready_o;

  void process_data();

  SC_CTOR(ctm) :
    ltm_a("long_term_mem_a"),
    ltm_b("long_term_mem_b"),
    stm("short_term_mem")
  {
          SC_CTHREAD(process_data, clk.pos());
          reset_signal_is(rst, false);

	  ltm_a.chunk_in(winning_chunks_down[0]);
	  ltm_a.chunk_out(competing_chunks[0]);
	  ltm_a.ext_data_in(in_data[0]);
	  ltm_a.ext_data_out(out_data[0]);
          ltm_a.got_data(ltm_dat_ready[0]);
          ltm_a.clk(clk);
          ltm_a.rst(rst);
          ltm_a.which_ltm = 0;

	  ltm_b.chunk_in(winning_chunks_down[1]);
	  ltm_b.chunk_out(competing_chunks[1]);
	  ltm_b.ext_data_in(in_data[1]);
	  ltm_b.ext_data_out(out_data[1]);
          ltm_b.got_data(ltm_dat_ready[1]);
          ltm_b.clk(clk);
	  ltm_b.rst(rst);
          ltm_b.which_ltm = 1;

          stm.chunk_in[0](competing_chunks[0]);
          stm.chunk_out[0](winning_chunks_down[0]);
          stm.chunk_in[1](competing_chunks[1]);
          stm.chunk_out[1](winning_chunks_down[1]);
          stm.clk(clk);
          stm.rst(rst);

          ltm_a_ready_o(ltm_dat_ready[0]);
          ltm_b_ready_o(ltm_dat_ready[1]);
  }

 private:
  myLtm<int> ltm_a;
  myLtm<int> ltm_b;

  myStm<int> stm;
  sc_signal<chunk_t> winning_chunks_down[NUM_LTMS];
  sc_signal<chunk_t> competing_chunks[NUM_LTMS];
  sc_signal<bool> ltm_dat_ready[NUM_LTMS];
};
#endif
