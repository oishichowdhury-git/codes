import processing.serial.*;
import controlP5.*;
Serial myPort;  // Create object from Serial class
ControlP5 cp; // Create object from ControlP5 class

boolean rect1Over = false;
boolean circleOver = false;
boolean rect2Over = false;

int x,i;
float y;
int a;
char b;
void setup() 
{
  cp = new ControlP5(this);
  cp.addSlider("Range_for_rep")
     .setBroadcast(false)
     .setRange(0.1, 10)
     .setPosition(width/2+115, height/2+100)
     .setSize(100, 20)
     .setBroadcast(true)
     .setValue(5)
     ;
    
  //println("available ports are");
  //println(Serial.list());
  ellipseMode(CENTER);
  // I know that On Windows machines, this generally opens COM1.
  // the first port in the serial list on mac is always FTDI adaptor, 
  // so you open Serial.list()[0]..
  // Open whatever port is the one you're using.
  String portName = "COM1";
  myPort = new Serial(this, portName, 9600);
  //myPort.buffer(64);
  
  size(600, 600);
}
void draw()
{
   background(304);
   overshape();
     
   if (rect1Over) {
    fill(color(51));
  } else {
    fill(color(0));
  }
   stroke(255);
   rect(width/2-175,height/2,50,50);
   fill(255, 204, 0);
   text("Simmer mode operation", width/2-225, height/2+80);
   
    if (circleOver) {
    fill(color(51));
  } else {
    fill(color(255));
  }
   stroke(255);
   ellipse(width/2+5,height/2+25,50,50);
   fill(255, 204, 0);
   text("Manual trigger", width/2-35, height/2+80);
   
   if (rect2Over) {
    fill(color(51));
  } else {
    fill(color(0));
  }
  stroke(255);
  rect(width/2+135,height/2,50,50); 
  fill(255, 204, 0);
   text("Repitative rate in hz", width/2+120, height/2+80);
   
}
void overshape()
{
  if (mouseX >= width/2-175 && mouseX <= width/2-175+ 50 && 
      mouseY >= height/2 && mouseY <= height/2+50)
  {
     rect1Over=true;
     circleOver = false;
     rect2Over=false;
   }
  else if (sqrt(sq(width/2+5 - mouseX) + sq(height/2+25 - mouseY)) < 25 )
  {
     rect1Over=false;
     circleOver = true;
     rect2Over=false;
   }
   else if (mouseX >= width/2+135 && mouseX <= width/2+135+ 50 && 
      mouseY >= height/2 && mouseY <= height/2+50)
  {
     rect2Over=true;
     circleOver = false;
     rect1Over=false;
   }
  else
     {
     rect1Over=false;
     circleOver =false;
     rect2Over=false;
   }
}
public void Range_for_rep(float val)
{
  x=(int)(val*10);
  y= x / 10.0;
  println("The value is" + y);
}
void mousePressed()
{
  if (circleOver)
  {
    myPort.write('5');
  }
  if (rect1Over) 
  {
    myPort.write('1');
  }
  if (rect2Over)
  {
    myPort.write('9');
    println("val=");
    for(i=0;i<3;i++)
    {
      a= x%10;
      b= char(a+'0');
      myPort.write(b);
      print(b);
      x= x/10;
    }
  }
}