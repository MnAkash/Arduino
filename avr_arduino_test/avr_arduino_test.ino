int constant=13;
int main(void)
{
    
    pinmode(constant,1);

    while(1)
    {
      digitalwrite(constant,1);
      _delay_ms(1000);
      digitalwrite(constant,0);
      _delay_ms(1000);
     
    }
    return 0;
}







void digitalwrite(int pin, int state)
{
  if(2<=pin<=7)
  {
      switch(state)
      {
        case 0:
            PORTD &=~(1<<pin);
            break;    
         case 1:
            PORTD |=(1<<pin);
            break;    
        default:
            exit(1);                  
      }
  }
  if(8<=pin<=13)
  {
      switch(state)
      {
        case 0:
            PORTB &=~(1<<pin-8);
            break;    
         case 1:
            PORTB |=(1<<pin-8);
            break;    
        default:
            exit(1);                  
      }
}
}

void pinmode(int pin, int state)
{
  if(2<=pin<=7)
  {
      switch(state)
      {
        case 0:
            DDRD &=~(1<<pin);
            break;    
         case 1:
            DDRD |=(1<<pin);
            break;    
        default:
            exit(1);                  
      }
  }
  if(8<=pin<=13)
  {
      switch(state)
      {
        case 0:
            DDRB &=~(1<<pin-8);
            break;    
         case 1:
            DDRB |=(1<<pin-8);
            break;    
        default:
            exit(1);                  
      }
}
}
