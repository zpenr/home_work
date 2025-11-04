import requests
from config import api_key
from cities import cities
import weather_data
def main():
    city = input("Введите название город: ").lower().strip()

    if city in cities.keys():
        responce = requests.get(f'https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/{cities[city]}?unitGroup=metric&include=days&key={api_key}&lang=ru')
        data = responce.json()['days'][0]
        weather_data.output_weather_general_inforation(data)

    else: print("К сожалению мы ничего не знаем про ващ город. Возможно вы неправильно ввели город")

if __name__ == "__main__":
    main()
