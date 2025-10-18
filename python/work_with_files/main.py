from defs import writeToFile
from defs import findAllRoles
from defs import numerateReplicasAndAddReplicasToRoles

def main():
    file = open('python/work_with_files/roles.txt','r')
    outFile = open('python/work_with_files/out.txt','w')
    
    lines = file.readlines()[1:]
    
    roles, lastLine = findAllRoles(lines)
    
    replicas = numerateReplicasAndAddReplicasToRoles(lines, lastLine, roles)

    writeToFile(outFile,roles,replicas)

    outFile.close()
    file.close()

if __name__=='__main__':
    main()