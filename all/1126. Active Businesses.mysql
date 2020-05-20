# Write your MySQL query statement below
SELECT business_id
  FROM
(SELECT business_id, 
       event_type,
       occurences,
       AVG(occurences) OVER (PARTITION BY event_type) avg_occurences
  FROM Events) data
 WHERE occurences > avg_occurences
 GROUP BY business_id
HAVING COUNT(*) > 1