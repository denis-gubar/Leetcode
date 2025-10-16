# Write your MySQL query statement below
SELECT Department.Name AS Department,
       Employee.Name   AS Employee,
       Employee.Salary
  FROM (SELECT Data.DepartmentId, MIN(Salary) Min_Salary
          FROM (SELECT Data.Salary, Data.DepartmentId
                  FROM (SELECT DISTINCT Salary, DepartmentId FROM Employee) AS Data
                 INNER JOIN (SELECT DISTINCT Salary, DepartmentId
                              FROM Employee) AS Other
                    ON Data.DepartmentId = Other.DepartmentId
                   AND Data.Salary <= Other.Salary
                 GROUP BY Data.Salary, Data.DepartmentId
                HAVING COUNT(*) <= 3) AS Data
         GROUP BY Data.DepartmentId) AS Data
 INNER JOIN Employee
    ON Data.DepartmentId = Employee.DepartmentId
   AND Data.Min_Salary <= Employee.Salary
 INNER JOIN Department
    ON Data.DepartmentId = Department.Id;