//
// Module: myLtm
// Description: Long Term Memory in CTM

#include "myLtm.h"
#include "ctm_datatypes.hpp"

template <typename T> void myLtm<T>::beh()
{
    while(1){
       do {
          wait();
       } while (!got_data.read());

       int tmpData = (T)ext_data_in.read();

       cout << "LTM " << which_ltm << " received the following information from the external environment, transforming it using an input map now...: " << tmpData << endl;
       ext_data_out.write(tmpData);

       wait();
    }
}

template <typename T> void myLtm<T>::gen_chunks()
{
    int timestamp = 0;
    while (1) {
        chunk_t newChunk(which_ltm,timestamp++,rand()%10,rand()%10,rand()%10,rand()%10);

       cout << "Sending data chunk from LTM " << which_ltm << " with attributes: address - " << newChunk.address << ", timestamp - " << newChunk.t  << ", gist - " << newChunk.gist  << ", weight - " << newChunk.weight  << ", intensity - " << newChunk.intensity  << ", mood - " << newChunk.mood << endl;
       chunk_out.write(newChunk);

       wait();
    }
}

template <typename T> void myLtm<T>::process_chunks()
{
    while (1) {
       chunk_t newChunk = chunk_in.read();

       cout << "In LTM " << which_ltm << ", received chunk from STM with attributes: address - " << newChunk.address << ", timestamp - " << newChunk.t  << ", gist - " << newChunk.gist  << ", weight - " << newChunk.weight  << ", intensity - " << newChunk.intensity  << ", mood - " << newChunk.mood << endl;
       wait();
    }
}
