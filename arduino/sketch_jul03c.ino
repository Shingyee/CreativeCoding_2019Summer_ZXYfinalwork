#include <dht11.h> //引用dht11库文件，使得下面可以调用相关参数
#define DHT11PIN 11     //定义温湿度针脚号为11号引脚
dht11 DHT11; //实例化一个对象

const int P = A0; //电位器的引脚
const int U = 2;
int sensorValue = 0; //电位器电压值
int outputValue = 0;

void setup() {                                                       //设置
  Serial.begin(9600);                                            //设置波特率参数
  pinMode(DHT11PIN, OUTPUT);                      //定义输出口
}

void loop() {                                                    //循环
  int chk = DHT11.read(DHT11PIN);                 //将读取到的值赋给chk
  int tem = (float)DHT11.temperature;             //将温度值赋值给tem
  int hum = (float)DHT11.humidity;                 //将湿度值赋给hum
  //Serial.print("Tempeature:");                        //打印出Tempeature:
  Serial.println(tem);                                     //打印温度结果
  //Serial.print("Humidity:");                            //打印出Humidity:
  //Serial.print(hum);                                     //打印出湿度结果
  //Serial.println("%");                                  //打印出%
  delay(1000);                                          //延时一段时间

  if (tem > 28) {
    sensorValue = analogRead(P);
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(U, outputValue);
    delay(1000);
  }
  else
  {
    analogWrite(U, 0);
    delay(1000);
  }
}
