import modi
import time

bundle = modi.MODI()

motor_1 = bundle.motors[0] #모터
motor_2 = bundle.motors[1]
speaker = bundle.speakers[0] #스피커
dial_1 = bundle.dials[0] #다이얼
dial_2 = bundle.dials[1]
button = bundle.buttons[0] #버튼
ir_1 = bundle.irs[0] #IR센서
ir_2 = bundle.irs[1] 

def car():
    while True:
        if ir_1.proximity > 50 or ir_2.proximity > 50:
            speaker.tune = 2000, 100
            motor_1.speed = 0, 0
            motor_2.speed = 0, 0
        elif ir_1.proximity <= 50 or ir_2.proximity <= 50:
            if 20 <= ir_1.proximity < 50 or 20 <= ir_2.proximity < 50:
                speaker.tune = 2000, 50
            elif ir_1.proximity < 20 or ir_2.proximity < 20:
                speaker.tune = 2000, 0
            if dial_1.degree > 10:
                if button.toggled == True: ## 앞으로
                    if dial_2.degree < 33: # 좌회전
                        motor_1.speed = dial_1.degree, dial_1.degree
                        motor_2.speed = dial_1.degree, dial_1.degree
                    elif 66 >= dial_2.degree and dial_2.degree >= 33: # 직진
                        motor_1.speed = dial_1.degree, -dial_1.degree
                        motor_2.speed = dial_1.degree, -dial_1.degree
                    elif dial_2.degree > 66: # 우회전
                        motor_1.speed = -dial_1.degree, -dial_1.degree
                        motor_2.speed = -dial_1.degree, -dial_1.degree
                elif button.toggled == False: ## 뒤로
                    motor_1.speed = -dial_1.degree, dial_1.degree
                    motor_2.speed = -dial_1.degree, dial_1.degree
            elif dial_1.degree < 10:
                motor_1.speed = 0, 0
                motor_2.speed = 0, 0

car()
