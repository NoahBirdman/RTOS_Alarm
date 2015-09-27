################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
MSP_EXP432P401RLP.obj: ../MSP_EXP432P401RLP.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/birdman/ti/ccsv6/ccs_base/arm/include" --include_path="/home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include" --include_path="/home/birdman/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/driverlib/MSP432P4xx" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="MSP_EXP432P401RLP.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

empty.obj: ../empty.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/birdman/ti/ccsv6/ccs_base/arm/include" --include_path="/home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include" --include_path="/home/birdman/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/driverlib/MSP432P4xx" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_wrap=off --gen_func_subsections=on --preproc_with_compile --preproc_dependency="empty.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../empty.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/home/birdman/ti/xdctools_3_31_00_24_core/xs" --xdcpath="/home/birdman/ti/tirtos_msp43x_2_12_01_33/packages;/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/bios_6_41_04_54/packages;/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/uia_2_00_02_39/packages;/home/birdman/ti/ccsv6/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.msp432:MSP432P401R -r release -c "/home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4" --compileOptions "-mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path=\"/home/birdman/ti/ccsv6/ccs_base/arm/include\" --include_path=\"/home/birdman/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.4/include\" --include_path=\"/home/birdman/ti/ccsv6/ccs_base/arm/include/CMSIS\" --include_path=\"/home/birdman/ti/tirtos_msp43x_2_12_01_33/products/MSPWare_2_00_00_40a/driverlib/MSP432P4xx\" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --display_error_number --diag_warning=225 --diag_wrap=off --gen_func_subsections=on  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd


