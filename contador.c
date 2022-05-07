#include <16f630.h>
#fuses intrc_io,nowdt,nomclr,protect,nobrownout
#use delay (clock=4000000)
#use fast_io(A)
#use fast_io(C)

#byte trisa=0x85
#byte trisc=0x87

#bit coin=0x05.0
#bit led=0x05.1
#bit salida=0x05.5

int a,b;

void anti()
{
while (coin==0)
delay_ms(100);
}

main()
{
trisa=0b00000001;
trisc=255;
b=0;
led=0;
salida=0;
a=(input(pin_c0)*1)+(input(pin_c1)*2)+(input(pin_c2)*4)+(input(pin_c3)*8);
while (true)
{
a=(input(pin_c0)*1)+(input(pin_c1)*2)+(input(pin_c2)*4)+(input(pin_c3)*8);
if (coin==0)
{
b++;
anti();
}

if (b>=a)
{
led=1;
salida=1;
delay_ms(100);
salida=0;
b=0;
}


}
}

