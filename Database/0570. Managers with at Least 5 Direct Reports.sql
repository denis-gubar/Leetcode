# Write your MySQL query statement below
SELECT Managers.Name
  FROM Employee Managers INNER JOIN Employee Subordinates
    ON Managers.Id = Subordinates.ManagerId
 GROUP BY Managers.Id, Managers.Name
HAVING COUNT(*) >= 5
  