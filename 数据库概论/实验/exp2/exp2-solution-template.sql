-- 姓名：陈南曈
-- 学号：191220008
-- 提交前请确保本次实验独立完成，若有参考请注明并致谢。

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q1.1
DROP PROCEDURE IF EXISTS productOrder;
delimiter //
CREATE PROCEDURE productOrder(IN product_name VARCHAR(40))
	BEGIN
		SELECT Customer.customerNo, Customer.customerName, OrderMaster.orderNo, OrderDetail.quantity, OrderDetail.quantity*OrderDetail.price AS orderSum
        FROM Customer, Product, OrderMaster, OrderDetail
        WHERE Product.productName=product_name AND
			  Product.productNo=OrderDetail.productNo AND
              Customer.customerNo=OrderMaster.customerNo AND
              OrderMaster.orderNo=OrderDetail.orderNo
		ORDER BY orderSum DESC;
    END //
delimiter ;

CALL productOrder("32M DRAM");

-- END Q1.1

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q1.2
DROP PROCEDURE IF EXISTS earlyEmployee;
delimiter //
CREATE PROCEDURE earlyEmployee(IN employee_no CHAR(8))
	BEGIN
		SELECT em1.employeeNo, em1.employeeName, em1.gender, em1.hireDate, em1.department
        FROM Employee em1, Employee em2
        WHERE em2.employeeNo=employee_no AND
              em1.hireDate<em2.hireDate AND
              em1.department=em2.department;
    END //
delimiter ;

CALL earlyEmployee("E2008005");

-- END Q1.2

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q2.1
SET GLOBAL log_bin_trust_function_creators = 1;
DROP FUNCTION IF EXISTS averagePrice;
delimiter //
CREATE FUNCTION averagePrice(product_name VARCHAR(40))
	RETURNS NUMERIC(7, 2)
    BEGIN
    DECLARE average_price NUMERIC(7, 2);
		SELECT AVG(OrderDetail.price) INTO average_price
        FROM Product, OrderDetail
        WHERE Product.productName=product_name AND
              Product.productNo=OrderDetail.productNo;
    RETURN average_price;
    END //
delimiter ;

SELECT Product.productName, averagePrice(Product.productName) AS averagePrice
FROM Product;

-- END Q2.1

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q2.2
SET GLOBAL log_bin_trust_function_creators = 1;
DROP FUNCTION IF EXISTS quantitySum;
delimiter //
CREATE FUNCTION quantitySum(product_no VARCHAR(9))
	RETURNS INT
    BEGIN
    DECLARE quantity_sum INT;
		SELECT SUM(OrderDetail.quantity) INTO quantity_sum
        FROM OrderDetail
        WHERE OrderDetail.productNo=product_no;
    RETURN quantity_sum;
    END //
delimiter ;

SELECT DISTINCT Product.productNo, Product.productName, quantitySum(Product.productNo) AS quantitySum
FROM Product, OrderDetail
WHERE quantitySum(Product.productNo)>4 AND
      Product.productNo=OrderDetail.productNo;
      
-- END Q2.2

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q3.1
DROP TRIGGER IF EXISTS insertProduct;
delimiter //
CREATE TRIGGER insertProduct BEFORE INSERT ON Product
FOR EACH ROW
BEGIN
	IF NEW.productPrice > 1000 THEN
		SET NEW.productPrice = 1000;
	END IF;
END //
delimiter ;

INSERT INTO Product VALUES('P20090001','鼠标','设备',200.00);
INSERT INTO Product VALUES('P20090002','耳机','设备',2000.00);
SELECT *
FROM Product;

-- END Q3.1

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q3.2
DROP TRIGGER IF EXISTS insertOrder;
delimiter //
CREATE TRIGGER insertOrder AFTER INSERT ON OrderMaster
FOR EACH ROW
BEGIN
	UPDATE Employee
    SET Employee.salary= Employee.salary*1.05
		WHERE Employee.employeeNo=NEW.employeeNo;
	UPDATE Employee
	SET Employee.salary = Employee.salary*1.03
		WHERE Employee.employeeNo=NEW.employeeNo AND
			Employee.hireDate < '19920101';
END //
delimiter ;

SELECT Employee.employeeNo, Employee.salary AS oldSalary
FROM Employee
WHERE Employee.employeeNo='E2005003' OR Employee.employeeNo='E2005004';
INSERT OrderMaster VALUES('200812080001','C20080001','E2005003','20080717',0.00,'I000000011');
INSERT OrderMaster VALUES('200812080002','C20050002','E2005004','20080816',0.00,'I000000012');
SELECT Employee.employeeNo, Employee.salary AS newSalary
FROM Employee
WHERE Employee.employeeNo='E2005003' OR Employee.employeeNo='E2005004';

-- END Q3.2

