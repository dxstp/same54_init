#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/e54_init.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/e54_init.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=my_init/ac.c my_init/adc.c my_init/ccl.c my_init/dac.c my_init/dpll.c my_init/evsys.c my_init/gclk.c my_init/gpio.c my_init/irqs.c my_init/mclk.c my_init/oscctrl.c my_init/pm.c my_init/pwm.c my_init/rtc.c my_init/sercom.c my_init/supc.c utils/delay.c utils/print.c main.c my_init/configbits.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/my_init/ac.o ${OBJECTDIR}/my_init/adc.o ${OBJECTDIR}/my_init/ccl.o ${OBJECTDIR}/my_init/dac.o ${OBJECTDIR}/my_init/dpll.o ${OBJECTDIR}/my_init/evsys.o ${OBJECTDIR}/my_init/gclk.o ${OBJECTDIR}/my_init/gpio.o ${OBJECTDIR}/my_init/irqs.o ${OBJECTDIR}/my_init/mclk.o ${OBJECTDIR}/my_init/oscctrl.o ${OBJECTDIR}/my_init/pm.o ${OBJECTDIR}/my_init/pwm.o ${OBJECTDIR}/my_init/rtc.o ${OBJECTDIR}/my_init/sercom.o ${OBJECTDIR}/my_init/supc.o ${OBJECTDIR}/utils/delay.o ${OBJECTDIR}/utils/print.o ${OBJECTDIR}/main.o ${OBJECTDIR}/my_init/configbits.o
POSSIBLE_DEPFILES=${OBJECTDIR}/my_init/ac.o.d ${OBJECTDIR}/my_init/adc.o.d ${OBJECTDIR}/my_init/ccl.o.d ${OBJECTDIR}/my_init/dac.o.d ${OBJECTDIR}/my_init/dpll.o.d ${OBJECTDIR}/my_init/evsys.o.d ${OBJECTDIR}/my_init/gclk.o.d ${OBJECTDIR}/my_init/gpio.o.d ${OBJECTDIR}/my_init/irqs.o.d ${OBJECTDIR}/my_init/mclk.o.d ${OBJECTDIR}/my_init/oscctrl.o.d ${OBJECTDIR}/my_init/pm.o.d ${OBJECTDIR}/my_init/pwm.o.d ${OBJECTDIR}/my_init/rtc.o.d ${OBJECTDIR}/my_init/sercom.o.d ${OBJECTDIR}/my_init/supc.o.d ${OBJECTDIR}/utils/delay.o.d ${OBJECTDIR}/utils/print.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/my_init/configbits.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/my_init/ac.o ${OBJECTDIR}/my_init/adc.o ${OBJECTDIR}/my_init/ccl.o ${OBJECTDIR}/my_init/dac.o ${OBJECTDIR}/my_init/dpll.o ${OBJECTDIR}/my_init/evsys.o ${OBJECTDIR}/my_init/gclk.o ${OBJECTDIR}/my_init/gpio.o ${OBJECTDIR}/my_init/irqs.o ${OBJECTDIR}/my_init/mclk.o ${OBJECTDIR}/my_init/oscctrl.o ${OBJECTDIR}/my_init/pm.o ${OBJECTDIR}/my_init/pwm.o ${OBJECTDIR}/my_init/rtc.o ${OBJECTDIR}/my_init/sercom.o ${OBJECTDIR}/my_init/supc.o ${OBJECTDIR}/utils/delay.o ${OBJECTDIR}/utils/print.o ${OBJECTDIR}/main.o ${OBJECTDIR}/my_init/configbits.o

