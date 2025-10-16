# Write your MySQL query statement below
SELECT Students.student_id,
       Students.student_name, 
       Subjects.subject_name,
       COUNT(Examinations.student_id) attended_exams
  FROM (Students CROSS JOIN Subjects) LEFT JOIN Examinations
    ON Students.student_id = Examinations.student_id 
   AND Subjects.subject_name = Examinations.subject_name
GROUP BY Students.student_id, Students.student_name, Subjects.subject_name
ORDER BY Students.student_id, Students.student_name