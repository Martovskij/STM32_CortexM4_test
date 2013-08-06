#ifndef _CS43_H
#define _CS43_H

#include "main.h"


//Address
#define DAC_ADDR                    0x94
#define BUFFER_SIZE              0xff
/* -------------------------- REGISTER ADDRESS ------------------------------*/

#define CHIP_ID                     0x01
#define POWER_CONTROL_1             0x02
#define POWER_CONTROL_2             0x04
#define CLOCKING_CONTROL            0x05
#define INTERFACE_CONTROL1          0x06
#define INTERFACE_CONTROL2          0x07
#define PASSTHROUGH_PASS_A          0x08
#define PASSTHROUGH_PASS_B          0x09
#define ANALOG_SETTINGS             0x0A
#define PASSTHROUGH_GAIN_CONTR      0x0C
#define PLAYBACK_CONTROL_1          0x0D
#define MISC_CONTROLS               0x0E
#define PLAYBACK_CONTROL_2          0x0F
#define PASS_A_VOLUME               0x14
#define PASS_B_VOLUME               0x15
#define PCMA_VOLUME                 0x1A
#define PCMB_VOLUME                 0x1B
#define BEEP_FREQ                   0x1C
#define BEEP_VOLUME                 0x1D
#define TONE_CONTROL                0x1F
#define MASTER_VOL_A                0x20
#define MASTER_VOL_B                0x21
#define HEADPHONE_VOL_CONTROL_A     0x22
#define HEADPHONE_VOL_CONTROL_B     0x23
#define SPEAKER_VOL_CONTROL_A       0x24
#define SPEAKER_VOL_CONTROL_B       0x25
#define PCM_CHANNEL_SWAP            0x26
#define LIMITER_CONTROL_1           0x27
#define LIMITER_CONTROL_2           0x28
#define LIMITER_ATACK_RATE          0x29
#define STATUS                      0x2E
#define BATTERY_COMPENSATION        0x2F
#define VP_BATT_LEVEL               0x30
#define CHARGE_PUMP_FREQ            0x31

/*--------------------------------- BITMASK ----------------------------------*/

// POWER CONTROL  1

#define POWER_DOWN                     (uint8_t)0b00000001
#define POWER_UP                       (uint8_t)0b10011110

// POWER CONTROL 2

#define HEADPH_ALWAYS_ON_A             (uint8_t)0b00100000 
#define HEADPH_ALWAYS_OFF_A            (uint8_t)0b00110000
#define HEADPH_ON_WHEN_SPK_IS_LOW_A    (uint8_t)0b00000000
#define HEADPH_ON_WHEN_SPK_IS_HIGH_A   (uint8_t)0b00010000
#define HEADPH_ALWAYS_ON_B             (uint8_t)0b10000000 
#define HEADPH_ALWAYS_OFF_B            (uint8_t)0b11000000
#define HEADPH_ON_WHEN_SPK_IS_LOW_B    (uint8_t)0b00000000
#define HEADPH_ON_WHEN_SPK_IS_HIGH_B   (uint8_t)0b00010000

#define SPK_ALWAYS_ON_A                (uint8_t)0b00000010
#define SPK_ALWAYS_OFF_A               (uint8_t)0b00000011
#define SPK_ON_WHEN_HP_LOW_A           (uint8_t)0b00000000
#define SPK_ON_WHEN_HP_HIGH_A          (uint8_t)0b00000001
#define SPK_ALWAYS_ON_B                (uint8_t)0b00001000
#define SPK_ALWAYS_OFF_B               (uint8_t)0b00001100
#define SPK_ON_WHEN_HP_LOW_B           (uint8_t)0b00000000
#define SPK_ON_WHEN_HP_HIGH_B          (uint8_t)0b00000100

// CLOCKING CONTROL 

#define AUTO_DETECT_SPEED              (uint8_t)0b10000000
#define DOUBLE_SPEED                   (uint8_t)0b00000000
#define SINGLE_SPEED                   (uint8_t)0b01000000
#define HALF_SPEED                     (uint8_t)0b10000000
#define QUARTER_SPEED                  (uint8_t)0b11000000
#define SAMPLE_RATE_32kHz_YES          (uint8_t)0b00010000            
#define SAMPLE_RATE_32kHZ_NO           (uint8_t)0b00000000
#define VIDEO_CLOCK_27MHz_YES          (uint8_t)0b00001000
#define VIDEO_CLOCK_27MHz_NO           (uint8_t)0b00000000
#define INTERNAL_CLOCK_RATIO_00        (uint8_t)0b00000000        
#define INTERNAL_CLOCK_RATIO_01        (uint8_t)0b00000010
#define INTERNAL_CLOCK_RATIO_10        (uint8_t)0b00000100
#define INTERNAL_CLOCK_RADIO_11        (uint8_t)0b00000110
#define MCLK_DIVIDE_BY_2               (uint8_t)0b00000001 

// INTERFACE CONTROL 1

