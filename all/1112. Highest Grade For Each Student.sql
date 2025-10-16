# Write your MySQL query statement below
SELECT student_id, 
       course_id,
       grade
  FROM
(SELECT student_id, 
       course_id,
       grade,
       RANK() OVER (PARTITION BY student_id ORDER BY grade desc, course_id) is_first_grade
  FROM Enrollments) Data
 WHERE is_first_grade = 1