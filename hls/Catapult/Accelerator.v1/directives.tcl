//  Catapult Ultra Synthesis 2021.1/950854 (Production Release) Mon Aug  2 21:36:02 PDT 2021
//  
//          Copyright (c) Siemens EDA, 1996-2021, All Rights Reserved.
//                        UNPUBLISHED, LICENSED SOFTWARE.
//             CONFIDENTIAL AND PROPRIETARY INFORMATION WHICH IS THE
//                   PROPERTY OF SIEMENS EDA OR ITS LICENSORS.
//  
//  Running on Linux rjujjav@lib-41917.eos.ncsu.edu 4.18.0-513.9.1.el8_9.x86_64 x86_64 aol
//  
//  Package information: SIFLIBS v23.7_0.0, HLS_PKGS v23.7_0.0, 
//                       SIF_TOOLKITS v23.7_0.0, SIF_XILINX v23.7_0.0, 
//                       SIF_ALTERA v23.7_0.0, CCS_LIBS v23.7_0.0, 
//                       CDS_PPRO v10.5a, CDS_DesigChecker v2021.1, 
//                       CDS_OASYS v20.1_3.6, CDS_PSR v20.2_1.8, 
//                       DesignPad v2.78_1.0
//  
solution new -state initial
solution options defaults
solution options set /Cache/UserCacheHome ../hls/catapult_cache
solution options set /Interface/DefaultResetClearsAllRegs yes
solution options set /Input/CppStandard c++11
solution options set /Input/CompilerFlags {-D_SYNTHESIS_ -DHLS_CATAPULT -DCONNECTIONS_ACCURATE_SIM -DSC_INCLUDE_DYNAMIC_PROCESSES }
solution options set /Input/SearchPath {. /mnt/coe/workspace/ece/ece720-common/tools/2020.05/matchlib/cmod /mnt/coe/workspace/ece/ece720-common/tools/2020.05/matchlib/cmod/include /mnt/coe/workspace/ece/ece720-common/tools/2020.05/matchlib/rapidjson/include /include}
solution options set /Output/OutputVHDL false
solution options set /Output/InlinedPropertyLang sva
solution options set /Flows/SCVerify/USE_QUESTASIM false
solution options set /Flows/SCVerify/USE_OSCI false
solution options set /Flows/SCVerify/USE_VCS true
solution options set /Flows/SCVerify/DISABLE_EMPTY_INPUTS true
solution options set /Flows/VCS/VCS_HOME {}
solution options set /Flows/VCS/VG_GNU_PACKAGE /gnu/linux
solution options set /Flows/VCS/VG_ENV64_SCRIPT source_me.csh
solution options set /Flows/VCS/SYSC_VERSION 2.3.2
solution file add ../sc/Accelerator.h -type CHEADER
directive set -LOGIC_OPT false
directive set -FSM_BINARY_ENCODING_THRESHOLD 64
directive set -REGISTER_SHARING_MAX_WIDTH_DIFFERENCE 8
directive set -CHAN_IO_PROTOCOL use_library
directive set -ARRAY_SIZE 1024
directive set -STALL_FLAG_SV off
directive set -STALL_FLAG false
directive set -READY_FLAG {}
directive set -ON_THE_FLY_PROTOTYPING false
directive set -CLUSTER_ADDTREE_IN_COUNT_THRESHOLD 0
directive set -PROTOTYPING_ENGINE oasys
directive set -DESIGN_GOAL area
directive set -SPECULATE true
directive set -MERGEABLE true
directive set -REGISTER_THRESHOLD 256
directive set -MEM_MAP_THRESHOLD 32
directive set -FSM_ENCODING none
directive set -REG_MAX_FANOUT 0
directive set -NO_X_ASSIGNMENTS true
directive set -SAFE_FSM false
directive set -REGISTER_SHARING_LIMIT 0
directive set -ASSIGN_OVERHEAD 0
directive set -TIMING_CHECKS true
directive set -MUXPATH true
directive set -REALLOC true
directive set -UNROLL no
directive set -IO_MODE super
directive set -IDLE_SIGNAL {}
directive set -TRANSACTION_DONE_SIGNAL true
directive set -DONE_FLAG {}
directive set -START_FLAG {}
directive set -TRANSACTION_SYNC ready
directive set -CLOCK_OVERHEAD 20.000000
directive set -OPT_CONST_MULTS use_library
directive set -CHARACTERIZE_ROM false
directive set -PROTOTYPE_ROM true
directive set -ROM_THRESHOLD 64
directive set -CLUSTER_ADDTREE_IN_WIDTH_THRESHOLD 0
directive set -CLUSTER_OPT_CONSTANT_INPUTS true
directive set -CLUSTER_RTL_SYN false
directive set -CLUSTER_FAST_MODE false
directive set -CLUSTER_TYPE combinational
directive set -PIPELINE_RAMP_UP true
go new
directive set -REGISTER_IDLE_SIGNAL false
directive set -RESET_CLEARS_ALL_REGS yes
go analyze
solution design set Accelerator -top
directive set -CLOCKS {clk {-CLOCK_PERIOD 2.0 -CLOCK_EDGE rising -CLOCK_UNCERTAINTY 0.0 -CLOCK_HIGH_TIME 1.0 -RESET_SYNC_NAME rst -RESET_ASYNC_NAME arst_n -RESET_KIND sync -RESET_SYNC_ACTIVE high -RESET_ASYNC_ACTIVE low -ENABLE_ACTIVE high}}
go compile
directive set -CLOCKS {clk {-CLOCK_PERIOD 2.0 -CLOCK_UNCERTAINTY 0.0 -CLOCK_HIGH_TIME 1.0}}
solution library add nangate-45nm_beh -- -rtlsyntool DesignCompiler -vendor Nangate -technology 045nm
solution library add ram_nangate-45nm-singleport_beh
go libraries
directive set /Accelerator/AxiSlaveToReg2<axi::cfg::standard,14,16>/run/reg:rsc -MAP_TO_MODULE {[Register]}
go architect
go extract
