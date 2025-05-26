#include <16f877A.h>
#include <stdio.h>
#USE delay(clock=20m)
#USE RS232(UART1)

void send_message()
{
   printf("AT+CMGF=1");
   printf("AT+CMGS=\"0123456789\"\r\n");
   printf("Theft alarm \n");
   putc(0x1A);
}

void main()
{
   setup_uart(9600);
   output_low(PIN_B0);
   while(1)
   {
      if(input(PIN_A0)==1)
      {
         output_high(PIN_B0);
         send_message();
      }
   }
}
