
#ifndef __ACCELERATOR_H__
#define __ACCELERATOR_H__

#include "nvhls_pch.h"

#include <ac_reset_signal_is.h>

#include <axi/axi4.h>
#include "AxiSlaveToReg2.h"
#include <CombinationalBufferedPorts.h>

class Accelerator : public sc_module {
 public:
  static const int kDebugLevel = 4;

  typedef axi::axi4<axi::cfg::standard> axi_;
  enum { numReg = 14, baseAddress = 0x0, numAddrBitsToInspect = 16 };

  sc_in<bool> clk;
  sc_in<bool> reset_bar;
  
  sc_int<16> we[16] ;
  sc_int<16> in[16] ;
  sc_int<16> out[16];

  typename axi_::read::template slave<> axi_read;
  typename axi_::write::template slave<> axi_write;

  AxiSlaveToReg2<axi::cfg::standard, numReg, numAddrBitsToInspect> slave;
  typedef AxiSlaveToReg2<axi::cfg::standard, numReg, numAddrBitsToInspect>::reg_write reg_write_;

  sc_signal<NVUINTW(numAddrBitsToInspect)> baseAddr;
  sc_signal<NVUINTW(axi_::DATA_WIDTH)> regOut_chan[numReg];

  Connections::CombinationalBufferedPorts<reg_write_,0,1> regIn_chan;



  SC_HAS_PROCESS(Accelerator);

  Accelerator(sc_module_name name)
      : sc_module(name),
        clk("clk"),
        reset_bar("reset_bar"),
        axi_read("axi_read"),
        axi_write("axi_write"),
        slave("slave"),
        regIn_chan("regIn_chan")
  {
    slave.clk(clk);
    slave.reset_bar(reset_bar);

    slave.if_axi_rd(axi_read);
    slave.if_axi_wr(axi_write);
    slave.regIn(regIn_chan);

    slave.baseAddr(baseAddr);
    baseAddr.write(baseAddress);

    for (int i = 0; i < numReg; i++) {
      slave.regOut[i](regOut_chan[i]);
    }

    SC_THREAD (run); 
    sensitive << clk.pos(); 
    NVHLS_NEG_RESET_SIGNAL_IS(reset_bar);

  }

  void run()
  {
    // cout << sc_time_stamp() << " " << name() << " Starting" << endl;
    regIn_chan.ResetWrite();
    //NVUINTW(axi_::DATA_WIDTH) lastCtrl = 0;
    reg_write_ regwr;
    regwr.addr = 10*8;
    regwr.data = 0;
	wait();
    // cout << sc_time_stamp() << " " << name() << " Reset" << endl;
    //
    // Under this while loop, I have to add my code for FIR filter and make 
    // changes to the way data is read.




	while(1){
		wait();
		if(regOut_chan[1].read() == 5 || regOut_chan[1].read() == 6){
			regwr.addr = 0x00	  		;
			regwr.data = 1        		;
			regIn_chan.Push(regwr)		;
			regIn_chan.TransferNBWrite();
			wait();


			for(int a=0; a<4; a++){
				for(int b = 0; b<4; b++){
					we[4*a+b] = (regOut_chan[a+2].read())>>(16*b);				
				}
			}


			/*for(int k = 0; k < 16; k++){
				int a = k/4;
				int b = k%4;
				we[4*a+b] = regOut_chan[a+2] >> (16 >> b)
			}*/


			regwr.data = 0;
			for(int j = 0; j < 4; j++){
				in[15] = regOut_chan[6].read() >> (16*j);
				out[j] = 0;
				for(int m=0;m<16;m++) out[j] += we[m]*in[m];
				for(int n = 0; n<15; n++) in[n] = in[n+1];
				regwr.data = regwr.data | (out[j] << (16*j));
			}
			regwr.addr = 80;
			regIn_chan.Push(regwr);
			regIn_chan.TransferNBWrite();
			wait();


		
			regwr.data = 0;
			for(int j = 0; j < 4;j++){
				in[15] = regOut_chan[7].read() >> (16*j);
				out[j+4] = 0;
				for(int m=0;m<16;m++) out[j+4] += we[m]*in[m];
				for(int n = 0; n<15; n++) in[n] = in[n+1];
				regwr.data = regwr.data | (out[j+4] << (16*j));
			}
			regwr.addr = 88;
			regIn_chan.Push(regwr);
			regIn_chan.TransferNBWrite();
			wait();


			regwr.data = 0;
			for(int j = 0; j < 4;j++){
				in[15] = regOut_chan[8].read() >> (16*j);
				out[j+8] = 0;
				for(int m=0;m<16;m++) out[j+8] += we[m]*in[m];	
				for(int n = 0; n<15; n++) in[n] = in[n+1];
				regwr.data = regwr.data | (out[j+8] << (16*j));
			}
			regwr.addr = 96;
			regIn_chan.Push(regwr);
			regIn_chan.TransferNBWrite();
			wait();



			regwr.data = 0;
			for(int j = 0; j < 4;j++){
				in[15] = regOut_chan[9].read() >> (16*j);
				out[j+9] = 0;
				for(int m=0;m<16;m++) out[j+9] += we[m]*in[m];	
				for(int n = 0; n<15; n++) in[n] = in[n+1];
				regwr.data = regwr.data | (out[j+9] << (16*j));
			}
			regwr.addr = 104;
			regIn_chan.Push(regwr);
			regIn_chan.TransferNBWrite();
			wait();

		}
	}

  /*  while (1)
    {
        wait();
        if (regOut_chan[1].read()!=lastCtrl) {
          lastCtrl = regOut_chan[1].read();
          if (regOut_chan[1].read() >=2 && regOut_chan[1].read() <=5) {
            // Copy data from weight register to corresponding output register
            regwr.data=regOut_chan[regOut_chan[1].read()].read();
            regwr.addr=(regOut_chan[1].read()-2)*8 + 80;
            // Start transfer
            cout << sc_time_stamp() << " " << name() << " Pushing " << regwr << endl;
            // Blocking Write
            regIn_chan.Push(regwr);
            regIn_chan.TransferNBWrite();
            // Sample code for a non-blocking write
            // if (!regIn_chan.FullWrite()) {
            //   regIn_chan.Push(regwr);
            // }
            cout << sc_time_stamp() << " " << name() << " Pushed" << endl;
          }
        }
    }*/
  }  
};

#endif