# Source Files
SOURCEFILES=my_init/ac.c my_init/adc.c my_init/ccl.c my_init/dac.c my_init/dpll.c my_init/evsys.c my_init/gclk.c my_init/gpio.c my_init/irqs.c my_init/mclk.c my_init/oscctrl.c my_init/pm.c my_init/pwm.c my_init/rtc.c my_init/sercom.c my_init/supc.c utils/delay.c utils/print.c main.c my_init/configbits.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/e54_init.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAME54P20A
MP_LINKER_FILE_OPTION=,--script="ATSAME54P20A.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/my_init/ac.o: my_init/ac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/ac.o.d 
	@${RM} ${OBJECTDIR}/my_init/ac.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/ac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/ac.o.d" -o ${OBJECTDIR}/my_init/ac.o my_init/ac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/adc.o: my_init/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/adc.o.d 
	@${RM} ${OBJECTDIR}/my_init/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/adc.o.d" -o ${OBJECTDIR}/my_init/adc.o my_init/adc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/ccl.o: my_init/ccl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/ccl.o.d 
	@${RM} ${OBJECTDIR}/my_init/ccl.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/ccl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/ccl.o.d" -o ${OBJECTDIR}/my_init/ccl.o my_init/ccl.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/dac.o: my_init/dac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/dac.o.d 
	@${RM} ${OBJECTDIR}/my_init/dac.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/dac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/dac.o.d" -o ${OBJECTDIR}/my_init/dac.o my_init/dac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/dpll.o: my_init/dpll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/dpll.o.d 
	@${RM} ${OBJECTDIR}/my_init/dpll.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/dpll.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/dpll.o.d" -o ${OBJECTDIR}/my_init/dpll.o my_init/dpll.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/evsys.o: my_init/evsys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/evsys.o.d 
	@${RM} ${OBJECTDIR}/my_init/evsys.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/evsys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/evsys.o.d" -o ${OBJECTDIR}/my_init/evsys.o my_init/evsys.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/gclk.o: my_init/gclk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/gclk.o.d 
	@${RM} ${OBJECTDIR}/my_init/gclk.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/gclk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/gclk.o.d" -o ${OBJECTDIR}/my_init/gclk.o my_init/gclk.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/gpio.o: my_init/gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/gpio.o.d 
	@${RM} ${OBJECTDIR}/my_init/gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/gpio.o.d" -o ${OBJECTDIR}/my_init/gpio.o my_init/gpio.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/irqs.o: my_init/irqs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/irqs.o.d 
	@${RM} ${OBJECTDIR}/my_init/irqs.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/irqs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/irqs.o.d" -o ${OBJECTDIR}/my_init/irqs.o my_init/irqs.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/mclk.o: my_init/mclk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/mclk.o.d 
	@${RM} ${OBJECTDIR}/my_init/mclk.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/mclk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/mclk.o.d" -o ${OBJECTDIR}/my_init/mclk.o my_init/mclk.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/oscctrl.o: my_init/oscctrl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/oscctrl.o.d 
	@${RM} ${OBJECTDIR}/my_init/oscctrl.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/oscctrl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/oscctrl.o.d" -o ${OBJECTDIR}/my_init/oscctrl.o my_init/oscctrl.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/pm.o: my_init/pm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/pm.o.d 
	@${RM} ${OBJECTDIR}/my_init/pm.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/pm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/pm.o.d" -o ${OBJECTDIR}/my_init/pm.o my_init/pm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/pwm.o: my_init/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/pwm.o.d 
	@${RM} ${OBJECTDIR}/my_init/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/pwm.o.d" -o ${OBJECTDIR}/my_init/pwm.o my_init/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/rtc.o: my_init/rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/rtc.o.d 
	@${RM} ${OBJECTDIR}/my_init/rtc.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/rtc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/rtc.o.d" -o ${OBJECTDIR}/my_init/rtc.o my_init/rtc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/sercom.o: my_init/sercom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/sercom.o.d 
	@${RM} ${OBJECTDIR}/my_init/sercom.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/sercom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/sercom.o.d" -o ${OBJECTDIR}/my_init/sercom.o my_init/sercom.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/supc.o: my_init/supc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/supc.o.d 
	@${RM} ${OBJECTDIR}/my_init/supc.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/supc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/supc.o.d" -o ${OBJECTDIR}/my_init/supc.o my_init/supc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/utils/delay.o: utils/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/delay.o.d 
	@${RM} ${OBJECTDIR}/utils/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/utils/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/utils/delay.o.d" -o ${OBJECTDIR}/utils/delay.o utils/delay.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/utils/print.o: utils/print.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/print.o.d 
	@${RM} ${OBJECTDIR}/utils/print.o 
	@${FIXDEPS} "${OBJECTDIR}/utils/print.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/utils/print.o.d" -o ${OBJECTDIR}/utils/print.o utils/print.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/configbits.o: my_init/configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/configbits.o.d 
	@${RM} ${OBJECTDIR}/my_init/configbits.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/configbits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/configbits.o.d" -o ${OBJECTDIR}/my_init/configbits.o my_init/configbits.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/my_init/ac.o: my_init/ac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/ac.o.d 
	@${RM} ${OBJECTDIR}/my_init/ac.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/ac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/ac.o.d" -o ${OBJECTDIR}/my_init/ac.o my_init/ac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/adc.o: my_init/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/adc.o.d 
	@${RM} ${OBJECTDIR}/my_init/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/adc.o.d" -o ${OBJECTDIR}/my_init/adc.o my_init/adc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/ccl.o: my_init/ccl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/ccl.o.d 
	@${RM} ${OBJECTDIR}/my_init/ccl.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/ccl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/ccl.o.d" -o ${OBJECTDIR}/my_init/ccl.o my_init/ccl.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/dac.o: my_init/dac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/dac.o.d 
	@${RM} ${OBJECTDIR}/my_init/dac.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/dac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/dac.o.d" -o ${OBJECTDIR}/my_init/dac.o my_init/dac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/dpll.o: my_init/dpll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/dpll.o.d 
	@${RM} ${OBJECTDIR}/my_init/dpll.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/dpll.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/dpll.o.d" -o ${OBJECTDIR}/my_init/dpll.o my_init/dpll.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/evsys.o: my_init/evsys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/evsys.o.d 
	@${RM} ${OBJECTDIR}/my_init/evsys.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/evsys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/evsys.o.d" -o ${OBJECTDIR}/my_init/evsys.o my_init/evsys.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/gclk.o: my_init/gclk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/gclk.o.d 
	@${RM} ${OBJECTDIR}/my_init/gclk.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/gclk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/gclk.o.d" -o ${OBJECTDIR}/my_init/gclk.o my_init/gclk.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/gpio.o: my_init/gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/gpio.o.d 
	@${RM} ${OBJECTDIR}/my_init/gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/gpio.o.d" -o ${OBJECTDIR}/my_init/gpio.o my_init/gpio.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/irqs.o: my_init/irqs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/irqs.o.d 
	@${RM} ${OBJECTDIR}/my_init/irqs.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/irqs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/irqs.o.d" -o ${OBJECTDIR}/my_init/irqs.o my_init/irqs.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/mclk.o: my_init/mclk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/mclk.o.d 
	@${RM} ${OBJECTDIR}/my_init/mclk.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/mclk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/mclk.o.d" -o ${OBJECTDIR}/my_init/mclk.o my_init/mclk.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/oscctrl.o: my_init/oscctrl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/oscctrl.o.d 
	@${RM} ${OBJECTDIR}/my_init/oscctrl.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/oscctrl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/oscctrl.o.d" -o ${OBJECTDIR}/my_init/oscctrl.o my_init/oscctrl.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/pm.o: my_init/pm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/pm.o.d 
	@${RM} ${OBJECTDIR}/my_init/pm.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/pm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/pm.o.d" -o ${OBJECTDIR}/my_init/pm.o my_init/pm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/pwm.o: my_init/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/pwm.o.d 
	@${RM} ${OBJECTDIR}/my_init/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/pwm.o.d" -o ${OBJECTDIR}/my_init/pwm.o my_init/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/rtc.o: my_init/rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/rtc.o.d 
	@${RM} ${OBJECTDIR}/my_init/rtc.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/rtc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/rtc.o.d" -o ${OBJECTDIR}/my_init/rtc.o my_init/rtc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/sercom.o: my_init/sercom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/sercom.o.d 
	@${RM} ${OBJECTDIR}/my_init/sercom.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/sercom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/sercom.o.d" -o ${OBJECTDIR}/my_init/sercom.o my_init/sercom.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/supc.o: my_init/supc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/supc.o.d 
	@${RM} ${OBJECTDIR}/my_init/supc.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/supc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/supc.o.d" -o ${OBJECTDIR}/my_init/supc.o my_init/supc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/utils/delay.o: utils/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/delay.o.d 
	@${RM} ${OBJECTDIR}/utils/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/utils/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/utils/delay.o.d" -o ${OBJECTDIR}/utils/delay.o utils/delay.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/utils/print.o: utils/print.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/utils" 
	@${RM} ${OBJECTDIR}/utils/print.o.d 
	@${RM} ${OBJECTDIR}/utils/print.o 
	@${FIXDEPS} "${OBJECTDIR}/utils/print.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/utils/print.o.d" -o ${OBJECTDIR}/utils/print.o utils/print.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/my_init/configbits.o: my_init/configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/my_init" 
	@${RM} ${OBJECTDIR}/my_init/configbits.o.d 
	@${RM} ${OBJECTDIR}/my_init/configbits.o 
	@${FIXDEPS} "${OBJECTDIR}/my_init/configbits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/my_init/configbits.o.d" -o ${OBJECTDIR}/my_init/configbits.o my_init/configbits.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/e54_init.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ATSAME54P20A.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/e54_init.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/e54_init.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ATSAME54P20A.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/e54_init.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/e54_init.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
