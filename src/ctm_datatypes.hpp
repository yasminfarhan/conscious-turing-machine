//
// ctm_datatypes
//

#include "systemc.h"

#ifndef __CTM_DATATYPES_H__
#define __CTM_DATATYPES_H__

#ifndef chunk_conf_t_SC_WRAPPER_TYPE
#define chunk_t_SC_WRAPPER_TYPE 1

#define NUM_LTMS 2

struct chunk_t {
    int32_t address, t, gist, weight, intensity, mood;

    chunk_t (int32_t address_ = 0, int32_t t_ = 0, int32_t gist_ = 0, int32_t weight_ = 0, int32_t intensity_ = 0, int32_t mood_ = 0) {address = address_; t = t_; gist = gist_; weight = weight_; intensity = intensity_; mood = mood_;}

    inline chunk_t& operator = (const chunk_t& x)
    { address = x.address; t = x.t; gist = x.gist; weight = x.weight; intensity = x.intensity; mood = x.mood; return *this; }

    inline bool operator == (const chunk_t & x) const {
        return (x.address == address && x.t == t && x.gist == gist && x.weight == weight && x.intensity == intensity && x.mood == mood);
    }

    inline friend void sc_trace(sc_trace_file *tf, const chunk_t & x, const std::string & name) {
        sc_trace(tf, x.address, name + ".address");
        sc_trace(tf, x.address, name + ".t");
        sc_trace(tf, x.address, name + ".gist");
        sc_trace(tf, x.address, name + ".weight");
        sc_trace(tf, x.address, name + ".intensity");
        sc_trace(tf, x.address, name + ".mood");
    }

    inline friend ostream & operator<<(ostream& os, chunk_t const & x) {
        os << "(" << x.address << ", " << (int32_t) x.t << ", " << (int32_t) x.gist << ", " << (int32_t) x.weight << ", " << (int32_t) x.intensity <<  ", " << (int32_t) x.mood << ")";
        return os;
    }
};

#endif // chunk_t_SC_WRAPPER_TYPE

#endif // __CONV_LAYER_DATATYPES_H__
