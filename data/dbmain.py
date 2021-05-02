import psycopg2
import sys
from dotenv import load_dotenv
import os

class newConnection:
    def __init__(self):
        load_dotenv()
        host = os.environ.get("HOST")
        dbname = os.environ.get("POSTGRES_DB")
        user = os.environ.get("POSTGRES_USER")
        password = os.environ.get("POSTGRES_PASSWORD")
        sslmode = 'allow'
        self.conn_string = "host={0} user={1} dbname={2} password={3} sslmode={4}".format(host, user, dbname, password, sslmode)
    # def createConnection(self):
        try:
            conn = psycopg2.connect(self.conn_string)
            self.conn = conn
            self.cursor = conn.cursor()
            # return conn
        except Exception as e:
            print("Connection Failed")
            print(e)
            sys.exit('-1')

    def closeConnection(self):
        self.conn.commit()
        self.cursor.close()
        self.conn.close()
        print("Connection Closed")

    def checkTableExist(self,tableName):
        self.cursor.execute(f"SELECT EXISTS (SELECT FROM information_schema.tables WHERE table_schema = 'public' AND table_name = '{tableName}');")
        re = self.cursor.fetchone()[0]
        if re == True:
            # print(f"{tableName} table exists")
            return True
        elif re == False:
            print(f"{tableName} table does not exists")
            return False
        else: sys.exit()
class newTable(newConnection):
    def __init__(self,tableName,parentName,valueType):
        self.tableName = tableName
        self.conn = parentName.conn
        self.cursor = parentName.cursor
        self.valueType = valueType
        # self.examValueType
    def createTable(self):
        try:
            self.cursor.execute(f"CREATE TABLE \"{self.tableName}\" {self.valueType};")
            print(f"{self.tableName} table created")
        except (Exception, psycopg2.DatabaseError) as error:
            print(error)

    def checkColumnExist(self,columnName):
        self.cursor.execute(f"SELECT EXISTS (SELECT FROM information_schema.column WHERE table_schema = 'public' AND table_name = '{self.tableName}' AND column_name = '{columnName}');")
        re = self.cursor.fetchone()[0]
        if re == True:
            # print(f"{self.tableName} exist")
            return True
        elif re == False:
            print(f"{columnName} column does not exist")
            return False
        else: sys.exit()
    
    def checkRowExist(self,columnID,rowID):
        self.cursor.execute(f"SELECT EXISTS (SELECT FROM \"{self.tableName}\" WHERE {columnID} = '{rowID}');")
        re = self.cursor.fetchone()[0]
        if re == True:
            # print(f"{self.tableName} exist")
            return True
        elif re == False:
            print(f"{rowID} does not exist")
            return False
        else: sys.exit()

    # def insertTwoValues(self,values,valueName):
    #     try:
    #         self.cursor.execute(f"INSERT INTO \"{self.tableName}\" ({valueName[0]}, {valueName[1]}) VALUES (%s, %s);", (values[0],values[1]))
    #         print(f"{values} inserted")
    #     except (Exception, psycopg2.DatabaseError) as error:
    #         print(error)
    
    def insertFourValues(self,values,valueName):
        try:
            self.cursor.execute(f"INSERT INTO \"{self.tableName}\" ({valueName[0]}, {valueName[1]}, {valueName[2]}, {valueName[3]}) VALUES (%s, %s, %s, %s);", (values[0],values[1],values[2],values[3]))
            print(f"{values} inserted")
        except (Exception, psycopg2.DatabaseError) as error:
            print(error)

