
#include <stdio.h>

#define TAPS 16
#define TSTEP 48

// short coef[TAPS] = {
// #include "coef.inc"
// };

// short input[TSTEP] = {
// #include "input.inc"
// };


#include "expected.inc"

int main( int argc, char* argv[] )
{
  volatile long long *llp;
  volatile long long **llpp;

// it is a 28 bit bus, and two ports.
// one port for controller
// pointer is direct address storing address.

  llpp=(volatile long long**)0x70000010; // dma sr
  *llpp=(volatile long long*)0x00004000; // memctl coef1 address
  llpp=(volatile long long**)0x70000018; // dma dr
  *llpp=(volatile long long*)0x10010010; // fir tap coef
  llp=(volatile long long*)0x70000020;   // dma len
  *llp=(volatile long long)32; // starts transfer 16 number with 32 bytes
  llp=(volatile long long*)0x70000000;   // dma st

  // The following line polls the dma st register until it is 0,
  // effectively waiting until the transfer is complete.
 
  while (*llp);
  printf("CHECK \n"); 
  // If the previous line is omitted, then the next one will not
  // show the expected valye, because the transfer is not complete.
  // Definately add a while star loop
 // printf("cpu main {W[3],W[2],W[1],W[0]} 0x%lx (0x2ffffffff0000 expected)\n",*((long long*)0x70010010));
/*
  int n,m;
  short *coef=(short *)0x60004000;
  short *input=(short *)0x60002000;
  // Uncomment the next line to avoid memory controller accesses
  // short output[TSTEP-TAPS];
  short *output=(short *)0x60001000;
  short error,total_error;

  for (n=0; n<TSTEP-TAPS; n++) {
    output[n]=0;
    for (m=0; m<TAPS; m++) {
      if (n+m-TAPS+1 >= 0) {
        output[n]+=coef[m]*input[n+m-TAPS+1];
        // Uncomment the next line for detailed calculation
         //printf("cpu main n: %d coef[%d]: %d input[%d]: %d sum: %d\n",n,m,coef[m],n+m-TAPS+1,input[n+m-TAPS+1],output[n]);
      }
    }
  }

  total_error=0;
  for (n=0; n<TSTEP-TAPS; n++) {
    error=expected[n]-output[n];              // Error for this time-step
    total_error+=(error<0)?(-error):(error);  // Absolute value
    // Uncomment the next line for a detailed error check
    // printf("cpu main k: %d output: %d expected %d\n",n,output[n],expected[n]);
  }
*/

// FIR HARDWARE
// INPUT SET 1
	llpp	= (volatile long long**) 0x70000010;
    *llpp	= (volatile long long*)  0x00002000;
	llpp	= (volatile long long**) 0x70000018;
	*llpp	= (volatile long long*)  0x10010030;
	llp		= (volatile long long*)  0x70000020;
	*llp	= (volatile long long)	 32		   ;
	llp		= (volatile long long*)  0x70000000;

	while(*llp);
	printf("INPUT\n");
	
	llp		= (volatile long long*)  0x70000020;
	*llp	= (volatile long long)	 0x05	   ;	
	llp		= (volatile long long*)  0x70010000;

	while(*llp);
	printf("output\n");

// OUTPUT SET 1
	llpp	= (volatile long long**) 0x70000010;
    *llpp	= (volatile long long*)  0x00010050;
	llpp	= (volatile long long**) 0x70000018;
	*llpp	= (volatile long long*)  0x10001000;
	llp		= (volatile long long*)  0x70000020;
	*llp	= (volatile long long)	 32		   ;
	llp		= (volatile long long*)  0x70000000;

	while(*llp);
	printf("Input\n");


// INPUT SET 2
	llpp	= (volatile long long**) 0x70000010;
    *llpp	= (volatile long long*)  0x00002020;
	llpp	= (volatile long long**) 0x70000018;
	*llpp	= (volatile long long*)  0x10010030;
	llp		= (volatile long long*)  0x70000020;
	*llp	= (volatile long long)	 32		   ;
	llp		= (volatile long long*)  0x70000000;

	while(*llp);
	printf("Output\n");
	
	llp		= (volatile long long*)  0x70000020;
	*llp	= (volatile long long)	 0x06	   ; 
	llp		= (volatile long long*)  0x70010000;

	while(*llp);
	printf("out\n");

// OUTPUT SET 2
	llpp	= (volatile long long**) 0x70000010;
    *llpp	= (volatile long long*)  0x00010050;
	llpp	= (volatile long long**) 0x70000018;
	*llpp	= (volatile long long*)  0x10001020;
	llp		= (volatile long long*)  0x70000020;
	*llp	= (volatile long long)	 32		   ;
	llp		= (volatile long long*)  0x70000000;
	//printf("CHECKING!!");	
	while(*llp);
	printf(" ");



 int n,m;
  short *coef=(short *)0x60004000;
  short *input=(short *)0x60002000;
  // Uncomment the next line to avoid memory controller accesses
  short output[TSTEP-TAPS];
  *output=(short *)0x60001000;
  short error,total_error;

  for (n=0; n<TSTEP-TAPS; n++) {
    output[n]=0;
    for (m=0; m<TAPS; m++) {
      if (n+m-TAPS+1 >= 0) {
        output[n]+=coef[m]*input[n+m-TAPS+1];
        // Uncomment the next line for detailed calculation
        //printf("cpu main n: %d coef[%d]: %d input[%d]: %d sum: %d\n",n,m,coef[m],n+m-TAPS+1,input[n+m-TAPS+1],output[n]);
      }
    }
  }



  total_error=0;
  for (n=0; n<TSTEP-TAPS; n++) {
    error=expected[n]-output[n];              // Error for this time-step
    total_error+=(error<0)?(-error):(error);  // Absolute value
    // Uncomment the next line for a detailed error check
    // printf("cpu main k: %d output: %d expected %d\n",n,output[n],expected[n]);
  }
  printf("cpu main error: %d\n",total_error);

  llp=(volatile long long*)0x70010008;; // fir ctrl
  *llp=(volatile long long)0x01;       // Print registers
  *llp=(volatile long long)0x02;       // Copy reg[2] to reg[10]
  *llp=(volatile long long)0x03;       // Copy reg[3] to reg[11]
  *llp=(volatile long long)0x04;       // Copy reg[4] to reg[12]
  *llp=(volatile long long)0x01;       // Print registers
  *llp=(volatile long long)0x0f;       // Exit

	while(*llp);
	//printf("cpu main {W[3],W[2],W[1],W[0]} 0x%lx (0x2ffffffff0000 expected)\n",*((long long*)0x70010010));
	printf("CHECK \n");
  // Exiting simulation 0x0f....
  //
  //
  return 0;
}
