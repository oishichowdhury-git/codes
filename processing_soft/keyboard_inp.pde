import processing.serial.*;
Serial myPort;  // Create object from Serial class

String input = "";
int i, finalInput;
char l;
char val;
void setup(){
  String portName = "COM1";
  myPort = new Serial(this, portName, 38400);
}
void draw(){
  background(0);
  if ( myPort.available() > 0) 
  {  // If data is available,
    val = myPort.readChar();
    println(val);
  }
}
void keyPressed(){
  if( key >= '0' && key <= '9' ){
    input+=char(key);
    println( "The key entered was: " + char(key) );
    println( "The current input is: " + input );
    if( abs( int( input ) ) >= 10000 ){
      println( "Whoops! That's too many digits. Let's ignore that last one." );
      input = input.substring(  0, input.length()-1 );
      println( "The current input is: " + input );    
    }
  }  
  else if( key == BACKSPACE && input.length() > 0 ){
    println( "Didn't like that last key you pressed, huh? Ok, we'll get rid of it for you." );
    input = input.substring(  0, input.length()-1 );
    println( "The current input is: " + input );
  } 
  else if (key == RETURN || key == ENTER){
    finalInput = int( input );
    println( "Input entered is: " + finalInput ); 
    myPort.write('5');   
    //myPort.write('5');
    for(i=0;i<4;i++)
      {    
           l=char(finalInput%10);
           finalInput = finalInput /10;
           myPort.write(l+48);           
      }
    input = "";
  }
}