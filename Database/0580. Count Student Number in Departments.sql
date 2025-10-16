# Write your MySQL query statement below
SELECT department.dept_name, COUNT(student.student_id) student_number
  FROM department LEFT JOIN student
 USING (dept_id)
 GROUP BY department.dept_id, department.dept_name
ORDER BY 2 DESC, 1