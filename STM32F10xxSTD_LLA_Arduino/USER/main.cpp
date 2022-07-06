extern "C" {
#include "hw_config.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_pwr.h"
#include "usb_istr.h"
#include "sdio_sdcard.h"
#include "memory.h"
#include "mass_mal.h"
}
#include <Arduino.h>
static uint8_t data_buf[BULK_MAX_PACKET_SIZE*2*4];
static uint8_t bulk_buf[BULK_MAX_PACKET_SIZE];
void setup(){

	SD_Init();
 	Mass_Memory_Size[0]=SDCardInfo.CardCapacity;		//�õ�SD���������ֽڣ�����SD����������4G��ʱ��,��Ҫ�õ�����u32����ʾ
	Mass_Block_Size[0] =512;							//��Ϊ������Init����������SD���Ĳ����ֽ�Ϊ512��,��������һ����512���ֽ�.
	Mass_Block_Count[0]=Mass_Memory_Size[0]/Mass_Block_Size[0];			
	USB_Port_Set(0); 	//USB�ȶϿ�
	USB_Port_Set(1);	//USB�ٴ����� 
  Data_Buffer=(uint32_t *)data_buf;	//ΪUSB���ݻ����������ڴ�
	Bulk_Data_Buff=bulk_buf;	//�����ڴ�
 	//USB����
 	USB_Interrupts_Config();    
 	Set_USBClock();   
 	USB_Init();	     	    
}

void loop(){



}


