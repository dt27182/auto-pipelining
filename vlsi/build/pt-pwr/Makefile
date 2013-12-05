#=======================================================================
# UCB VLSI FLOW: Makefile for pt-pwr
#-----------------------------------------------------------------------
# Yunsup Lee (yunsup@cs.berkeley.edu)
#
# This makefile will use Synopsys PrimeTime to check timing and analyze
# power of your gate-level verilog netlist.
#

default: all

base_dir = $(abspath ../../..)
vlsi_dir = $(abspath ../..)
build_dir = $(abspath ..)
sim_dir = $(abspath ../vcs-sim-gl-par)

include $(base_dir)/Makefrag
include $(build_dir)/Makefrag
include $(build_dir)/dc-syn/Makefrag
include $(build_dir)/icc-par/Makefrag
include $(build_dir)/vcs-sim-gl-par/Makefrag
include $(build_dir)/Makefrag-sim
include $(build_dir)/pt-pwr/Makefrag

#--------------------------------------------------------------------
# Default make target
#--------------------------------------------------------------------

.PHONY: pt

pt_median = $(pt_cur_build_dir)/$(pt_reports_dir)/median.riscv.power.avg.max.report
pt_multiply = $(pt_cur_build_dir)/$(pt_reports_dir)/multiply.riscv.power.avg.max.report
pt_qsort = $(pt_cur_build_dir)/$(pt_reports_dir)/qsort.riscv.power.avg.max.report
pt_towers = $(pt_cur_build_dir)/$(pt_reports_dir)/towers.riscv.power.avg.max.report
pt_vvadd = $(pt_cur_build_dir)/$(pt_reports_dir)/vvadd.riscv.power.avg.max.report
pt_dhrystone = $(pt_cur_build_dir)/$(pt_reports_dir)/dhrystone.riscv.power.avg.max.report

all: $(pt_median) $(pt_multiply) $(pt_qsort) $(pt_towers) $(pt_vvadd) $(pt_dhrystone) 
  

#--------------------------------------------------------------------
# Clean up
#--------------------------------------------------------------------

junk +=

clean:
	rm -rf build* current* $(junk) *~ \#*
