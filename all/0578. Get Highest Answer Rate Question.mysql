# Write your MySQL query statement below
SELECT question_id survey_log
  FROM 
(SELECT question_id,
       ratio,
       max(ratio) over () max_ratio
  FROM
(SELECT survey_log.question_id,
       SUM(CASE
         WHEN survey_log.action = 'answer' THEN 1
         ELSE 0
       END) ratio
 FROM survey_log
GROUP BY survey_log.question_id) data) data
WHERE ratio = max_ratio