/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_CORRECTIQ_correctiq_auto_impl_H
#define INCLUDED_CORRECTIQ_correctiq_auto_impl_H

#include <correctiq/correctiq_auto.h>

namespace gr {
  namespace correctiq {

    class correctiq_auto_impl : public correctiq_auto
    {
     private:
      // Nothing to declare in this block.
     float avg_real = 0.0;
     float avg_img = 0.0;
     float ratio=1e-05f;

     float d_samp_rate;
     float d_freq;
     float d_gain;
     float d_syncWindow;

     long syncCounter = 0;
     bool synchronized = false;

     long d_max_syncSamples;

     public:
      correctiq_auto_impl(float samp_rate,float freq,float gain,float syncWindow);
      ~correctiq_auto_impl();

      void set_synchronized() {synchronized = true; };  // used for testing
      void setup_rpc();

      virtual float get_freq();
      virtual float get_gain();

      virtual void set_freq(float newValue);
      virtual void set_gain(float newValue);

      int testCPU(int noutput_items,
                         gr_vector_const_void_star &input_items,
                         gr_vector_void_star &output_items);

      int work(int noutput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace correctiq
} // namespace gr

#endif /* INCLUDED_CORRECTIQ_correctiq_auto_impl_H */

