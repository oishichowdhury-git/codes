import controlP5.*;
import processing.serial.*;
ControlP5 cp5; // you always need the main class
Serial myPort;  // Create object from Serial class

boolean rectOver = false;
boolean rOver = false;
boolean triggerOver = false;
boolean chargingOver = false;
int z=0,y=0;
float e;
char val;

void setup() {
  size(700, 400);
  String portName = "COM1";
  myPort = new Serial(this, portName, 9600);
  cp5 = new ControlP5(this);
  cp5.setFont(new ControlFont(createFont("Georgia",15), 15));
  // add a dropdownlist at position (100,100)
  DropdownList droplist1 = cp5.addDropdownList("Trigger menu",55,125,220,124) 
                             .setBackgroundColor(color(255))
                             .setBarHeight(30)
                             .setItemHeight(30)
                             .setOpen(false);
                             
    // add items to the dropdownlist
    droplist1.addItem("Mannual Trigger", 1);
    droplist1.addItem("Repetative Trigger", 2);
    droplist1.addItem("Stopped (Trigger menu)", 3);
    
    DropdownList droplist2 = cp5.addDropdownList("Charging menu",305,125,235,124) 
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
  // controlp5 autodraw is on by default (if you use the default JAVA2D renderer)
  // this means the gui is automatically drawn at the end
    if ( myPort.available() > 0) 
  {  // If data is available,
    val = myPort.readChar();
    fill(255);
    textSize(16);    
 if(val !='s' && val !='t')
    print(val);
 if(val==' ')
 println("");
  }
  
 if (val=='s' && chargingOver && (e==1||e==0))
  {     
     //text("Sorry !!",367,295);
     text("Impropper voltage !", 345,288);
     text("Please Dump it ", 358,314);
     text("and then try.", 365,340);
  }
  if (val=='t' && chargingOver && (e==1||e==0))     
     text("Charging over !", 358,300);
     
   if(z==1)
   {
    delay(250);
    z=0;
   }
   fill(color(255));
   stroke(255);
   rect(570,height/2-25,50,50);
   
   if(y==1)
   {
    delay(250);
    y=0;
   }
   fill(color(255));
   stroke(255);
   rect(570,height/2+75,50,50);
   
   fill(255);
   textSize(16);
   text("Dump", 570, height/2-30);
   text("Adc val", 570, height/2+70);
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
        if(theEvent.getController().getValue()==0.0)
            myPort.write('0');
        if(theEvent.getController().getValue()==1.0)
            myPort.write('1');
        if(theEvent.getController().getValue()==2.0)
            myPort.write('2');
      }
       if(chargingOver)
       {
        if(theEvent.getController().getValue()==0.0)
            myPort.write('3');
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
  if (mouseX >= 570 && mouseX <=570+ 50 && 
      mouseY >= height/2-25&& mouseY <= height/2-25+50)
      {
       rectOver=true;
       triggerOver = false;
       chargingOver = false;
       rOver = false;
      }
  else if(mouseX >= 55 && mouseX <=55+ 220 && 
  mouseY >= 125 && mouseY <= 125 +124)  
  {
     rectOver=false;
     triggerOver = true;
     chargingOver = false;
     rOver = false;
  }
  else if(mouseX >= 305 && mouseX <=305 + 235 && 
  mouseY >= 125 && mouseY <= 125 +124)  
  {
     rectOver=false;
     triggerOver = false;
     chargingOver = true;
     rOver = false;
  }
  else if(mouseX >= 570 && mouseX <=570+ 50 && 
  mouseY >=  height/2+75&& mouseY <= height/2+75+50)  
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
  if (rectOver) 
   {
       z=1;
       myPort.write('2');
       fill(color(51));
       stroke(255);
       rect(570,height/2-25,50,50); 
   }
   if (rOver) 
   {
       y=1;
       myPort.write('4');
       fill(color(51));
       stroke(255);
       rect(570,height/2+75,50,50); 
   }
  
}