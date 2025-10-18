import re

def searchFirstLetter(string):
    regular = r'[A-Za-zА-Яа-я()]'
    try:
        return re.search(regular,string).span()[0]
    except: return 0


def findAllRoles(lines):
    try:
        roles = dict()

        lenght = len(lines)
        lastLine = 0
        for i in range(lenght):
            if 'textLines' in lines[i]:
                break
            roles[lines[i][:-1]] = ''
            lastLine = i+1
        print('Все роли успешно найдены')
        return roles, lastLine
    except Exception as e: print(f'Ошибка при поиске ролей: {e}')


def numerateReplicasAndAddReplicasToRoles(lines, lastLine, roles):
    try:
        replicas = dict()
        lenght = len(lines)
        cnt = 0
        for x in range(lastLine+1,lenght):
            if lines[x][0]!=' ':
                cnt+=1
                line = lines[x].split(':')
                role = line[0]
                lineWithOutRole = line[1]
                replicas[cnt] = lineWithOutRole
                roles[role] += f'{cnt};'
            else: replicas[cnt] = replicas[cnt] + lines[x]
        print('Реплики успешно пронумерованы, а также занесены в соответсвующие роли')
        return replicas
    except Exception as e: print(f'Ошибка при нумеровании реплик или занесении их в соответсвующие роли: {e}')


def writeToFile(file,roles,replicas):
    try:
        for Role in roles.keys():
            numbersOfRoleReplicas = roles[Role].split(';')[:-1]
            file.write(f'{Role}:\n')
            for numberOfRoleReplica in numbersOfRoleReplicas:
                roleReplica=replicas[int(numberOfRoleReplica)]
                formatedRoleReplica = roleReplica[searchFirstLetter(roleReplica):]
                file.write(f'{numberOfRoleReplica})  {formatedRoleReplica}\n')
        print("Файл успешно записан")
    except: print("Ошибка при записи файла")
