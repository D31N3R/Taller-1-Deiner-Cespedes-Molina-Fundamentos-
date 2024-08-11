int Led_Maximo=13;
int Led_4_Bits=12;
int Led_3_Bits=11;
int Led_2_Bits=10;
int Led_1_Bits=9;
int Boton_2=5;
int Boton_1=4;
int Boton_Reset=3;
int Boton_Complemento_A_Dos=2;
int Contador=0;
int Contador_Temporal=0;
bool Complemento_A_Dos_Flag=false;

void setup()
{
pinMode(Boton_2,INPUT);
pinMode(Boton_1,INPUT);
pinMode(Boton_Reset , INPUT);
pinMode(Boton_Complemento_A_Dos , INPUT);
  
pinMode(Led_Maximo,OUTPUT);
pinMode(Led_4_Bits,OUTPUT);
pinMode(Led_3_Bits,OUTPUT);
pinMode(Led_2_Bits,OUTPUT);    
pinMode(Led_1_Bits,OUTPUT);
}

void loop()
{	
 if (Contador>=16)
 {
  digitalWrite(Led_Maximo,HIGH);
  digitalWrite(Led_1_Bits,LOW);
  digitalWrite(Led_2_Bits,LOW);
  digitalWrite(Led_3_Bits,LOW);
  digitalWrite(Led_4_Bits,LOW);
 }
  if (digitalRead(Boton_2)==LOW)
  {
    if (Contador <= 15)
    {
      Contador = Contador+2;
      Mostrar_Numero();
    }
  }
  if (digitalRead(Boton_1)==LOW)
  {
    if (Contador <= 15)
    {
  		Contador=Contador+1;
   		Mostrar_Numero();
    }
  }
  if (digitalRead(Boton_Reset)==LOW)
  {
    digitalWrite(Led_Maximo,LOW);
  	Contador = 0;
    digitalWrite(Led_1_Bits,LOW);
  	digitalWrite(Led_2_Bits,LOW);
  	digitalWrite(Led_3_Bits,LOW);
  	digitalWrite(Led_4_Bits,LOW);
    
  }
  if (digitalRead(Boton_Complemento_A_Dos)==LOW)
  {
    if(Complemento_A_Dos_Flag==false)
    {
      Complemento_A_Dos_Flag=true;
      Mostrar_Numero();
    }
    else
    {
      Complemento_A_Dos_Flag=false;
      Mostrar_Numero();
    }
    delay(250);
  }
    
  
}
int Mostrar_Numero()
{
  delay(200);
  Contador_Temporal=Contador;
  if (Contador_Temporal>0){
  	
      if (Complemento_A_Dos_Flag==false )
      {
      
    	for (int led=9;led<=12;led++)
    	{
      		digitalWrite(led,(Contador_Temporal%2));
     		Contador_Temporal/=2;
    	}
      }
      else
      {
        int Variable_Sumado=0;
        for (int led=9;led<=12;led++)
        {
          if ((Contador_Temporal%2)==Variable_Sumado)
          {
            digitalWrite(led,0);
     		Contador_Temporal/=2;
          }
          else
          {
            digitalWrite(led,1);
     		Contador_Temporal/=2;
            Variable_Sumado=1;
          }
          
        }
      }
  }
}