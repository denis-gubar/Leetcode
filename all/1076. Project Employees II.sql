# Write your MySQL query statement below
SELECT project_id
  FROM
(SELECT project_id, MAX(cnt) OVER () as max_cnt, cnt
  FROM 
(SELECT Project.project_id,
       COUNT(Employee.employee_id) cnt
  FROM Project INNER JOIN Employee
 USING (employee_id)
GROUP BY Project.project_id) data) data
 WHERE cnt = max_cnt