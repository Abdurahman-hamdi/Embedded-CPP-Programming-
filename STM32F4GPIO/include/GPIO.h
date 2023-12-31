#ifndef __GPIOD__
#define __GPIOD__

#include"GPIOCFG.hpp"
#include<cstdint>
#include<memory>
#include "stm32f4xx_gpio.h"

//prototype for GPIO model

	/**/
	template< GPIO_port T, typename gpio_def>
	class GPIO
	{

	public:
		explicit GPIO(std::unique_ptr<gpio_def> custom_port):port{std::move(custom_port)}
		{
				
		}
		GPIO(const GPIO& )=delete;//ports cann't be copied into each other as they are not same
		GPIO(GPIO&& )	=delete;//neither to be moved to another port
		gpio_def& portaccess()
		{
			return port;
		}
		void 
		~GPIO()
		{
				//TBD
		}
	private:	
	// a poiter to the object that will perform all the acticvties of conguired port whatever uart, adc..etc
		std::unique_ptr<gpio_def> port; 
	};
	
	
	
	
	
	
	

#endif