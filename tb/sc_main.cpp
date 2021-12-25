//
// Module: sc_main
// Description: sc_main 

#include "systemc.h"
#include "ctm.h"
#include "ctm_tb.h"
#include <ctime>
#include <ostream>

int sc_main(int, char **) {
  sc_clock        clk("clk", 10, SC_NS);
  sc_signal<bool> rst("rst");
  sc_signal<int> sample_a;
  sc_signal<int> result_a;
  
  sc_signal<int> sample_b;
  sc_signal<int> result_b;
  sc_signal<bool> dat_ready;

  ctm dut("dut");
  ctm_tb tb("tb");
  
  dut.clk(clk);
  dut.rst(rst);
  dut.in_data[0](sample_a);
  dut.out_data[0](result_a);
  dut.in_data[1](sample_b);
  dut.out_data[1](result_b);
  dut.dat_ready_i(dat_ready);

  tb.clk(clk);
  tb.rst(rst);
  tb.data_0(sample_a);
  tb.result_0(result_a);
  tb.data_1(sample_b);
  tb.result_1(result_b);
  tb.dat_ready_o(dat_ready);

  rst.write(false);
  sc_start(11,SC_NS);
  rst.write(true);

  sc_start(10*10,SC_NS);

  sc_stop();

  cout << "Simulation successful! @" << sc_time_stamp() << endl;

  return 0;
}
