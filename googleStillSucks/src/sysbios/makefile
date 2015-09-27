
XOPTS = -I"/home/birdman/ti/xdctools_3_31_00_24_core/packages/" -Dxdc_target_types__=/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/targets/arm/elf/std.h -Dxdc_target_name__=M4F

vpath % /home/birdman/ti/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/sysbios/
vpath %.c /home/birdman/ti/xdctools_3_31_00_24_core/packages/

CCOPTS    = --endian=little -mv7M4 --abi=eabi --float_support=fpv4spd16 -q -ms --opt_for_speed=2  --program_level_compile -o3 -g --optimize_with_debug  -Dti_sysbios_family_arm_m3_Hwi_enableException__D=TRUE -Dti_sysbios_family_arm_m3_Hwi_disablePriority__D=32U -Dti_sysbios_family_arm_m3_Hwi_numSparseInterrupts__D=0U

XDC_ROOT  = /home/birdman/ti/xdctools_3_31_00_24_core/packages/

BIOS_ROOT = /home/birdman/ti/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/ti/sysbios/

BIOS_DEFS =  -Dti_sysbios_BIOS_swiEnabled__D=TRUE -Dti_sysbios_BIOS_taskEnabled__D=TRUE -Dti_sysbios_BIOS_clockEnabled__D=TRUE -Dti_sysbios_BIOS_runtimeCreatesEnabled__D=TRUE -Dti_sysbios_hal_Hwi_DISABLE_ALL_HOOKS -Dti_sysbios_knl_Swi_DISABLE_ALL_HOOKS -Dti_sysbios_knl_Task_DISABLE_ALL_HOOKS -Dti_sysbios_BIOS_smpEnabled__D=FALSE -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_knl_Swi_numPriorities__D=16 -Dti_sysbios_knl_Task_deleteTerminatedTasks__D=FALSE -Dti_sysbios_knl_Task_numPriorities__D=16 -Dti_sysbios_knl_Task_checkStackFlag__D=TRUE -Dti_sysbios_knl_Clock_TICK_SOURCE=ti_sysbios_knl_Clock_TickSource_TIMER -Dti_sysbios_knl_Clock_TICK_MODE=ti_sysbios_knl_Clock_TickMode_PERIODIC -Dti_sysbios_hal_Core_delegate_getId=ti_sysbios_hal_CoreNull_getId__E -Dti_sysbios_hal_Core_delegate_interruptCore=ti_sysbios_hal_CoreNull_interruptCore__E -Dti_sysbios_hal_Core_delegate_lock=ti_sysbios_hal_CoreNull_lock__E -Dti_sysbios_hal_Core_delegate_unlock=ti_sysbios_hal_CoreNull_unlock__E -Dti_sysbios_hal_Core_numCores__D=1 -Dti_sysbios_hal_CoreNull_numCores__D=1 -Dti_sysbios_utils_Load_taskEnabled__D=FALSE -Dti_sysbios_utils_Load_swiEnabled__D=FALSE -Dti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__D=TRUE -Dti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__D=TRUE -Dti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__D=TRUE -Dti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__D=TRUE -Dti_sysbios_knl_Semaphore_supportsEvents__D=FALSE -Dti_sysbios_knl_Semaphore_supportsPriority__D=TRUE

BIOS_INC  = -I"/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/"

TARGET_INC = -I"/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages/"

INCS = $(BIOS_INC) $(TARGET_INC)  --include_path="/home/birdman/ti/ccsv6/ccs_base/arm/include" --include_path="/home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include" --include_path="/home/birdman/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/driverlib/MSP432P4xx" 

CC = /home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/bin/armcl -c $(CCOPTS) -I /home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include
ASM = /home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/bin/armcl -c $(CCOPTS) -I /home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include
AR = /home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/bin/armar rq

DEL = rm -f
CP = cp -f

define RM
	$(if $(wildcard $1),$(DEL) $1,:)
endef

