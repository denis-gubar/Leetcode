# Write your MySQL query statement below
SELECT Id, 
       Month,
       Salary
  FROM       
(SELECT Id, 
       Month, 
       MAX(Month) OVER (PARTITION BY Id) Max_Month,
       COALESCE(LAG(Salary, 2) OVER (PARTITION BY Id ORDER BY Month), 0) + 
       COALESCE(LAG(Salary) OVER (PARTITION BY Id ORDER BY Month), 0) + 
       Salary Salary
  FROM Employee) data
 WHERE Month < Max_Month
ORDER BY 1, 2 DESC