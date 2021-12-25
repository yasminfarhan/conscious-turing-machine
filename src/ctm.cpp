//
// Module: ctm
// Description: Conscious Turing Machine

#include "ctm.h"

void ctm::process_data(void) {
    while(1) {
       do {
           wait();
       } while (!dat_ready_i);

       cout << "In CTM, receiving information from the outside world... " << endl;
       cout << "In CTM, letting LTMs know there is information for them... " << endl;

       ltm_a_ready_o.write(1);
       ltm_b_ready_o.write(1);
       wait();
       ltm_a_ready_o.write(1);
       ltm_b_ready_o.write(1);
    }
}
