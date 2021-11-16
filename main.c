//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-10-31
//  ����޸�   : 
//  ��������   : LCD SPI�ӿ���ʾ����
//              ˵��: 
//              ----------------------------------------------------------------
//              GND     ��Դ��
//              VCC     3.3v��Դ
//              SCLK      P1.5��SCL��
//              MOSI      P1.6��SDA��
//              RES     P1.3
//              DC      P1.2
//              CS      ����  
//		BLK     ���� ���Ʊ���
//		MISO    P1.7
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018-10-31
//All rights reserved
//******************************************************************************/
#include "delay.h"
#include "lcd.h"
#include <ioCC2530.h>

#define uint unsigned int
#define uchar unsigned char

void Initial_IO(void)
{
    P0DIR |= 0xff;     //P0����Ϊ���
    P1DIR |= 0xff;     //P1����Ϊ���
}

//******************************************************
int main(void)
 {	
	 u8 i,m;
	 float t=0;
        
         Initial_IO();  

	 Lcd_Init();			//��ʼ��OLED  
	 LCD_Clear(WHITE);
	 BACK_COLOR=WHITE;

	 while(1)
	 {
		LCD_ShowChinese32x32(10,0,0,32,GBLUE);   //��
		LCD_ShowChinese32x32(45,0,1,32,GBLUE);   //��
		LCD_ShowChinese32x32(80,0,2,32,GBLUE);   //԰
		LCD_ShowChinese32x32(115,0,3,32,GBLUE);  //��
		LCD_ShowChinese32x32(150,0,4,32,GBLUE);  //��
		LCD_ShowChinese32x32(10,75,0,16,RED);   //��
		LCD_ShowChinese32x32(45,75,1,16,RED);   //��
		LCD_ShowChinese32x32(80,75,2,16,RED);   //԰
		LCD_ShowChinese32x32(115,75,3,16,RED);  //��
		LCD_ShowChinese32x32(150,75,4,16,RED);  //��
		LCD_ShowString(10,35,"2.8 TFT SPI 240*320",RED);
		LCD_ShowString(10,55,"LCD_W:",RED);	LCD_ShowNum(70,55,LCD_W,3,RED);
		LCD_ShowString(110,55,"LCD_H:",RED);LCD_ShowNum(160,55,LCD_H,3,RED);
		  
                for(i=0;i<2;i++)
		{
			for(m=0;m<6;m++)
			{
		           LCD_ShowPicture(0+m*40,120+i*40,39+m*40,159+i*40);
			}
		}
		
                while(1)
		{
                          LCD_ShowNum1(80,200,t,5,RED);
		          t+=0.01;
                }
          }//  while loop
}
