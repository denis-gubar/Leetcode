# Write your MySQL query statement below
SELECT DISTINCT pay_month, 
       department_id,
       CASE
         WHEN department_avg_amount = company_avg_amount THEN 'same'
         WHEN department_avg_amount > company_avg_amount THEN 'higher'
         WHEN department_avg_amount < company_avg_amount THEN 'lower'
       END comparison
  FROM       
(SELECT CAST(pay_date as CHAR(7)) pay_month, department_id,
  AVG(amount) OVER (PARTITION BY department_id, CAST(pay_date as CHAR(7))) department_avg_amount,
  AVG(amount) OVER (PARTITION BY CAST(pay_date as CHAR(7))) company_avg_amount
  FROM salary INNER JOIN employee
 USING (employee_id)) data