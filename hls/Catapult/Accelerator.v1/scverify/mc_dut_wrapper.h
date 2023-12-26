// ----------------------------------------------------------------------------
// SystemC Wrapper for Catapult Design HDL Netlist
//
//    HLS version: 2021.1/950854 Production Release
//       HLS date: Mon Aug  2 21:36:02 PDT 2021
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 10.4
//
//   Generated by: rjujjav@lib-41917.eos.ncsu.edu
// Generated date: Sat Dec 09 00:51:57 EST 2023
//
// ----------------------------------------------------------------------------
#ifndef INCLUDED_CCS_DUT_WRAPPER_H
#define INCLUDED_CCS_DUT_WRAPPER_H

#ifndef SC_USE_STD_STRING
#define SC_USE_STD_STRING
#endif

#include <systemc.h>
#include <mc_simulator_extensions.h>

#ifdef CCS_SYSC
namespace HDL {
#endif

#if defined(CCS_DUT_SYSC)

// alias ccs_DUT_wrapper to namespace enclosure of either cycle or RTL SystemC netlist
namespace ccs_design {
#if defined(CCS_DUT_CYCLE)
#include "cycle.cxx"
#else
#if defined(CCS_DUT_RTL)
#include "rtl.cxx"
#endif
#endif
}
typedef ccs_design::HDL::Accelerator_rtl ccs_DUT_wrapper;

#else

// Create a foreign module wrapper around the HDL
#ifdef VCS_SYSTEMC
// VCS support - ccs_DUT_wrapper is derived from VCS-generated SystemC wrapper around HDL code

class ccs_DUT_wrapper : public TOP_HDL_ENTITY
{
public:
   ccs_DUT_wrapper(const sc_module_name& nm, const char *hdl_name)
      : TOP_HDL_ENTITY(nm)
      {
         //elaborate_foreign_module(hdl_name);
      }
   
   ~ccs_DUT_wrapper() {}
};

#else
// non VCS simulators - ccs_DUT_wrapper is derived from mc_foreign_module (adding 2nd ctor arg)

class ccs_DUT_wrapper : public mc_foreign_module
{
public:
   #ifndef VCS_SYSTEMC
   // Interface Ports
   sc_in<bool> clk;
   sc_in< sc_logic > reset_bar;
   sc_in< sc_logic > axi_read_ar_val;
   sc_out< sc_logic > axi_read_ar_rdy;
   sc_in< sc_lv<44> > axi_read_ar_msg;
   sc_out< sc_logic > axi_read_r_val;
   sc_in< sc_logic > axi_read_r_rdy;
   sc_out< sc_lv<71> > axi_read_r_msg;
   sc_in< sc_logic > axi_write_aw_val;
   sc_out< sc_logic > axi_write_aw_rdy;
   sc_in< sc_lv<44> > axi_write_aw_msg;
   sc_in< sc_logic > axi_write_w_val;
   sc_out< sc_logic > axi_write_w_rdy;
   sc_in< sc_lv<73> > axi_write_w_msg;
   sc_out< sc_logic > axi_write_b_val;
   sc_in< sc_logic > axi_write_b_rdy;
   sc_out< sc_lv<6> > axi_write_b_msg;
   #endif
   
public:
   ccs_DUT_wrapper(const sc_module_name& nm, const char *hdl_name)
      : mc_foreign_module(nm,hdl_name)
      #ifndef VCS_SYSTEMC
      ,clk("clk")
      ,reset_bar("reset_bar")
      ,axi_read_ar_val("axi_read_ar_val")
      ,axi_read_ar_rdy("axi_read_ar_rdy")
      ,axi_read_ar_msg("axi_read_ar_msg")
      ,axi_read_r_val("axi_read_r_val")
      ,axi_read_r_rdy("axi_read_r_rdy")
      ,axi_read_r_msg("axi_read_r_msg")
      ,axi_write_aw_val("axi_write_aw_val")
      ,axi_write_aw_rdy("axi_write_aw_rdy")
      ,axi_write_aw_msg("axi_write_aw_msg")
      ,axi_write_w_val("axi_write_w_val")
      ,axi_write_w_rdy("axi_write_w_rdy")
      ,axi_write_w_msg("axi_write_w_msg")
      ,axi_write_b_val("axi_write_b_val")
      ,axi_write_b_rdy("axi_write_b_rdy")
      ,axi_write_b_msg("axi_write_b_msg")
      #endif
      {
          elaborate_foreign_module(hdl_name);
      }
      
      ~ccs_DUT_wrapper() {}
   };
   #endif
   
   #endif

#endif

#ifdef CCS_SYSC
} // end namespace HDL
#endif
