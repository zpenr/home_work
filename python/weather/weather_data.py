def output_weather_general_inforation(data):
    max_temp = data['tempmax']
    min_temp = data['tempmin']
    temp = data['temp']
    windspeed = data['windspeed']
    sunrise_time = data['sunrise']
    sunset_time = data['sunset']
    conditions = data['conditions']
    print(f"""Общая информация 
    Максимальная температура за день: {max_temp}
    Минимальная температура за день: {min_temp}
    Средняя температура за день: {temp}
    Скорость ветра: {windspeed} м/с
    Восход: {sunrise_time}
    Закат: {sunset_time}
    Условия: {conditions}\n""")