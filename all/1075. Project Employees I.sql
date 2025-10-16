# Write your MySQL query statement below
SELECT Project.project_id,
       ROUND(SUM(Employee.experience_years) / COUNT(Employee.employee_id), 2) average_years
  FROM Project INNER JOIN Employee
 USING (employee_id)
GROUP BY Project.project_id