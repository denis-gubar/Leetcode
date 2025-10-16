# Write your MySQL query statement below
SELECT student_id, student_name
  FROM Student
 WHERE student_id NOT IN 
(SELECT student_id
  FROM
(SELECT Student.student_id, 
       Student.student_name,
       Exam.score,
       MAX(Exam.score) OVER (PARTITION BY Exam.exam_id) max_score,
       MIN(Exam.score) OVER (PARTITION BY Exam.exam_id) min_score
  FROM Exam INNER JOIN Student
 USING (student_id)) data
 WHERE score = max_score OR score = min_score) AND
 student_id IN (SELECT DISTINCT student_id from Exam)