import modi
import time

bundle = modi.MODI()
 
motor_3 = bundle.motors[0]
ir_3 = bundle.irs[0]
ir_4 = bundle.irs[1]
led = bundle.leds[0] #led

def gate():
    while True:
        led.rgb = 100, 0, 0
        motor_3.degree = 1, 0
        count = 0
        while ir_3.proximity > 10 and count < 3:
            time.sleep(1)
            count += 1
        if count == 3:
            motor_3.degree = 29, 0
            led.rgb = 0, 100, 0
            while True:
                if ir_4.proximity > 10:
                    break

gate()
