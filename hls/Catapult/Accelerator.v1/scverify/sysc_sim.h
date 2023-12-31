// ----------------------------------------------------------------------------
// SystemC SCVerify Flow -- sysc_sim.h
//
//    HLS version: 2021.1/950854 Production Release
//       HLS date: Mon Aug  2 21:36:02 PDT 2021
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 10.4
//
//   Generated by: rjujjav@lib-41917.eos.ncsu.edu
// Generated date: Sat Dec 09 00:51:57 EST 2023
//
// ----------------------------------------------------------------------------
#ifndef INCLUDED_SYSC_SIM_WRAPPER_H
#define INCLUDED_SYSC_SIM_WRAPPER_H
// 
// -------------------------------------
// sysc_sim_wrapper
// Represents a new SC_MODULE having the same interface as the original model Accelerator_rtl
// -------------------------------------
// 

#ifndef TO_QUOTED_STRING
#define TO_QUOTED_STRING(x) TO_QUOTED_STRING1(x)
#define TO_QUOTED_STRING1(x) #x
#endif
extern double __scv_hold_time;


#ifndef SC_USE_STD_STRING
#define SC_USE_STD_STRING
#endif

#include "../../../sc/Accelerator.h"
#include <systemc.h>
#include <mc_stall_ctrl.h>
#include <mc_scv_trans.h>
#include "mc_dut_wrapper.h"


namespace CCS_RTL {
   class sysc_sim_wrapper : public sc_module
   {
   public:
      // Module instance pointers
      HDL::ccs_DUT_wrapper ccs_rtl;
      
      // Interface Ports
      sc_core::sc_in<bool > clk;
      sc_core::sc_in<bool > reset_bar;
      axi::axi4<axi::cfg::standard >::read::slave<Connections::SYN_PORT > axi_read;
      axi::axi4<axi::cfg::standard >::write::slave<Connections::SYN_PORT > axi_write;
      
      // Named Objects
      
      // Data objects
      sc_signal< bool >                          ccs_rtl_SIG_clk;
      sc_signal< sc_logic >                      ccs_rtl_SIG_reset_bar;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_read_ar_val;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_read_ar_rdy;
      sc_signal< sc_lv<44> >                     ccs_rtl_SIG_axi_read_ar_msg;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_read_r_val;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_read_r_rdy;
      sc_signal< sc_lv<71> >                     ccs_rtl_SIG_axi_read_r_msg;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_write_aw_val;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_write_aw_rdy;
      sc_signal< sc_lv<44> >                     ccs_rtl_SIG_axi_write_aw_msg;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_write_w_val;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_write_w_rdy;
      sc_signal< sc_lv<73> >                     ccs_rtl_SIG_axi_write_w_msg;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_write_b_val;
      sc_signal< sc_logic >                      ccs_rtl_SIG_axi_write_b_rdy;
      sc_signal< sc_lv<6> >                      ccs_rtl_SIG_axi_write_b_msg;
      
      // Declare processes (SC_METHOD and SC_THREAD)
      void update_proc();
      
