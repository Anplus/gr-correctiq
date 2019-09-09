/* -*- c++ -*- */
/*
 * Copyright 2019 ghostop14.
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

#ifndef INCLUDED_CORRECTIQ_CORRECTIQ_MAN_IMPL_H
#define INCLUDED_CORRECTIQ_CORRECTIQ_MAN_IMPL_H

#include <correctiq/correctiq_man.h>

namespace gr {
  namespace correctiq {

    class correctiq_man_impl : public correctiq_man
    {
     private:
        float avg_real = 0.0;
        float avg_img = 0.0;

        gr_complex d_k;

        public:
         correctiq_man_impl(float real,float imag);
         ~correctiq_man_impl();

         virtual float get_real();
         virtual float get_imag();

         virtual void set_real(float newValue);
         virtual void set_imag(float newValue);

         int testCPU(int noutput_items,
                            gr_vector_const_void_star &input_items,
                            gr_vector_void_star &output_items);

         int work(int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items);
    };

  } // namespace correctiq
} // namespace gr

#endif /* INCLUDED_CORRECTIQ_CORRECTIQ_MAN_IMPL_H */

