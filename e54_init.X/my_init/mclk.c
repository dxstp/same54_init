// DOM-IGNORE-BEGIN
/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */
// DOM-IGNORE-END

#include <sam.h>
#include "mclk.h"

void MCLK_init(void) {
    MCLK_REGS->MCLK_AHBMASK =
            MCLK_AHBMASK_HPB0(1)
          | MCLK_AHBMASK_HPB1(1)
          | MCLK_AHBMASK_HPB2(1)
          | MCLK_AHBMASK_HPB3(1)
          | MCLK_AHBMASK_DSU(1)
          | MCLK_AHBMASK_HMATRIX(1)
          | MCLK_AHBMASK_NVMCTRL(1)
          | MCLK_AHBMASK_HSRAM(1)
          | MCLK_AHBMASK_CMCC(1)
          | MCLK_AHBMASK_DMAC(1)
          | MCLK_AHBMASK_USB(1)
          | MCLK_AHBMASK_BKUPRAM(1)
          | MCLK_AHBMASK_PAC(1)
          | MCLK_AHBMASK_QSPI(1)
          | MCLK_AHBMASK_GMAC(1)
          | MCLK_AHBMASK_SDHC0(1)
          | MCLK_AHBMASK_SDHC1(1)
          | MCLK_AHBMASK_CAN0(1)
          | MCLK_AHBMASK_CAN1(1)
          | MCLK_AHBMASK_ICM(1)
          | MCLK_AHBMASK_PUKCC(1)
          | MCLK_AHBMASK_QSPI_2X(1)
          | MCLK_AHBMASK_NVMCTRL_CACHE(1)
          | MCLK_AHBMASK_NVMCTRL_SMEEPROM(1);
	
    MCLK_REGS->MCLK_APBAMASK = 
            MCLK_APBAMASK_PAC(1)
          | MCLK_APBAMASK_PM(1)
          | MCLK_APBAMASK_MCLK(1)
          | MCLK_APBAMASK_RSTC(1)
          | MCLK_APBAMASK_OSCCTRL(1)
          | MCLK_APBAMASK_OSC32KCTRL(1)
          | MCLK_APBAMASK_SUPC(1)
          | MCLK_APBAMASK_GCLK(1)
          | MCLK_APBAMASK_WDT(1)
          | MCLK_APBAMASK_RTC(1)
          | MCLK_APBAMASK_EIC(1)
          | MCLK_APBAMASK_FREQM(1)
          | MCLK_APBAMASK_SERCOM0(1)
          | MCLK_APBAMASK_SERCOM1(1)
          | MCLK_APBAMASK_TC0(1)
          | MCLK_APBAMASK_TC1(1);
	
	MCLK_REGS->MCLK_APBBMASK =
            MCLK_APBBMASK_USB(0)
          | MCLK_APBBMASK_DSU(1)
          | MCLK_APBBMASK_NVMCTRL(1)
          | MCLK_APBBMASK_PORT(1)
          | MCLK_APBBMASK_HMATRIX(0)
          | MCLK_APBBMASK_EVSYS(1)
          | MCLK_APBBMASK_SERCOM2(0)
          | MCLK_APBBMASK_SERCOM3(0)
          | MCLK_APBBMASK_TCC0(0)
          | MCLK_APBBMASK_TCC1(0)
          | MCLK_APBBMASK_TC2(0)
          | MCLK_APBBMASK_TC3(0)
          | MCLK_APBBMASK_RAMECC(0);
   
    MCLK_REGS->MCLK_APBCMASK =
            MCLK_APBCMASK_GMAC(1)
          | MCLK_APBCMASK_TCC2(0)
          | MCLK_APBCMASK_TCC3(0)
          | MCLK_APBCMASK_TC4(1)
          | MCLK_APBCMASK_TC5(0)
          | MCLK_APBCMASK_PDEC(0)
          | MCLK_APBCMASK_AC(0)
          | MCLK_APBCMASK_AES(0)
          | MCLK_APBCMASK_TRNG(0)
          | MCLK_APBCMASK_ICM(0)
          | MCLK_APBCMASK_QSPI(0)
          | MCLK_APBCMASK_CCL(0);
	
	MCLK_REGS->MCLK_APBDMASK =
            MCLK_APBDMASK_SERCOM4(0)
          | MCLK_APBDMASK_SERCOM5(0)
          | MCLK_APBDMASK_SERCOM6(0)
          | MCLK_APBDMASK_SERCOM7(0)
          | MCLK_APBDMASK_TCC4(0)
          | MCLK_APBDMASK_TC6(0)
          | MCLK_APBDMASK_TC7(0)
          | MCLK_APBDMASK_ADC0(0)
          | MCLK_APBDMASK_ADC1(0)
          | MCLK_APBDMASK_DAC(0)
          | MCLK_APBDMASK_I2S(0)
          | MCLK_APBDMASK_PCC(0);
          
}