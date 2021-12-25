//
// Module: myStm
// Description: Short Term Memory in CTM

#include "myStm.h"

template <typename T> void myStm<T>::beh()
{
    while(1) {

       for (int i=0; i<NUM_LTMS; i++) {
          chunk_t gotChunk = chunk_in[i].read();
          cout << "In STM, got data chunk from LTM with attributes: address - " << gotChunk.address << ", timestamp - " << gotChunk.t  << ", gist - " << gotChunk.gist%10  << ", weight - " << gotChunk.weight%10  << ", intensity - " << gotChunk.intensity%10  << ", mood - " << gotChunk.mood << endl;
          competing_chunks[i] = gotChunk;
       }

       cout << "In STM - Starting UpTree competition..." << endl;

       int winning_idx = upTree();

       cout << "In STM - UpTree competition complete! Winning chunk is from LTM: " << winning_idx  << endl;

       cout << "In STM - Beginning DownTree broadcast..." << endl;

       downTree(winning_idx);

       wait();
    }
}

template <typename T> int myStm<T>::upTree()
{
   return rand()%NUM_LTMS;
}

template <typename T> void myStm<T>::downTree(int _win_idx)
{
   for(int i=0; i<NUM_LTMS; i++) {
      chunk_out[i].write(competing_chunks[_win_idx]);
   }
}
