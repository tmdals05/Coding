from urllib import response
import requests
from flask import Flask, jsonify
import sys
from datetime import datetime, timedelta
import json
import re
import schedule

application = Flask(__name__)

Days = ['(월)', '(화)', '(수)', '(목)', '(금)', '(토)', '(일)']

def meal_function(SCHOOL_CODE, MEAL, PLUS_DATE):
    API_KEY = '02d070cf271a46259611f05b0b03e9e6'
    FAKE_DATE = '20220425'
    REAL_DATE = datetime.today().strftime('%Y%m%d')

    DATE = int(REAL_DATE) + int(PLUS_DATE)

    url = 'https://open.neis.go.kr/hub/mealServiceDietInfo'
    queryParams = '?' + \
                'KEY=' + API_KEY + \
                '&Type='+ 'json' + \
                '&pIndex='+ '1' + \
                '&pSize='+ '10' + \
                '&ATPT_OFCDC_SC_CODE='+ 'N10' + \
                '&SD_SCHUL_CODE='+ SCHOOL_CODE + \
                '&MMEAL_SC_CODE='+ MEAL + \
                '&MLSV_YMD='+ str(DATE)

    response = requests.get(url + queryParams)
    contents = response.text

    json_ob = json.loads(contents) 

    try:
        body = json_ob['mealServiceDietInfo'][1]['row']
        for i in range(len(body)):
            meal_1 = body[i]['DDISH_NM']
        
        meal_2 = meal_1.replace('<br/>', '\n\n')

        meal_3 = re.sub(r'\([^)]*\)', '', meal_2)
    except:
        meal_3 = "불러올 데이터가 없습니다"


    if int(PLUS_DATE) == 0:
        meal_date = datetime.today()
        meal_date = meal_date.strftime("%Y-%m-%d")
        day_of_week = datetime.today().weekday()
        meal_final = (meal_date + Days[day_of_week] + " 중식 메뉴\n\n" + meal_3)

    elif int(PLUS_DATE) == 1:
        meal_date = datetime.today() + timedelta(1)
        meal_date = meal_date.strftime("%Y-%m-%d")
        day_of_week = datetime.today().weekday()
        meal_final = (meal_date + Days[day_of_week + 1] + " 석식 메뉴\n\n" + meal_3)
    
    return meal_final

@application.route("/lunch/today", methods=["POST"])
def lunch_today_function():
    response = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "simpleText": {
                        "text": (meal_function('8140387', '2', '0'))
                    }
                }
            ]
        }
    }
    return jsonify(response)

@application.route("/dinner/today", methods=["POST"])
def dinner_today_function():
    response = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "simpleText": {
                        "text": (meal_function('8140387', '3', '0'))
                    }
                }
            ]
        }
    }
    return jsonify(response)

@application.route("/lunch/tomorrow", methods=["POST"])
def lunch_tomorrow_function():
    response = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "simpleText": {
                        "text": (meal_function('8140387', '2', '1'))
                    }
                }
            ]
        }
    }
    return jsonify(response)

@application.route("/dinner/tomorrow", methods=["POST"])
def dinner_tomorrow_function():
    response = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "simpleText": {
                        "text": (meal_function('8140387', '3', '1'))
                    }
                }
            ]
        }
    }
    return jsonify(response)

@application.route("/lunch/cheonan", methods=["POST"])
def cheonan_lunch_today_function():
    response = {
        "version": "2.0",
        "template": {
            "outputs": [
                {
                    "simpleText": {
                        "text": (meal_function('8140104', '2', '0'))
                    }
                }
            ]
        }
    }
    return jsonify(response)


if __name__ == "__main__":
    application.run(host='0.0.0.0', port=int(sys.argv[1]), debug=True)

schedule.every().day.at("01:00").do(meal_function)