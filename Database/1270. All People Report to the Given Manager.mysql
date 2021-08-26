# Write your MySQL query statement below
WITH RECURSIVE Hierarchy AS
(SELECT employee_id, manager_id
  FROM Employees
 WHERE employee_id != 1 AND manager_id = 1
UNION ALL
SELECT Employees.employee_id, Employees.manager_id
  FROM Employees INNER JOIN Hierarchy
    ON Employees.manager_id = Hierarchy.employee_id
 WHERE Employees.employee_id != Employees.manager_id)
SELECT employee_id FROM Hierarchy 
 
