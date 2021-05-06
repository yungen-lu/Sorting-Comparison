from dbmain import new_connection
from dbmain import new_table
def open_file(filenames):
    fobj={}
    try:
        for filename in filenames:
            fobj[filename] = open("../output/"+filename+".txt")
        return fobj
    except:
        print("can't open file")
        
def close_file(fobj,filenames):
    try:
        for filename in filenames:
            fobj[filename].close()
    except:
        print("can't close file")


c = new_connection()
valueName = ["sortingtype","length","datatype","time"]
valueType = f"(id serial PRIMARY KEY, {valueName[0]} VARCHAR(50), {valueName[1]} INTEGER, {valueName[2]} VARCHAR(50), {valueName[3]} float(6))"
file = open("../output/Result.txt")
if c.check_table_exist("Result") == False:
    s = new_table("Result",c,valueType)
    s.create_table()
else:
    s = new_table("Result",c,valueType)
listOfString = file.read().splitlines()
for var in listOfString:
    token = var.split(" ")
    s.insert_four_values(token,valueName)
file.close()
c.close_connection()
