/* Touch Pad Read Example

*/
///Estoy escribiendo en github
#include "ESP32.h"
#include "driver/touch_pad.h"
#include "esp_log.h"

//#define TOUCH_PAD_NO_CHANGE   (-1)
#define TOUCH_THRESH_NO_USE   (0)
//#define TOUCH_FILTER_MODE_EN  (1)
#define TOUCHPAD_FILTER_TOUCH_PERIOD (10)


void main()
{

    uint16_t touch_value;
    uint16_t touch_filter_value;

    touch_pad_init();

    touch_pad_set_voltage(TOUCH_HVOLT_2V7, TOUCH_LVOLT_0V5, TOUCH_HVOLT_ATTEN_1V);

    touch_pad_config(4, TOUCH_THRESH_NO_USE);

    touch_pad_filter_start(TOUCHPAD_FILTER_TOUCH_PERIOD);

    while(1)
    {
    	int i=4;
		// If open the filter mode
    	touch_pad_read_raw_data(i, &touch_value);
		touch_pad_read_filtered(i, &touch_filter_value);
		printf("T%d:[%4d,%4d] \n\r", i, touch_value, touch_filter_value);

		vTaskDelay(2000 / portTICK_PERIOD_MS);

     }

}
