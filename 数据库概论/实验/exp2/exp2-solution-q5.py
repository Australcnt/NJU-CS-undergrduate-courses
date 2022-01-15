#!/usr/bin/python3
import pymysql

# ______________________________________________________________________________________________________________________
# BEGIN Q5.1
department = '业务科'
db = pymysql.connect(host='localhost',
                     user='root',
                     passwd='123456',
                     database='OrderDB')
cursor = db.cursor()
sql = """
      UPDATE Employee
      SET salary=salary+200
      WHERE department=%s
      """
cursor.execute(sql, department)

sql = """
      SELECT Employee.employeeNo, Employee.employeeName, Employee.salary
      FROM Employee
      """
cursor.execute(sql)
result = cursor.fetchall()
for row in result:
    print(row)
db.close()

# END Q5.1

# ______________________________________________________________________________________________________________________
# BEGIN Q5.2
db = pymysql.connect(host='localhost',
                     user='root',
                     passwd='123456',
                     database='OrderDB')
cursor = db.cursor()
sql = """
      SELECT Customer.customerName, Customer.address, Customer.telephone
      FROM Customer
      """
cursor.execute(sql)
result = cursor.fetchall()
for row in result:
    print(row)
db.close()

# END Q5.2
