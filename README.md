
# Power Window Control System with RTOS

This project is about controlling a power window of a car using freeRTOS. The project includes functionalities like the driver able to control the passenger window, a driver lock function to lock the passenger window controls, auto up and down when the button is pressed on time otherwise it will be manual, and jam function to clear if an obstacle got stuck while the window is in the auto up function.
  
## Components


- Tiva C
- Pushbuttons x8
- L298 Module Red Board (Dual H-bridge motor driver using L298N)
- Simple DC motor
- USB to TTL

## PIN Table

| PIN             | Functionality                                                                |
| ----------------- | ------------------------------------------------------------------ |
| GPIO A2 | Window Limit Up |
| GPIO A3 | Window Limit Down |
| GPIO B0 | Jam Functionality |
| GPIO B1 | Lock Passenger Window Controls |
| GPIO C4 | Driver Control of Passenger Window Up |
| GPIO C5 | Driver Control of Passenger Window Down |
| GPIO C6 | Passenger Window Up  |
| GPIO C7 | Passenger Window Down |
| GPIO E2 | Motor A Movement Control Clockwise |
| GPIO E3 | Motor A Movement Control Counterclockwise |

## Circuit Diagram


![Circuit Design_bb](https://github.com/Sasa-Indeed/RTOS_Project_Power_Window_Control_System/assets/108436896/039740fe-1f19-494a-bbc4-d99715f59042)

