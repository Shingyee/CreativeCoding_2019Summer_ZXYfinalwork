PImage img;
import processing.serial.*;
Serial myPort;
char temp;



void setup()
{
  size(700, 700);
  img = loadImage("新建图像.jpg");
  background(img);
  myPort=new Serial(this, "COM5", 9600);
}



void draw() 
{
  while (myPort.available()>0)
  {
    background(img);
    String data=myPort.readStringUntil('\n');
    if (data!=null)
    { 
      print(data);
      fill(#56AA94);
      textSize(38);
      text(data, 132, 88);
    }
  }
  if ((mouseX-579)*(mouseX-579)+(mouseY-345)*(mouseY-345)<=6724) {
    fill(255);
    //noStroke();
    rect(100, 230, 375, 150, 20, 20, 20, 20);
    fill(0);
    textSize(38);
    textAlign(CENTER, CENTER);
    text("Have a Cool Day!", 287, 300);
  }
}
