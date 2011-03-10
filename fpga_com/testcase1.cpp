/*
 * Copyright (C) 2011 Simon A. Berger
 * 
 *  This program is free software; you may redistribute it and/or modify its
 *  under the terms of the GNU Lesser General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 */

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

#include "fpga_com.h"
#include "background_reader.h"

int main() {

    fpga_con_t fc;
   
    fpga_con_init( &fc, "192.168.1.1", 21844, 21845 );   
    
    fpga_bgr_t bgr;

    fpga_bgr_init( &bgr, fc.s, 1024 * 1024 * 10 );
    
    fpga_bgr_start( &bgr );
    
    
    fpga_con_send_init_packet( &fc );
    
    {
        const int N = 10;
        float test[N];
        for( int i = 0; i < N; i++ ) {
        
            test[i] = exp(i);
            
        }

        fpga_con_send_floatv( &fc, test, N);
        
        
        float rec[N];
        fpga_bgr_recv_floatv(&bgr, rec, N );

        
        printf( "recv float: \n" );
        for( int i = 0; i < N; i++ ) {
            printf( "recv: %f %f", test[i], rec[i] ); 
        }
    }
    {
        const int N = 10;
        double test[N];
        for( int i = 0; i < N; i++ ) {
        
            test[i] = exp(i);
            
        }

        fpga_con_send_doublev( &fc, test, N);
        
        double rec[N];
        fpga_bgr_recv_doublev(&bgr, rec, N );

        
        printf( "recv double: \n" );
        for( int i = 0; i < N; i++ ) {
            printf( "recv: %f %f", test[i], rec[i] ); 
        }
    }
}
