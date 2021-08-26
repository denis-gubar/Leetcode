# Write your MySQL query statement below
SELECT Department.Name AS Department,
       Employee.Name   AS Employee,
       Employee.Salary
  FROM Employee
 INNER JOIN Department
    ON Employee.DepartmentId = Department.Id
 WHERE (Employee.DepartmentID, Employee.Salary) IN
       (SELECT Department.Id, MAX(Employee.Salary) AS Max_Salary
          FROM Employee
         INNER JOIN Department
            ON Employee.DepartmentId = Department.Id
         GROUP BY Department.Id);