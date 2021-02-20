/*
 * led.c
 *
 *  Created on: 2021. 2. 20.
 *      Author: baram
 */


#include "led.h"



#ifdef _USE_HW_LED


typedef struct
{
  GPIO_T   *port;
  uint32_t  port_pin;
  uint32_t  pin;
  uint8_t   on_state;
  uint8_t   off_state;
} led_tbl_t;


led_tbl_t led_tbl[LED_MAX_CH] =
    {
        {PC, 2, 5, 0, 1},
    };





bool ledInit(void)
{
  bool ret = true;


  for (int i=0; i<LED_MAX_CH; i++)
  {
    GPIO_SetMode(led_tbl[i].port, 1<<led_tbl[i].pin, GPIO_MODE_OUTPUT);
    ledOff(i);
  }

#ifdef _USE_HW_CLI
  cliAdd("led", cliLed);
#endif

  return ret;
}

void ledOn(uint8_t ch)
{
  volatile uint32_t *pin;

  if (ch >= LED_MAX_CH) return;

  pin = ((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(led_tbl[ch].port_pin))) + ((led_tbl[ch].pin)<<2)));


  *pin = led_tbl[ch].on_state;
}

void ledOff(uint8_t ch)
{
  volatile uint32_t *pin;

  if (ch >= LED_MAX_CH) return;

  pin = ((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(led_tbl[ch].port_pin))) + ((led_tbl[ch].pin)<<2)));


  *pin = led_tbl[ch].off_state;
}

void ledToggle(uint8_t ch)
{
  volatile uint32_t *pin;

  if (ch >= LED_MAX_CH) return;

  pin = ((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(led_tbl[ch].port_pin))) + ((led_tbl[ch].pin)<<2)));


  *pin ^= 1;
}




#endif
