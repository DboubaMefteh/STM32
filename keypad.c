
#define R_PORT GPIOE
#define R1_PIN 8
#define R2_PORT GPIOE
#define R2_PIN 10
#define R3_PORT GPIOE
#define R3_PIN 12
#define R4_PORT GPIOE
#define R4_PIN 14

#define C1_PORT GPIOB
#define C1_PIN 10
#define C2_PORT GPIOB
#define C2_PIN 12
#define C3_PORT GPIOB
#define C3_PIN 14
#define C4_PORT GPIOD
#define C4_PIN 8

void initialisation()
{
	// configuration of rows
		/* Enable porTS  clock */
			  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN|RCC_AHB1ENR_GPIOEEN|RCC_AHB1ENR_GPIOBEN;

			 /* Select output mode */
			  R_PORT->MODER |= GPIO_MODER_MODER8_0|GPIO_MODER_MODER10_0|GPIO_MODER_MODER12_0|GPIO_MODER_MODER14_0;

				  /*
				   * Select no pull
				   * reset value of the value of port E , register Pudr  is 0x00
				   */
	///configuration of colmuns
			  /*select pull up*/

			  C4_PORT->PUPDR|=GPIO_PUPDR_PUPDR8_0;
			  C1_PORT->PUPDR|=GPIO_PUPDR_PUPDR10_0|GPIO_PUPDR_PUPDR12_0|GPIO_PUPDR_PUPDR14_0;



}
char* read_keypad (void)
{

	while(1)
	{
		R_PORT->MODER&=~(GPIO_MODER_MODER10|GPIO_MODER_MODER12|
				GPIO_MODER_MODER14);
		Delay_ms(1);
		R_PORT->BSRRH |=1u<<R1_PIN;//R4 High
		//R_PORT->BSRRL = GPIO_BSRR_BS_8;//R1 Low
		//R_PORT->BSRRL = GPIO_BSRR_BS_10;//R2 High
		//R_PORT->BSRRL = GPIO_BSRR_BS_14;//R1

		if (!(C1_PORT->IDR&=(uint32_t)1<<C1_PIN))
		{
			Delay_ms(200);
			while(!(C1_PORT->IDR&=(uint32_t)1<<C1_PIN));
			return "1";

		}
		if (!(C2_PORT->IDR&=(uint32_t)1<<C2_PIN))
		{
			Delay_ms(200);
			while(!(C2_PORT->IDR&=(uint32_t)1<<C2_PIN));
			return "2";

		}
		if (!(C3_PORT->IDR&=(uint32_t)1<<C3_PIN))
		{
			Delay_ms(200);
			while(!(C3_PORT->IDR&=(uint32_t)1<<C3_PIN));
			return "3";

		}
		if (!(C4_PORT->IDR&=(uint32_t)1<<C4_PIN))
		{
			Delay_ms(200);
			while(!(C4_PORT->IDR&=(uint32_t)1<<C4_PIN));
			return "A";
		}
		R_PORT->MODER |= GPIO_MODER_MODER8_0|GPIO_MODER_MODER10_0|GPIO_MODER_MODER12_0|GPIO_MODER_MODER14_0;

		Delay_ms(1);

			//
		R_PORT->MODER&=~(GPIO_MODER_MODER8|GPIO_MODER_MODER12|
				GPIO_MODER_MODER14);
		//R_PORT->BSRRL = GPIO_BSRR_BS_8;//R1 Low
		R_PORT->BSRRH |= 1<<R2_PIN;//R2 High
		/*R_PORT->BSRRL = GPIO_BSRR_BS_12;//R3 High
		R_PORT->BSRRL = GPIO_BSRR_BS_14;//R4 High*/

		Delay_ms(1);



		if (!(C1_PORT->IDR&=(uint32_t)1<<C1_PIN))
		{
			Delay_ms(200);
			while(!(C1_PORT->IDR&=(uint32_t)1<<C1_PIN));
			return "4";

		}
		if (!(C2_PORT->IDR&=(uint32_t)1<<C2_PIN))
		{
			Delay_ms(200);
			while(!(C2_PORT->IDR&=(uint32_t)1<<C2_PIN));
			return "5";

		}
		if (!(C3_PORT->IDR&=(uint32_t)1<<C3_PIN))
		{
			Delay_ms(200);
			while(!(C3_PORT->IDR&=(uint32_t)1<<C3_PIN));
			return "6";

		}
		if (!(C4_PORT->IDR&=(uint32_t)1<<C4_PIN))
		{
			Delay_ms(200);
			while(!(C4_PORT->IDR&=(uint32_t)1<<C4_PIN));
			return "B";
		}
		R_PORT->MODER |= GPIO_MODER_MODER8_0|GPIO_MODER_MODER10_0|GPIO_MODER_MODER12_0|GPIO_MODER_MODER14_0;


		Delay_ms(1);

		R_PORT->MODER&=~(GPIO_MODER_MODER8|GPIO_MODER_MODER10|
				GPIO_MODER_MODER14);
		//
		//R_PORT->BSRRL = GPIO_BSRR_BS_8;//R1 Low
		//R_PORT->BSRRL = GPIO_BSRR_BS_10;//R2 High
		R_PORT->BSRRH |= 1<<R3_PIN;//R3 High
		//R_PORT->BSRRL = GPIO_BSRR_BS_14;//R4 High


		Delay_ms(1);

		if (!(C1_PORT->IDR&=(uint32_t)1<<C1_PIN))
		{
			Delay_ms(200);
			while(!(C1_PORT->IDR&=(uint32_t)1<<C1_PIN));
			return "7";

		}
		if (!(C2_PORT->IDR&=(uint32_t)1<<C2_PIN))
		{
			Delay_ms(200);
			while(!(C2_PORT->IDR&=(uint32_t)1<<C2_PIN));
			return "8";

		}
		if (!(C3_PORT->IDR&=(uint32_t)1<<C3_PIN))
		{
			Delay_ms(200);
			while(!(C3_PORT->IDR&=(uint32_t)1<<C3_PIN));
			return "9";

		}
		if (!(C4_PORT->IDR&=(uint32_t)1<<C4_PIN))
		{
			Delay_ms(200);
			while(!(C4_PORT->IDR&=(uint32_t)1<<C4_PIN));
			return "C";
		}
		R_PORT->MODER |= GPIO_MODER_MODER8_0|GPIO_MODER_MODER10_0|GPIO_MODER_MODER12_0|GPIO_MODER_MODER14_0;


		Delay_ms(1);

			//
		/*R_PORT->BSRRL = GPIO_BSRR_BS_8;//R1 Low
		R_PORT->BSRRL = GPIO_BSRR_BS_10;//R2 High
		R_PORT->BSRRL = GPIO_BSRR_BS_12;//R3 High*/
		R_PORT->MODER&=~(GPIO_MODER_MODER8|GPIO_MODER_MODER10|
				GPIO_MODER_MODER12);
		Delay_ms(1);
		R_PORT->BSRRH |= 1<<R4_PIN;//R4 High

		if (!(C1_PORT->IDR&=(uint32_t)1<<C1_PIN))
		{
			Delay_ms(200);
			while(!(C1_PORT->IDR&=(uint32_t)1<<C1_PIN));
			return "*";

		}
		if (!(C2_PORT->IDR&=(uint32_t)1<<C2_PIN))
		{
			Delay_ms(200);
			while(!(C2_PORT->IDR&=(uint32_t)1<<C2_PIN));
			return "0";

		}
		if (!(C3_PORT->IDR&=(uint32_t)1<<C3_PIN))
		{
			Delay_ms(200);
			while(!(C3_PORT->IDR&=(uint32_t)1<<C3_PIN));
			return "#";

		}
		if (!(C4_PORT->IDR&=(uint32_t)1<<C4_PIN))
		{
			Delay_ms(200);
			while(!(C4_PORT->IDR&=(uint32_t)1<<C4_PIN));

			return "D";
		}
		R_PORT->MODER |= GPIO_MODER_MODER8_0|GPIO_MODER_MODER10_0|GPIO_MODER_MODER12_0|GPIO_MODER_MODER14_0;

		Delay_ms(1);

	}
}
