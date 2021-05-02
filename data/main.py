from dbmain import newConnection
from dbmain import newTable
def openFile(filenames):
    fobj={}
    try:
        for filename in filenames:
            fobj[filename] = open("../output/"+filename+".txt")
        return fobj
    except:
        print("can't open file")
        
def closeFile(fobj,filenames):
    try:
        for filename in filenames:
            fobj[filename].close()
    except:
        print("can't close file")

def insertValues(conn,fileobjs,filenames):
    # for filename in filenames:
    #     listOfString = fileobjs[filename].read().splitlines()
    #     for var in listOfString:
    #         token = var.split(" ")
    #         print(token)
    #         conn.insertFourValues(token,valueName)
    conn.insertFourValues()
def checkTableExist(conn,tableNames):
    for tablename in tableNames:
        if conn.checkTableExist(tablename)==False:
            s = newTable(tablename,conn,valueType)
            s.createTable()
def insertToDB(p,fileobjs,tableNames):
    for tablename in tableNames:
        # print(tablename)
        s = newTable(tablename,p,valueType)
        # insertValues(s,fileobjs,filenames)
        listOfString = fileobjs[tablename].read().splitlines()
        for var in listOfString:
            token = var.split(" ")
            s.insertFourValues(token,valueName)


c = newConnection()
valueName = ["sortingtype","length","datatype","time"]
valueType = f"(id serial PRIMARY KEY, {valueName[0]} VARCHAR(50), {valueName[1]} INTEGER, {valueName[2]} VARCHAR(50), {valueName[3]} float(6))"
# s = newTable("tablesort1",c,valueType)
# s.createTable()
# filenames = ["../output/QuickSortResult.txt","../output/MergeSortResult.txt","../output/HeapSortResult.txt","../output/RadixSortResult.txt"]
tableNames = ["QuickSortResult","MergeSortResult","HeapSortResult", "RadixSortResult"]
fobj = openFile(tableNames)
# insertValues(s,fobj,filenames)
checkTableExist(c,tableNames)
insertToDB(c,fobj,tableNames)
closeFile(fobj,tableNames)
c.closeConnection()