#define MASTER_MODE                    (uint8_t)0b10000000 
#define SLAVE_MODE                     (uint8_t)0b00000000
#define CLK_POLAR_INVERTED             (uint8_t)0b01000000
#define CLK_POLAR_NOTINVERTED          (uint8_t)0b00000000
#define DSP_MODE                       (uint8_t)0b00010000
#define LEFT_JUSTIFIED_24BIT           (uint8_t)0b00000000
#define RIGHT_JUSTIFIED_24BIT          (uint8_t)0b00000100 
#define RIGHT_JUSTIFIED                (uint8_t)0b00001000 
#define WORD_LENGTH_24BIT              (uint8_t)0b00000000
#define WORD_LENGTH_20BIT              (uint8_t)0b00000001
#define WORD_LENGHT_18BIT              (uint8_t)0b00000010
#define WORD_LENGHT_16BIT              (uint8_t)0b00000011


// INTERFACE CONTROL 2

#define OUTPUT_CLK                     (uint8_t)0b01000000
#define OUTPUT_SIGNAL_INVERT           (uint8_t)0b00001000



// PASSTHROUGH 

#define NO_INPUTS                      (uint8_t)0b00000000 
#define AIN1x                          (uint8_t)0b00000001
#define AIN2x                          (uint8_t)0b00000010
#define AIN3x                          (uint8_t)0b00000100
#define AIN4x                          (uint8_t)0b00001000

// ANALOG SETTINGS

#define SOFT_RAMP_B                    (uint8_t)0b00001000 
#define SOFT_RAMP_A                    (uint8_t)0b00000010


// PASSTHROUGH GAIN CONTROL

#define PASSTHROUGH_GAIN_CONTROL       (uint8_t)0b10000000



// PLAYBACK CONTROL  1
 
#define HP_GAIN_000                    (uint8_t)0b00000000
#define HP_GAIN_001                    (uint8_t)0b00100000
#define HP_GAIN_010                    (uint8_t)0b01000000 
#define HP_GAIN_011                    (uint8_t)0b01100000 
#define HP_GAIN_100                    (uint8_t)0b10000000
#define HP_GAIN_101                    (uint8_t)0b10100000
#define HP_GAIN_110                    (uint8_t)0b11000000
#define HP_GAIN_111                    (uint8_t)0b11100000
#define PLAYBACK_VOL_CONTROL           (uint8_t)0b00010000
#define INVERT_PCMB                    (uint8_t)0b00001000
#define INVERT_PCMA                    (uint8_t)0b00000100
#define MASTER_PLAYBACK_MUTE_B         (uint8_t)0b00000010
#define MASTER_PLAYBACK_MUTE_A         (uint8_t)0b00000001

// MISC CONTROLS 


#define  PASSTHRUB                     (uint8_t)0b10000000
#define  PASSTHRUA                     (uint8_t)0b01000000
#define  PASSBMUTE                     (uint8_t)0b00100000
#define  PASSAMUTE                     (uint8_t)0b00010000
#define  FREEZE                        (uint8_t)0b00001000
#define  DEMPH                         (uint8_t)0b00000100
#define  DIGSFT                        (uint8_t)0b00000010
#define  DIGZC                         (uint8_t)0b00000000

// PLAYBACK CONTROL 2

#define  HPBMUTE                       (uint8_t)0b10000000
#define  HPAMUTE                       (uint8_t)0b01000000
#define  SPKBMUTE                      (uint8_t)0b00100000
#define  SPKAMUTE                      (uint8_t)0b00010000
#define  ALL_SPK_MUTE                  (uint8_t)0b00001000
#define  SPK_SWAP                      (uint8_t)0b00000100
#define  SPK_MONO                      (uint8_t)0b00000010
#define  MUTE_50BY50                   (uint8_t)0b00000001

// PCM CHANNEL SWAP
#define  PCM_SWAP_LEFT_A                    (uint8_t)0b00000000
#define  PCM_SWAP_LEFT_RIGHT_A_DIVIDE_BY2   (uint8_t)0b01000000
#define  PCM_SWAP_RIGHT_A                   (uint8_t)0b11000000
#define  PCM_SWAP_LEFT_B                    (uint8_t)0b00000000
#define  PCM_SWAP_LEFT_RIGHT_B_DIVIDE_BY2   (uint8_t)0b00010000
#define  PCM_SWAP_RIGHT_B                   (uint8_t)0b00110000


// STATUS

#define  SPCLK_ERR                          (uint8_t)0b01000000
#define  DSP_A_ENGINE_OVERFLOW              (uint8_t)0b00100000
#define  DSP_B_ENGINE_OVERFLOW              (uint8_t)0b00010000
#define  PCM_A_OVERFLOW                     (uint8_t)0b00001000
#define  PCM_B_OVERFLOW                     (uint8_t)0b00000100

// BATTERY COMPENSATION

#define   BATTCMP                           (uint8_t)0b10000000
#define   VPMONITOR                         (uint8_t)0b01000000

// SPEAKER STATUS 

#define   OVERLOAD_A                        (uint8_t)0b00100000
#define   OVERLOAD_B                        (uint8_t)0b00010000
#define   SPEAKER_PIN_STATUS                (uint8_t)0b00001000

/*---------------------------------------------------------------------------*/
#endif