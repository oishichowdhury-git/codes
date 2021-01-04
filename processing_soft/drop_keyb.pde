import controlP5.*;
import processing.serial.*;
ControlP5 cp5; // you always need the main class
Serial myPort;  // Create object from Serial class

boolean rectOver = false;
boolean rOver = false;
boolean triggerOver = false;
boolean chargingOver = false;
int z=0,y=0,c=0,i,count=0,t,sv_ok=0,button_size=50,en=1;
float e;
char val;
String input = "",temp="",disp="",sv_inter="",sv="00000",s="";
int finalInput,show=0,dump_x=415,dump_y=380,setvol_x=100,setvol_y=380;
char l;

void setup() {
  size(740, 600);
  String portName = "COM1";
  myPort = new Serial(this, portName, 38400);
  cp5 = new ControlP5(this);
  cp5.setFont(new ControlFont(createFont("Georgia",15), 15));
  // add a dropdownlist at position (100,100)
  DropdownList droplist1 = cp5.addDropdownList("Trigger menu",405,125,220,124) 
                             .setBackgroundColor(color(255))
                             .setBarHeight(30)
                             .setItemHeight(30)
                             .setOpen(false);
                             
    // add items to the dropdownlist
    droplist1.addItem("Mannual Trigger", 1);
    droplist1.addItem("Repetative Trigger", 2);
    droplist1.addItem("Stopped (Trigger menu)", 3);
    
    DropdownList droplist2 = cp5.addDropdownList("Charging menu",100,125,235,124) 
                             .setBackgroundColor(color(255))
                             .setBarHeight(30)
                             .setItemHeight(30)
                             .setOpen(false);
                               
  // add items to the dropdownlist
    droplist2.addItem("Mannual Charging", 1);
    droplist2.addItem("Repetative Charging", 2);
    droplist2.addItem("Stopped (Charging menu)", 3);
}
 
void draw() {
  background(0);
  c=0;
  // controlp5 autodraw is on by default (if you use the default JAVA2D renderer)
  // this means the gui is automatically drawn at the end
    if ( myPort.available() > 0) 
  {  // If data is available,
    val = myPort.readChar();   
 if(val !='s' && val !='t'&& val !='k')
 { 
   count++;
   temp=temp+val;
 }
 if(val =='s')
 show=1;
 if(val =='t')
 show=2;
 if(val =='k')
 show=3;
 }
  
 fill(255);
 textSize(16);
 if(count==6)
 {
 count=0;
 disp=temp+'V';
 temp="";
 }
 text("Feedback voltage: "+disp, 415,462);
 if (chargingOver && (e==1||e==0) && show==1)
  {   
     text("Impropper voltage !", 127,238);
     text("Please Dump it ", 141,265);
    text("and then try.", 150,292);
  }
  if (chargingOver && (e==1||e==0) && show==2) 
  {
     text("Charging over !", 151,217);
  }
  if (chargingOver && (e==1||e==0) && show==3) 
  {
     text("Please set the voltage !", 121,217);
  }   
   if(z==1||y==1)
   {
    delay(250);
    z=0;
    y=0;
   }
   fill(color(255));
   stroke(255);
   rect(dump_x,dump_y,button_size,button_size);

   fill(color(255));
   stroke(255);
   rect(setvol_x,setvol_y,button_size,button_size);
   
   fill(255);
   textSize(16);
   text("Dump", dump_x+button_size+10, dump_y+30);
   text("Set voltage", setvol_x+button_size+10, setvol_y+30);
   if(sv_ok==1)
   {
       text(sv_inter,98,252);
   }
   text("Set voltage now: "+sv+" V",100,462);
}
 
