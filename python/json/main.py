import json
import re
def add_user_to_json(login, last_time_visit, len_of_visit_seconds, filename):
    data = read_all_users_from_json(filename=filename)
    file = open(filename,'w', encoding='utf-8')
    if f'{login}' not in data.keys():
        data[f'{login}'] = {'last_time_visit': last_time_visit, 'len_of_visit_seconds': len_of_visit_seconds}
        json.dump(data, file)
        file.close()
        print(f"user с login '{login}' успешно добывлен")
    else: print(f"user с login '{login}' уже существует")
    
def read_all_users_from_json(filename):
    file = open(filename,'r', encoding='utf-8')
    users = json.load(file)
    file.close()
    return users

def find_user_by_login(filename,login):
    users = read_all_users_from_json(filename)
    if f'{login}' in users.keys():
        return {f"{login}":users[f'{login}']}
    else: 
        print('user не найден')
        return 0

def print_in_format(json_string):
    if json_string == 0:
        return 0
    for login in json_string.keys():
        print(f'{login}')
        for key in json_string[login].keys():
            print(f"\t{key} : {json_string[login][key]}")
def validate_input_time(time_string):
    validator = r'[0-2][0-9]:[0-5][0-9]'
    if re.match(validator,time_string):
        return 1
    else: return 0
def main(filename):
    print("""\nДля просмотра json введите 1
Для находения пользователя по логину введите 2
Для добавления пользоваетя введите 3
Для завершения редактирования введите 4\n""")
    key = input()
    if key == '1':
        print_in_format(read_all_users_from_json(filename))
    elif key == '2':
        login = input('Введите логин: ')
        print_in_format(find_user_by_login(filename=filename, login=login))
    elif key == '3':
        login = input('Введите логин: ')
        last_time_visit = input("Введите последнее время посещения в таком виде 'часы:минуты' : ")
        while not validate_input_time(last_time_visit):
            last_time_visit = input("Вы ввели время в неверном формате!!!\nВведите последнее время посещения в таком виде 'часы:минуты' : ")
        len_of_visit_seconds = input('Введите продолжительность последнего посещения в секундах : ')
        add_user_to_json(login=login, last_time_visit=last_time_visit, len_of_visit_seconds=len_of_visit_seconds,filename=filename)
    elif key == '4':
        return True
    else: 
        print("Вы ввели неверное значение ")
    return False

if "__main__"==__name__:
    filename = 'python/json/users.json'
    flag_close = False
    while not flag_close:
        flag_close = main(filename=filename)

    