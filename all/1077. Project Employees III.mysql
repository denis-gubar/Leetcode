# Write your MySQL query statement below
SELECT project_id, employee_id
  FROM
(SELECT Project.project_id,
       Employee.employee_id,
       Employee.experience_years,
       MAX(Employee.experience_years) OVER (PARTITION BY Project.project_id) max_experience_years
  FROM Project INNER JOIN Employee
 USING (employee_id)) data
 WHERE experience_years = max_experience_years