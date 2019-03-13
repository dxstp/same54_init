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

#define NVM_USER_WORD_0 \
	  (0x1   << FUSES_BOD33_DIS_Pos)\
	| (0x1C  << FUSES_BOD33USERLEVEL_Pos)\
	| (0x1   << FUSES_BOD33_ACTION_Pos)\
	| (0x2   << FUSES_BOD33_HYST_Pos)\
	| (0x535 << 15)\
	| (0xF   << NVMCTRL_FUSES_BOOTPROT_Pos)\
	| (0x3   << 30)
	
#define NVM_USER_WORD_1 \
	  (0x0   << NVMCTRL_FUSES_SEESBLK_Pos)\
	| (0x0   << NVMCTRL_FUSES_SEEPSZ_Pos)\
	| (0x1   << RAMECC_FUSES_ECCDIS_Pos)\
	| (0xFF  << 8)\
	| (0x0   << WDT_FUSES_ENABLE_Pos)\
	| (0x0   << WDT_FUSES_ALWAYSON_Pos)\
	| (0xB   << WDT_FUSES_PER_Pos)\
	| (0xB   << WDT_FUSES_WINDOW_Pos)\
	| (0xB   << WDT_FUSES_EWOFFSET_Pos)\
	| (0x0   << WDT_FUSES_WEN_Pos)\
	| (0x1   << 31)

// region lock bits
#define NVM_USER_WORD_2 \
	  0xFFFFFFFF

// user page
#define NVM_USER_WORD_3 \
	  0xFFFFFFFF
	  
// factory settings - do not change
#define NVM_USER_WORD_4 \
	  0x00804010

// user page
#define NVM_USER_WORD_5 \
	  0xFFFFFFFF
	  
// user page
#define NVM_USER_WORD_6 \
	  0xFFFFFFFF
	  
// user page
#define NVM_USER_WORD_7 \
	  0xFFFFFFFF

__attribute__((section(".userrow"))) const uint32_t nvm_user_row[8] = {
	NVM_USER_WORD_0,
	NVM_USER_WORD_1,
	NVM_USER_WORD_2,
	NVM_USER_WORD_3,
	NVM_USER_WORD_4,
	NVM_USER_WORD_5,
	NVM_USER_WORD_6,
	NVM_USER_WORD_7
};

/* Bugfix for DFP 1.0.87:
 * For E54 device, you can get the atdf file in the following installation path:
 * C:\Program Files (x86)\Atmel\Studio\7.0\packs\atmel\SAME54_DFP\1.0.87\atdf
 *
 * Select the atdf file (for 1.0.87) corresponding to the target device and
 * under the mapping section <devices>, please add the following line of code.
 *
 * <memory-segment name="AUX0" start="0x00804000" size="0x200" type="user_page" pagesize="16" rw="RW"/>
 *
 * Restart your Atmel Studio to apply the changes. 
*/

__attribute__((section(".userpage"))) const char nvm_user_page[] = 
	"NVM User Page Mapping: The NVM User Page can be read at address 0x00804000. "
	"The size of the NVM User Page is 512 Bytes. The first eight 32-bit words "
	"(32 Bytes) of the Non Volatile Memory (NVM) User Page contain calibration "
	"data that are automatically read at device power on. The remaining 480 "
	"Bytes can be used for storing custom parameters. To write the NVM User "
	"Page, refer to the NVMCTRL (Non-Volatile Memory Controller) documentation. "
	"SAM D5x/E5x Family Data Sheet, page 57.";
