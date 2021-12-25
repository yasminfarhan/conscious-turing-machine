//
// Module: ctm_tb
// Description: Testbench

#include "ctm_tb.h"

void ctm_tb::source()
{
  cout << "In ctm_tb source() function" << endl;
  if (!rst.read()) {
     RESET:
      data_0.write(0);
      data_1.write(0);
  } else if (clk.event()) {
      int tmpData_ltm_a = rand()%100;
      int tmpData_ltm_b = rand()%100;
      dat_ready_o.write(0);

      cout << "In CTM tb: Sending " << tmpData_ltm_a << " to LTM A and sending " << tmpData_ltm_b << " to LTM B" << endl;

      data_0.write(tmpData_ltm_a);
      data_1.write(tmpData_ltm_b);
      dat_ready_o.write(1);
  }
}

void ctm_tb::sink()
{
  cout << "In ctm_tb sink() function..." << endl;
  if (rst.read()) {
      int tmpData_from_ltm_a = result_0.read();
      int tmpData_from_ltm_b = result_1.read();
      cout << "Received " << tmpData_from_ltm_a << " from LTM A and received " << tmpData_from_ltm_b << " from LTM B" << endl;
  }
}
