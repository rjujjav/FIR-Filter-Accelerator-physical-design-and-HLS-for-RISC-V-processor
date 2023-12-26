#! /bin/csh -f
setenv SYSTEMC_HOME /mnt/coe/workspace/ece/ece720-common/tools/catapult2021.1/Mgc_home/shared
setenv SYSTEMC_LIB_DIR /mnt/coe/workspace/ece/ece720-common/tools/catapult2021.1/Mgc_home/shared/lib
setenv CXX_FLAGS "-g -DCALYPTO_SKIP_SYSTEMC_VERSION_CHECK"
setenv LD_FLAGS "-lpthread"
setenv OSSIM ddd
setenv PATH /mnt/coe/workspace/ece/ece720-common/tools/catapult2021.1/Mgc_home/bin:$PATH