      // Constructor
      SC_HAS_PROCESS(sysc_sim_wrapper);
      sysc_sim_wrapper(
         const sc_module_name& nm
      )
         : ccs_rtl(
            "ccs_rtl",
            TO_QUOTED_STRING(TOP_HDL_ENTITY)
         )
         , clk("clk")
         , reset_bar("reset_bar")
         , axi_read("axi_read")
         , axi_write("axi_write")
         , ccs_rtl_SIG_clk("ccs_rtl_SIG_clk")
         , ccs_rtl_SIG_reset_bar("ccs_rtl_SIG_reset_bar")
         , ccs_rtl_SIG_axi_read_ar_val("ccs_rtl_SIG_axi_read_ar_val")
         , ccs_rtl_SIG_axi_read_ar_rdy("ccs_rtl_SIG_axi_read_ar_rdy")
         , ccs_rtl_SIG_axi_read_ar_msg("ccs_rtl_SIG_axi_read_ar_msg")
         , ccs_rtl_SIG_axi_read_r_val("ccs_rtl_SIG_axi_read_r_val")
         , ccs_rtl_SIG_axi_read_r_rdy("ccs_rtl_SIG_axi_read_r_rdy")
         , ccs_rtl_SIG_axi_read_r_msg("ccs_rtl_SIG_axi_read_r_msg")
         , ccs_rtl_SIG_axi_write_aw_val("ccs_rtl_SIG_axi_write_aw_val")
         , ccs_rtl_SIG_axi_write_aw_rdy("ccs_rtl_SIG_axi_write_aw_rdy")
         , ccs_rtl_SIG_axi_write_aw_msg("ccs_rtl_SIG_axi_write_aw_msg")
         , ccs_rtl_SIG_axi_write_w_val("ccs_rtl_SIG_axi_write_w_val")
         , ccs_rtl_SIG_axi_write_w_rdy("ccs_rtl_SIG_axi_write_w_rdy")
         , ccs_rtl_SIG_axi_write_w_msg("ccs_rtl_SIG_axi_write_w_msg")
         , ccs_rtl_SIG_axi_write_b_val("ccs_rtl_SIG_axi_write_b_val")
         , ccs_rtl_SIG_axi_write_b_rdy("ccs_rtl_SIG_axi_write_b_rdy")
         , ccs_rtl_SIG_axi_write_b_msg("ccs_rtl_SIG_axi_write_b_msg")
      {
         // Instantiate other modules
         ccs_rtl.clk(ccs_rtl_SIG_clk);
         ccs_rtl.reset_bar(ccs_rtl_SIG_reset_bar);
         ccs_rtl.axi_read_ar_val(ccs_rtl_SIG_axi_read_ar_val);
         ccs_rtl.axi_read_ar_rdy(ccs_rtl_SIG_axi_read_ar_rdy);
         ccs_rtl.axi_read_ar_msg(ccs_rtl_SIG_axi_read_ar_msg);
         ccs_rtl.axi_read_r_val(ccs_rtl_SIG_axi_read_r_val);
         ccs_rtl.axi_read_r_rdy(ccs_rtl_SIG_axi_read_r_rdy);
         ccs_rtl.axi_read_r_msg(ccs_rtl_SIG_axi_read_r_msg);
         ccs_rtl.axi_write_aw_val(ccs_rtl_SIG_axi_write_aw_val);
         ccs_rtl.axi_write_aw_rdy(ccs_rtl_SIG_axi_write_aw_rdy);
         ccs_rtl.axi_write_aw_msg(ccs_rtl_SIG_axi_write_aw_msg);
         ccs_rtl.axi_write_w_val(ccs_rtl_SIG_axi_write_w_val);
         ccs_rtl.axi_write_w_rdy(ccs_rtl_SIG_axi_write_w_rdy);
         ccs_rtl.axi_write_w_msg(ccs_rtl_SIG_axi_write_w_msg);
         ccs_rtl.axi_write_b_val(ccs_rtl_SIG_axi_write_b_val);
         ccs_rtl.axi_write_b_rdy(ccs_rtl_SIG_axi_write_b_rdy);
         ccs_rtl.axi_write_b_msg(ccs_rtl_SIG_axi_write_b_msg);
         
         
         // Register processes
         SC_METHOD(update_proc);
         sensitive  << clk << reset_bar << axi_read.axi::axi4<axi::cfg::standard >::read::slave<Connections::SYN_PORT >::ar.Connections::InBlocking_Ports_abs<axi::axi4<axi::cfg::standard >::AddrPayload >::val << ccs_rtl_SIG_axi_read_ar_rdy << axi_read.axi::axi4<axi::cfg::standard >::read::slave<Connections::SYN_PORT >::ar.Connections::InBlocking<axi::axi4<axi::cfg::standard >::AddrPayload, Connections::SYN_PORT >::msg << ccs_rtl_SIG_axi_read_r_val << axi_read.axi::axi4<axi::cfg::standard >::read::slave<Connections::SYN_PORT >::r.Connections::OutBlocking_Ports_abs<axi::axi4<axi::cfg::standard >::ReadPayload >::rdy << ccs_rtl_SIG_axi_read_r_msg << axi_write.axi::axi4<axi::cfg::standard >::write::slave<Connections::SYN_PORT >::aw.Connections::InBlocking_Ports_abs<axi::axi4<axi::cfg::standard >::AddrPayload >::val << ccs_rtl_SIG_axi_write_aw_rdy << axi_write.axi::axi4<axi::cfg::standard >::write::slave<Connections::SYN_PORT >::aw.Connections::InBlocking<axi::axi4<axi::cfg::standard >::AddrPayload, Connections::SYN_PORT >::msg << axi_write.axi::axi4<axi::cfg::standard >::write::slave<Connections::SYN_PORT >::w.Connections::InBlocking_Ports_abs<axi::axi4<axi::cfg::standard >::WritePayload >::val << ccs_rtl_SIG_axi_write_w_rdy << axi_write.axi::axi4<axi::cfg::standard >::write::slave<Connections::SYN_PORT >::w.Connections::InBlocking<axi::axi4<axi::cfg::standard >::WritePayload, Connections::SYN_PORT >::msg << ccs_rtl_SIG_axi_write_b_val << axi_write.axi::axi4<axi::cfg::standard >::write::slave<Connections::SYN_PORT >::b.Connections::OutBlocking_Ports_abs<axi::axi4<axi::cfg::standard >::WRespPayload >::rdy << ccs_rtl_SIG_axi_write_b_msg;
         // Other constructor statements
      }
      
      ~sysc_sim_wrapper()
      {
      }
      
      // C++ class functions
   };
} // end namespace CCS_RTL
#endif //INCLUDED_SYSC_SIM_WRAPPER_H
