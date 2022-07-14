import modi
import time
from multiprocessing import Process

bundle = modi.MODI()

motor_1 = bundle.motors[0] #모터
motor_2 = bundle.motors[1]
speaker = bundle.speakers[0] #스피커
dial_1 = bundle.dials[0] #다이얼
dial_2 = bundle.dials[1]
button = bundle.buttons[0] #버튼
ir_1 = bundle.irs[0] #IR센서
ir_2 = bundle.irs[1] 
ir_3 = bundle.irs[2]
led = bundle.leds[0] #led

def car():
    while True:
        if ir_1.proximity > 70:
            speaker.tune = 2000, 100
            motor_1.speed = 0, 0
            motor_2.speed = 0, 0
        elif  50 < ir_1.proximity < 70:
            if ir_1.proximity < 70:
                speaker.tune = 2000, 50
            elif ir_1.proximity < 50:
                speaker.tune = 2000, 0
            if dial_1.degree > 0:
                if button.toggled == True:
                    if dial_2.degree < 50:
                        motor_1.speed = dial_1, -dial_1
                        motor_2.speed = dial_1, -dial_1
                elif button.toggled == False:
                    if dial_2.degree > 50:
                        motor_1.speed = -dial_1, dial_1
                        motor_2.speed = -dial_1, dial_1
            elif dial_1.degree == 0:
                motor_1.speed = 0, 0
                motor_2.speed = 0, 0

def gate():
    led.rgb = 100, 0, 0
    while True:
        count = 0
        while ir_3.proximity > 50 and count < 3:
            time.Sleep(1)
            count += 1
        if count == 3:
            motor_2.degree = 90, 0
            led.rgb = 0, 100, 0

p_car = Process(target=car)
p_car.start()


        

        
