/*
 * SPI_TRANS.c
 *
 * Created: 1/21/2022 9:33:16 PM
 * Author : Doha
 */ 

#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "I2C_interface.h"

int main(void)
{
	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	/*DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
	DIO_voidSetPinValue(PORTA,PIN1,HIGH);*/
	
	I2C_Slave_voidInit(0x10);

	while(1){
		u8 data;
		I2C_Slave_voidListen();
		I2C_Slave_enuReadu8Data(&data);
		if(data==0x30)
		{
			DIO_voidSetPinValue(PORTA,PIN0,HIGH);
		}
		I2C_Slave_enuReadu8Data(&data);
	}
}