define ASSEMBLE
	@echo asmem4f $< ...
	@$(ASM) $(BIOS_DEFS) $(XOPTS) $(INCS) $<
endef

all: sysbios.aem4f

m3_Hwi_asm.obj: family/arm/m3/Hwi_asm.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=m3_Hwi_asm.obj

m3_Hwi_asm_switch.obj: family/arm/m3/Hwi_asm_switch.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=m3_Hwi_asm_switch.obj

m3_IntrinsicsSupport_asm.obj: family/arm/m3/IntrinsicsSupport_asm.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=m3_IntrinsicsSupport_asm.obj

m3_TaskSupport_asm.obj: family/arm/m3/TaskSupport_asm.sv7M makefile
	@-$(call RM, $@)
	$(ASSEMBLE) --output_file=m3_TaskSupport_asm.obj


BIOS.obj: BIOS.c family/arm/msp432/init/Boot.c knl/Clock.c knl/Idle.c knl/Intrinsics.c knl/Event.c knl/Queue.c knl/Semaphore.c knl/Swi.c knl/Swi_andn.c knl/Task.c hal/Hwi.c hal/Hwi_stack.c hal/Hwi_startup.c heaps/HeapMem.c family/arm/m3/Hwi.c family/arm/m3/TaskSupport.c family/arm/m3/Timer.c family/arm/m3/TimestampProvider.c gates/GateHwi.c gates/GateMutex.c family/arm/msp432/Timer.c family/arm/msp432/ClockFreqs.c utils/Load.c utils/Load_CPU.c makefile
	@-$(call RM, $@)
	@echo clem4f $< ...
	@$(CC) $(BIOS_DEFS) $(XOPTS) $(INCS) \
	$(BIOS_ROOT)BIOS.c \
	$(BIOS_ROOT)family/arm/msp432/init/Boot.c \
	$(BIOS_ROOT)knl/Clock.c \
	$(BIOS_ROOT)knl/Idle.c \
	$(BIOS_ROOT)knl/Intrinsics.c \
	$(BIOS_ROOT)knl/Event.c \
	$(BIOS_ROOT)knl/Queue.c \
	$(BIOS_ROOT)knl/Semaphore.c \
	$(BIOS_ROOT)knl/Swi.c \
	$(BIOS_ROOT)knl/Swi_andn.c \
	$(BIOS_ROOT)knl/Task.c \
	$(BIOS_ROOT)hal/Hwi.c \
	$(BIOS_ROOT)hal/Hwi_stack.c \
	$(BIOS_ROOT)hal/Hwi_startup.c \
	$(BIOS_ROOT)heaps/HeapMem.c \
	$(BIOS_ROOT)family/arm/m3/Hwi.c \
	$(BIOS_ROOT)family/arm/m3/TaskSupport.c \
	$(BIOS_ROOT)family/arm/m3/Timer.c \
	$(BIOS_ROOT)family/arm/m3/TimestampProvider.c \
	$(BIOS_ROOT)gates/GateHwi.c \
	$(BIOS_ROOT)gates/GateMutex.c \
	$(BIOS_ROOT)family/arm/msp432/Timer.c \
	$(BIOS_ROOT)family/arm/msp432/ClockFreqs.c \
	$(BIOS_ROOT)utils/Load.c \
	$(BIOS_ROOT)utils/Load_CPU.c \

sysbios.aem4f: BIOS.obj m3_Hwi_asm.obj m3_Hwi_asm_switch.obj m3_IntrinsicsSupport_asm.obj m3_TaskSupport_asm.obj
	@-$(call RM, $@)
	@echo arem4f $^ ...
	@$(AR) $@ $^


clean:
	@-$(call RM, sysbios.aem4f)
	@-$(call RM, BIOS.obj)
	@-$(call RM, m3_Hwi_asm.obj)
	@-$(call RM, m3_Hwi_asm_switch.obj)
	@-$(call RM, m3_IntrinsicsSupport_asm.obj)
	@-$(call RM, m3_TaskSupport_asm.obj)
