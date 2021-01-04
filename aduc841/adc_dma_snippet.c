void adctrans()
{
		EADC=0;
	    for(i=4;i>-1;i--)
        transmit(j[i]+48);
        transmit(' ');
		EADC=1;
}

void conf()
{
		CFG841= 0X81;   // ENABLE XRAM
		for(i=0;i<512;i++)
		XBYTE[i]=0x00;
		XBYTE[i]=0XF0;

		EADC=1;
		ADCCON1=0x32;	// POWER DOWN adc
		CFG841= 0X81;   // ENABLE XRAM						
		ADCCON2=0x40 ;	// ENABLE DMA with channel 0				
						
		DMAL=0x00;	  
		DMAH=0x00;	 
		DMAP=0x00;
		ADCI=0;
}

void graph_plot()
{
		while(!ADCI); 
		CCONV=0;
		ADCI=0;	
		ADCCON1=0x32;	// POWER DOWN adc
		ADCCON2=0x0F ;	// DISABLE DMA with channel 0

		EADC = 0;
		transmit('l'); // 
		CFG841= 0X81;   // ENABLE XRAM	- DISABELING DMA AUTOMATICALLY DISABLED XRAM
		for(i=0;i<512;i=i+2)
		{
				ddt = ((XBYTE[i]<<8) + XBYTE[i+1])/2;
				transmit((ddt/1000));
				ddt = ddt %1000;
				transmit((ddt/100));
				ddt = ddt %100;
				transmit((ddt/10));
				ddt = ddt %10;
				transmit(ddt);
		}	
		RI = 0;
		while(!RI);
		RI=0;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////				
		CFG841= 0X00;   // DISABLE XRAM
		EADC = 1;
		ADCCON1=0x8E;	// POWER UP adc
		ADCCON2=0x01 ;	// ENABLE ADC CH 1
		ddt = 0;
}

void give_graph()
{
		conf();				
		ADCCON1=0xB2;	// POWER up adc		
		CCONV=1; 
	 	graph_plot();
		dump();
}