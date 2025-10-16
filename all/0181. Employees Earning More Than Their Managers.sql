# Write your MySQL query statement below
SELECT NAME AS Employee
  FROM Employee AS Data
 WHERE EXISTS (SELECT NULL FROM Employee AS Manager WHERE Manager.Id = Data.ManagerId AND  Manager.Salary < Data.Salary);
