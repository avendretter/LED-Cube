/* Name: main.c
 * Author: Julian Gog
 * Copyright: Julian Gog. 2012. mail:jgog@gmx.de
 * License: <insert your license reference here>
 */

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#define mydelay 5



char i;

char LED[2][3] =
{
    {0,0,0},
    {0,0,0}
};

int setPort(int myfrequence)
{
    for(i=0;i< myfrequence ;i++)
    {
        PORTD = LED[0][0];
        if (LED[1][0])
        {
            PORTB |= (1<<0);
        }
        else
        {
            PORTB &= ~(1<<0);
        };
        
        PORTC = (1 << 4)| (1 << 5);
        _delay_ms(mydelay);
    
        
        PORTD = LED[0][1];
        if (LED[1][1])
        {
            PORTB |= (1<<0);
        }
        else
        {
            PORTB &= ~(1<<0);
        };
        
        PORTC = (1 << 3) | (1 << 5) ;
        _delay_ms(mydelay);
    
        PORTD = LED[0][2];
        if (LED[1][2])
        {
            PORTB |= (1<<0);
        }
        else
        {
            PORTB &= ~(1<<0);
        };
        
        
        PORTC = (1 << 3) | (1 << 4) ;
        _delay_ms(mydelay);
    }

    
}

int resetarray(void)
{
    LED[0][0] = 0;
    LED[0][1] = 0;
    LED[0][2] = 0;
    LED[1][0] = 0;
    LED[1][1] = 0;
    LED[1][2] = 0;
}


int reset(void)
{
    resetarray();
    setPort(1);
}

int set(int x,int y)
{
    y=y-1;
    switch(x)
    {
        case 1:
            LED[0][y] = 1 ;
            break;
        case 2:
            LED[0][y] |= 1 << 1 ;
            break;
        case 3:
            LED[0][y] |= 1 << 2;
            break;
        case 4:
            LED[0][y] |= 1 << 3;
            break;
        case 5:
            LED[0][y] |= 1 << 4;
            break;
        case 6:
            LED[0][y] |= 1 << 5;
            break;
        case 7:
            LED[0][y] |= 1 << 6;
            break;
        case 8:
            LED[0][y] |= 1 << 7;
            break;
        case 9:
            LED[1][y] = 1 << 0;
            break;
    }
}

int main(void)
{
    DDRD =
    1<<0| //1.LED
    1<<1| //2.LED
    1<<2| //3.LED
    1<<3| //4.LED
    1<<4| //5.LED
    1<<5| //6.LED
    1<<6| //7.LED
    1<<7 //8.LED
    ;               // schaltet LED ein
    
    DDRB =
    1<<0; //9.LED  
    
    DDRC =
    1<<3 | //1.EBENE
    1<<4 | //2.EBENE
    1<<5;  //3.EBENE
    
    
    DDRB &= ~(1 << DDB2);   
    
    PORTB |= (1 << PORTB2); 
    
    
    char p,l,j;
   
    
    
    while (1)
    {
        
        while( (PINB & (1<<PINB2)) < 1)
        {
           
            for(l=0;l<10;l++)
            {
            
                set(5,2);
                set(2,2);
                set(8,2);
                setPort(30);
                resetarray();
                set(1,2);
                set(2,2);
                set(3,2);
                set(4,2);
                set(5,2);
                set(6,2);
                set(7,2);
                set(8,2);
                set(9,2);
                setPort(30);
                resetarray();
            
                for(p=0;p<10;p++)
                {
                    set(5,2);
                    set(2,2);
                    set(8,2);
                    set(3,3);
                    set(6,3);
                    set(9,3);
                    set(1,1);
                    set(4,1);
                    set(7,1);
                    setPort(5);
                    resetarray();                    
                    set(5,2);
                    set(2,2);
                    set(8,2);
                    set(2,1);
                    set(5,1);
                    set(8,1);
                    set(2,3);
                    set(5,3);
                    set(8,3);
                    setPort(5);
                    resetarray();                    
                    set(5,2);
                    set(2,2);
                    set(8,2);
                    set(1,3);
                    set(4,3);
                    set(7,3);
                    set(3,1);
                    set(6,1);
                    set(9,1);
                    setPort(5);
                    resetarray();
                    set(1,2);
                    set(2,2);
                    set(3,2);
                    set(4,2);
                    set(5,2);
                    set(6,2);
                    set(7,2);
                    set(8,2);
                    set(9,2);
                    setPort(5);
                    resetarray();
                }
            
                
                _delay_ms(200); 
            
                set(5,2);
                set(2,2);
                set(8,2);
                setPort(30);
                resetarray();
                set(2,2);
                set(5,2);
                set(8,2);
                set(2,1);
                set(5,1);
                set(8,1);
                set(2,3);
                set(5,3);
                set(8,3);
                setPort(30);
                resetarray();
            
            
                for(j=0;j<10;j++)
                {
                    set(1,1);
                    set(5,1);
                    set(9,1);
                    set(5,1);
                    set(1,2);
                    set(5,2);
                    set(9,2);
                    set(1,3);
                    set(5,3);
                    set(9,3);
                    setPort(5);
                    
                    resetarray();
                
                    set(4,1);
                    set(5,1);
                    set(6,1);
                    set(4,2);
                    set(5,2);
                    set(6,2);
                    set(4,3);
                    set(5,3);
                    set(6,3);
                    setPort(5);
                    resetarray();                    
                    set(7,1);
                    set(5,1);
                    set(3,1);
                    set(7,2);
                    set(5,2);
                    set(3,2);
                    set(7,3);
                    set(5,3);
                    set(3,3);
                    setPort(5);
                    resetarray();
                    set(2,1);
                    set(5,1);
                    set(8,1);
                    set(2,2);
                    set(5,2);
                    set(8,2);
                    set(2,3);
                    set(5,3);
                    set(8,3);
                    setPort(5);
                    resetarray();   
                }
                reset();
                _delay_ms(200);
            }
        }
                
        
    
    }
    
}