// controlEvent monitors clicks on the gui
void controlEvent(ControlEvent theEvent) {
  if (theEvent.isGroup()) {
    println(theEvent.getGroup() + " => " + theEvent.getGroup().getValue());
  }
    else if (theEvent.isController()) 
    {  
      if(triggerOver)
      {
        show=0;
        if(theEvent.getController().getValue()==0.0)
            myPort.write('0');
        if(theEvent.getController().getValue()==1.0)
            myPort.write('1');
        if(theEvent.getController().getValue()==2.0)
            myPort.write('2');
      }
       if(chargingOver)
       {
         show=0;
        if(theEvent.getController().getValue()==0.0)
            {
              if(sv.equals("00000"))
                show=3;                
               else
                myPort.write('3');
            }
         if(theEvent.getController().getValue()==1.0)
            println("Hiii repch");
         if(theEvent.getController().getValue()==2.0)
            myPort.write('2');
       }
    println("event from controller : "+theEvent.getController().getValue()+" from "+theEvent.getController());
    e=theEvent.getController().getValue();
}
  }
void overshape()
{
  if (mouseX >= dump_x && mouseX <=dump_x+button_size&& 
      mouseY >= dump_y&& mouseY <= dump_y+button_size)
      {
       rectOver=true;
       triggerOver = false;
       chargingOver = false;
       rOver = false;
      }
  else if(mouseX >= 100 && mouseX <=100+ 235 && 
  mouseY >= 125 && mouseY <= 125 +124)  
  {
     rectOver=false;
     triggerOver = false;
     chargingOver = true;
     rOver = false;
  }
  else if(mouseX >= 405 && mouseX <=405 + 220 && 
  mouseY >= 125 && mouseY <= 125 +124)  
  {
     rectOver=false;
     triggerOver = true;
     chargingOver = false;
     rOver = false;
  }
  else if(mouseX >= setvol_x && mouseX <=setvol_x+button_size && 
  mouseY >= setvol_y && mouseY <= setvol_y+button_size)  
  {
     rectOver=false;
     triggerOver = false;
     chargingOver = false;
     rOver = true;
  }
  else
  {
      rectOver=false;
      triggerOver = false;
      chargingOver = false;
      rOver = false;
  }
}
void mousePressed()
{
  overshape();
  show=0;
  if (rectOver) 
   {
       z=1;
       myPort.write('2');
       fill(color(51));
       stroke(255);
       rect(dump_x,dump_y,button_size,button_size); 
   }
   if (rOver) 
   {
       y=1;
       myPort.write('5');
       sv_ok=1;
        println( "Please enter the set voltage \n The range is 100 - 10000");
        sv_inter="Please enter the set voltage in range - 100 to 10000V -";
       fill(color(51));
       stroke(255);
       rect(setvol_x,setvol_y,button_size,button_size); 
   }  
}
void keyPressed(){
  show=0;
  if( key >= '0' && key <= '9' ){
    input+=char(key);
    println( "The current input is: " + input );
    sv_inter= "The current input is: " + input +'V';
    if( abs( int( input ) ) >= 10000 ){
      println( "Whoops! That's above the range. Let's ignore the last digit." );
      sv_inter="Whoops! That's above the range. Let's ignore the last digit.";
      input = input.substring(  0, input.length()-1 );
      println( "The current input is: " + input ); 
      sv_inter= "The current input is: " + input +'V';
    }
  }  
  else if( key == BACKSPACE && input.length() > 0 ){
    input = input.substring(  0, input.length()-1 );
    println( "The current input is :" + input );
    sv_inter="The current input is :" + input +'V';
  } 
  else if (key == RETURN || key == ENTER)
  {
    finalInput = int( input );
    if(finalInput>100)
    {
      println( "Set voltage entered is: " + finalInput + "\n" ); 
       sv_inter="Set voltage entered is: " + finalInput+'V';
       s="";
      for(i=0;i<5;i++)
      {    
           l=char(finalInput%10);
           s=s+=char(finalInput%10 +48);
           finalInput = finalInput /10;
           myPort.write(l+48);
       }
      sv = new StringBuffer(s).reverse().toString();      
      sv_ok=0;
    }
    else
    {
    println( "Set voltage has to be greater than 100" ); 
    sv_inter="Set voltage has to be greater than 100V- ";
    }
    input = "";
  }
}