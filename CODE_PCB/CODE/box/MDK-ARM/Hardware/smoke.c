#include "main.h"
#include "adc.h"
#include "all.h"
SMOKE smoke;



void ADC_GET(void)
{
	HAL_ADC_Start_DMA(&hadc1,smoke.adc_buffer,1);
    


}
void SMOKE_GET(void)
{
	ADC_GET();
	 if(smoke.adc_buffer[0]!=0)
	 {
		 smoke.data=(float)(((int)smoke.adc_buffer[0]/4096.0f)*3.3f);
	     smoke.ratio=(int)((smoke.data/3.3f)*100.0f);
	 }
	 else{    smoke.data=0; smoke.ratio=0;
	 }

}
