#!/usr/bin/python3
import pymysql

# ______________________________________________________________________________________________________________________
# BEGIN Q4.1
db = pymysql.connect(host='localhost',
                     user='root',
                     passwd='123456',
                     database='OrderDB')
cursor = db.cursor()
sql = """
      SELECT Employee.employeeNo, Employee.employeeName, Employee.salary
      FROM Employee
      ORDER BY Employee.salary DESC
      LIMIT 0,21
      """
cursor.execute(sql)
result = cursor.fetchall()
for row in result:
    print(row)
db.close()

# END Q4.1

# ______________________________________________________________________________________________________________________
# BEGIN Q4.2
db = pymysql.connect(host='localhost',
                     user='root',
                     passwd='123456',
                     database='OrderDB')
cursor = db.cursor()
sql = """
      INSERT INTO Customer
      VALUES ('C20080002','泰康股份有限公司','010-5422685','天津市','220501')
      """
cursor.execute(sql)
db.commit()

sql = """
      SELECT *
      FROM Customer
      """
cursor.execute(sql)
result = cursor.fetchall()
for row in result:
    print(row)
db.close()

# END Q4.2

# ______________________________________________________________________________________________________________________
# BEGIN Q4.3
db = pymysql.connect(host='localhost',
                     user='root',
                     passwd='123456',
                     database='OrderDB')
cursor = db.cursor()
sql = """
      DELETE
      FROM Employee
      WHERE Employee.salary>5000
      """
cursor.execute(sql)
db.commit()

sql = """
      SELECT Employee.employeeNo, Employee.employeeName, Employee.salary
      FROM Employee
      """
cursor.execute(sql)
result = cursor.fetchall()
for row in result:
    print(row)
db.close()

# END Q4.3

# ______________________________________________________________________________________________________________________
# BEGIN Q4.4
db = pymysql.connect(host='localhost',
                     user='root',
                     passwd='123456',
                     database='OrderDB')
cursor = db.cursor()
sql = """
      UPDATE Product
      SET productPrice=productPrice*0.5
      WHERE productPrice>1000
      """
cursor.execute(sql)
db.commit()

sql = """
      SELECT *
      FROM Product
      """
cursor.execute(sql)
result = cursor.fetchall()
for row in result:
    print(row)
db.close()

# END Q4.4
