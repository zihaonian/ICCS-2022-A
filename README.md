## 项目概述

​		基于安徽省机器人大赛（嵌入式赛道A平台），本项目是一个基于51单片机的嵌入式油烟机控制系统，旨在实现对油烟机的智能化管理和控制。采用温度传感器和油烟浓度传感器，通过AD转换获取实时的温度和油烟浓度数据，使用12864液晶显示屏，实时显示温度、油烟浓度和系统的工作状态。利用DS1302时钟模块，实时获取当前时间，为系统提供准确的时间基准。集成红外接收模块，通过红外遥控器实现油烟机的遥控操作，包括开关、挡位调整等。利用定时器进行定时操作，实现定时关机、定时调整挡位等功能。集成矩阵按键，通过按钮实现系统功能的手动控制，包括时间调整、挡位调整等。集成直流电机，通过PWM控制电机的启停和转速，实现油烟机挡位的调整。根据实时的油烟浓度数据，自动调整油烟机的挡位，提高处理效率。利用外部中断检测按钮的按下，实现快速响应用户的手动操作。通过计数器实现定时功能，并通过按钮调节计时时间。根据温度传感器的读数，自动调整油烟机的工作状态，提升工作效率。根据红外遥控器命令，实现油烟机工作状态的自动切换。通过采用多种传感器和外设，以及合理的算法设计，系统能够实时监测环境参数，自动调整油烟机的工作状态，提高油烟处理的效率，同时通过人机交互界面，方便用户对系统进行手动操作。

## 文件结构

```
ICCS/
│
├── Project/         			# 竞赛51工程文件
│   ├── Listings			
│   ├── Objects
│   ├── my_lib
│	│   ├── DCmotor				# 直流电机驱动程序
│	│   ├── Delay				# 延时函数
│	│   ├── DS18B20				# 温湿度传感器模块驱动
│	│   ├── DS1302				# 实时时钟模块驱动程序
│	│   ├── int					# 外部中断程序
│	│   ├── IR					# 红外遥控器驱动程序
│	│   ├── LCD1602				# LCD1602驱动程序
│	│   ├── LCD12864			# LCD12864驱动程序
│	│   ├── MatrixKey			# 矩阵键盘驱动程序
│	│   ├── OneWire				# DHT11模块驱动
│	│   ├── Timer				# 定时器模块
│	│   └── XPT2046				# AD转换驱动程序	
│   └── user
│
├── driver_51/                  # 存放各个模块51驱动程序
│   ├── AD_conversion                   # AD转换驱动程序
│   ├── DCmotor                         # 直流电机驱动程序
│   ├── delay                           # 延时函数
│   ├── DHT11                           # DHT11模块驱动
│   ├── Digital_tubes                   # 八段数码管模块驱动
│   ├── External_interrupt              # 外部中断程序
│   ├── Infrared_remote_control         # 红外遥控器驱动程序
│   ├── Lamps_and_independent_buttons   # led	
│   ├── LCD12864                        # LCD12864驱动程序
│   ├── Matrix_keyboard                 # 矩阵键盘驱动程序
│   ├── RF_module                       # 射频模块驱动程序
│   ├── RTC                             # 实时时钟模块驱动程序
│   ├── Stepper_motors                  # 步进电机驱动程序
│   ├── timer                           # 定时器模块
│   ├── ultrasonic                      # 超声波模块驱动程序
│   └── Weight_sensor                   # 重量传感器驱动程序
│
├── res/                         # 存放程序流程图
│   ├── DS1302.jpg
│   ├── SCH.jpg
│   ├── LCD12864_Matrix_keyboard.jpg
│   ├── RTC_DS18B20.jpg
│   └── AD_and_it_pwm_timer.jpg
│
├── 竞赛赛题/                     # 包含竞赛赛题与模块清单
│   ├── 2021年安徽省机器人大赛-单片机与嵌入式系统赛道模块清单.pdf
│   ├── 竞赛赛题.pdf
│   └── 举办“2021年安徽省机器人大赛-单片机与嵌入式系统竞赛”的通知.pdf
│
└── README.md                    # 本文档，提供有关功能汇总、电路原理图以及文件结构等信息
```

## 功能汇总

1. **环境监测：**
   - 通过XPT2046模块读取温度和油烟浓度传感器的模拟信号。
   - 使用`XPT2046_ReadAD`函数进行AD转换，获取温度和油烟浓度的数值。
2. **显示功能：**
   - 使用LCD12864显示屏，通过`LCD12864_ShowString`和`LCD12864_ShowNum`等函数，在屏幕上显示温度、油烟浓度以及系统的工作状态。
   - `Disp_Roll`函数实现了在LCD上滚动显示特定信息。
3. **时间管理：**
   - 使用DS1302时钟模块，通过`DS1302_Init`和`DS1302_ReadTime`函数读取当前时间，并在LCD上显示。
4. **红外遥控功能：**
   - 通过`IR_Init`函数初始化红外遥控模块，通过`IR_GetDataFlag`和`IR_GetCommand`等函数检测和获取红外遥控信号。
   - 根据接收到的红外命令，控制油烟机的状态，如开关、挡位调节等。
5. **定时器控制：**
   - 使用定时器进行定时控制，例如通过`Timer1Init`函数初始化定时器1，实现定时操作。
   - 在定时器中，执行相关操作，如改变挡位、显示刷新等。
6. **矩阵键盘输入控制：**
   - 通过`MatrixKey`函数实现矩阵按键的输入检测，根据按键的不同操作进行相关功能的调用。控制油烟机中的电机，通过PWM调节电机的转速，实现不同挡位的风扇转速。通过按键进行时间的手动调整，增强了系统的可操作性。
7. **电机控制：**
   - 使用`DCmotorstart`函数控制电机的启动和停止。
   - 根据不同的挡位设置，通过PWM调节电机的转速。
8. **自动挡位控制：**
   - 通过`PWM_zkb`变量的值来控制电机的转速，根据油烟浓度来自动调节挡位。
   - 实现了自动挡位的功能，当油烟浓度超过一定阈值时，自动调整为更高的挡位。
9. **外部中断：**
   - 使用`Int0Init`和`Int1Init`函数初始化外部中断，通过外部中断实现按钮按下的检测和处理，用于调整时间等功能。
10. **计数器显示与调节：**
    - 通过`count`变量进行计数，并在LCD上显示。按键操作可以增加或减少计数值。
11. **油烟自动控制：**
    - 根据油烟浓度，通过PWM控制电机的转速，实现油烟自动控制。
12. **自动切换工作状态：**
    - 根据红外遥控器的命令，自动切换油烟机的工作状态，包括开关、挡位调整等。  

## 电路原理图

<div align=center><img  src ="https://github.com/zihaonian/ICCS-2022-A/blob/main/res/SCH.jpg"/></div>

## 程序流程图

### ADC转换 定时器 PWM控制

<div align=center><img  src ="https://github.com/zihaonian/ICCS-2022-A/blob/main/res/AD_and_it_pwm_timer.jpg"/></div>

### RTC实时时钟

<div align=center><img  src ="https://github.com/zihaonian/ICCS-2022-A/blob/main/res/DS1302.jpg"/></div>

### LCD12864 矩阵键盘

<div align=center><img  src ="https://github.com/zihaonian/ICCS-2022-A/blob/main/res/LCD12864_Matrix_keyboard.jpg"/></div>

### 温湿度传感器

<div align=center><img  src ="https://github.com/zihaonian/ICCS-2022-A/blob/main/res/RTC_DS18B20.jpg"/></div>

