from urllib import response
import requests
from flask import Flask, jsonify, request
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
        
        meal_1 = meal_1.replace('<br/>', '\n')

        meal_1 = re.sub(r'\([^)]*\)', '', meal_1)
    except:
        meal_1 = "불러올 데이터가 없습니다"

    if int(MEAL) == 2:
        MEAL_MENU = ' 중식 메뉴'
    elif int(MEAL) == 3:
        MEAL_MENU = ' 석식 메뉴'

    try:
        body = json_ob['mealServiceDietInfo'][1]['row']
        for i in range(len(body)):
            meal_2 = body[i]['CAL_INFO']
    except:
        meal_1 = "불러올 데이터가 없습니다"
    
    if int(PLUS_DATE) == 0:
        meal_date = datetime.today()
        meal_date = meal_date.strftime("%Y-%m-%d")
        day_of_week = datetime.today().weekday()
        try:
            meal_final = (meal_date + Days[day_of_week % 7] + MEAL_MENU + "\n\n" + meal_1 + "\n\n(" + meal_2 + ")")
        except:
            meal_final = "불러올 데이터가 없습니다"
            
    elif int(PLUS_DATE) == 1:
        meal_date = datetime.today() + timedelta(1)
        meal_date = meal_date.strftime("%Y-%m-%d")
        day_of_week = datetime.today().weekday()
        try:
            meal_final = (meal_date + Days[(day_of_week + 1) % 7] + MEAL_MENU + "\n\n" + meal_1 + "\n\n(" + meal_2 + ")")
        except:
            meal_final = "불러올 데이터가 없습니다"
    
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

@application.route("/meal/test", methods=["POST"])
def meal_test():
    body = request.get_json()
    print(body)
    params_df = body['action']['detailParams']
    print(type(params_df))
    date_request = json.loads(params_df['date'])['origin']

    print(date_request, type(date_request))
    
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

schedule.every().day.at("00:00").do(meal_function)
