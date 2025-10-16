# Write your MySQL query statement below
SELECT company_id,
       employee_id,
       employee_name,
       ROUND(CASE
         WHEN max_salary < 1000 THEN salary
         WHEN max_salary BETWEEN 1000 and 10000 THEN salary * 0.76
         ELSE salary * 0.51
       END) salary
  FROM
(SELECT company_id,
       employee_id,
       employee_name,
       salary,
       MAX(salary) OVER (PARTITION BY company_id) max_salary
  FROM Salaries) data