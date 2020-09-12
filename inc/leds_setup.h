
#ifndef _LEDS_SETUP_H_
#define _LEDS_SETUP_H_
typedef enum {L0R,L0G,L0B,L1,L2,L3} led_t;

void LED_cfg(led_t led);
void LED_low(led_t led);
void LED_high(led_t led);
void LED_ALL();
void LED_toggle(led_t led);
void LED_ALL_OFF();
#endif
